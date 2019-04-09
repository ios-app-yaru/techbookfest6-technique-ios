= CI/CD
== 用語解説

  * CI (Continuous Integration) 継続的インテグレーション
  ** 例: PullRequestの作成時やmasterブランチ変更時に自動ビルドとテストを実行し、品質の安定を図る
  * CD (Continuous Delivery) 継続的デリバリー
  ** 例: masterブランチが変更されるたびに自動でビルドし、自動でテスターに配布する

== Bitrise

モバイルアプリケーション用のCI/CDサービス

  * Bitrise
  * https://www.bitrise.io/

サービス登録してワークフロー（githubからのclone、ビルド、テスト、デプロイ、Slack通知等）をポチポチと設定するだけでCI/CD環境が構築できる便利なサービス
フリー版だと、直列ビルドでビルド時間にMAX10分等の制限がついているので注意です。※この本が出版された後に変わる可能性があります。

//image[06-bitrise-pricing][Bitrise課金携帯]{
//}

初回登録時、次の作業が必要です。

  * アカウントの作成
  * アプリを登録する（アプリ名とか）
  * リポジトリを登録する (optional: Github連携)
  * ブランチを選択 (ex. master)

アプリの登録が終わったら、次は自動ビルド時に使う用の証明書をBitriseサービスに登録します。

  * アプリ > Workflow > Code Signingを開く
  * PROVISIONING PROFILEセクションに.mobileprovisionファイルをドラッグしてアップロード

//image[06/bitrise-provisioning-profile][Provisioning Profileのアップロード]{
//}

  * CODE SIGNING IDENTITYセクションに.p12ファイルをドラッグしてアップロード

//image[06/bitrise-codesigning][.p12ファイルのアップロード]{
//}

次に、workflowを作ります。指定したブランチが更新されたときにどのようなアクションを取るか設定していきます。
筆者の個人開発アプリでは次のようにしています。

//image[06/bitrise-workflow][Bitrise workflow]{
//}

後は、masterブランチを更新したときに作ったworkflowが動けば成功！
手動で動かす場合は、`Start/Schedule` ボタンを押してbranchを`master`にするとワークフローが走ります。

== Fastlane

iOS/Androidアプリ開発者向けのCI/CD用ライブラリ

  * Fastlane
  * https://github.com/fastlane/fastlane
  * https://docs.fastlane.tools/

スクリーンショットの作成、ProvisioningProfileの処理、アプリのデプロイ、リリース等の作業を自動化できます。

=== 導入

今回は、試しにTestflightへコマンド一発でデプロイできる仕組みを作ってみます。まずはプロジェクトにfastlaneを導入するため、次のコマンド郡を実行してください。

//emlist[]{
# xcode commandline toolの導入
xcode-select --install
# RubyGems を利用してのインストール
sudo gem install fastlane -NV
# プロジェクトへ移動
cd YOUR_XCODE_PROJECT
# fastlaneの導入
fastlane init
//}

自動でセットアップすることもできますが、今回はマニュアルでセットアップしていきます。

//emlist[]{
[✔] 🚀
[✔] Looking for iOS and Android projects in current directory...
[23:20:43]: Created new folder './fastlane'.
[23:20:43]: Detected an iOS/macOS project in the current directory: 'あなたのプロジェクト名.xcworkspace'
[23:20:43]: -----------------------------
[23:20:43]: --- Welcome to fastlane 🚀 ---
[23:20:43]: -----------------------------
[23:20:43]: fastlane can help you with all kinds of automation for your mobile app
[23:20:43]: We recommend automating one task first, and then gradually automating more over time
[23:20:43]: What would you like to use fastlane for?
1. 📸  Automate screenshots
2. 👩‍✈️  Automate beta distribution to TestFlight
3. 🚀  Automate App Store distribution
4. 🛠  Manual setup - manually setup your project to automate your tasks
?
//}

4（マニュアルセットアップ）を入力したあと、各種ファイルの自動生成とfastlaneのイロイロについての説明が色々出力されるので基本Enter連打で進めて下さい。完了すると、次のようなファイル群が生成されます。

  * fastlane/Appfile
  ** AppleIDやアプリのBundleIdentifierを定義
  * fastlane/Fastfile
  ** 自動化処理を記述
  ** 各種laneを定義
  *** lane -> １つ１つの自動化処理の名前のようなもの
  *** 自動デプロイするlane、自動スクショ撮るlane、自動テストするlane等いろいろあります。

試しに、自動でテストを走らせるlaneを定義してみます。その場合は、Fastfileを開き次のように編集します

//emlist[]{
default_platform(:ios)

platform :ios do
  desc "test"
  lane :test do
    run_tests # 実行する処理　actionと呼ばれている
  end
end
//}

その後、次のコマンドを入力すると自動でテストが走ります

//emlist[]{
fastlane test
//}

また、actionはもっとカスタマイズすることができます。

//emlist[]{
platform :ios do
  desc "test"
  lane :test do
    run_tests(
      devices: ["iPhone 6s", "iPad Air"],
      clean: true
    )
  end
end
//}

他にも、AppleStoreへの自動デプロイ、Testflightへの自動デプロイ等いくつかactionが用意されています。詳しくはドキュメントをご参照下さい。(https://docs.fastlane.tools/actions/)

最後に、筆者の個人開発アプリのFastfileの中身を一部ここで紹介します。参考になれば嬉しいです！

//emlist[]{
default_platform(:ios)

platform :ios do

  desc "Submit App to Fabric Beta"
  lane :beta do
    build_app(
      scheme: "Production-Debug",
      configuration: "Release-Adhoc",
      export_method: "ad-hoc"
    )
    crashlytics(
      api_token: "YOUR_TOKEN",
      build_secret: "YOUR_SECRET_KEY",
      groups: "development"
    )
    slack(
      slack_url: "https://hooks.slack.com/services/YOUR_SLACK_INCOMING_HOOK_URL",
      channel: "#notify",
      username: "fastlane"
    )
  end

  lane :release do
    build_app(
      scheme: "Production",
      configuration: "Release-AppStore",
      workspace: "YOUR_PROJECT_NAME.xcworkspace",
      export_method: "app-store",
      include_bitcode: true
    )
    upload_to_app_store
    slack(
      slack_url: "YOUR_SLACK_INCOMING_HOOK_URL",
      channel: "#notify",
      username: "fastlane"
    )
  end

end

//}
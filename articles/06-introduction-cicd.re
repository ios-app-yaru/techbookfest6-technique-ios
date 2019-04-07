= CI/CD
== Bitrise

モバイルアプリケーション用のCI/CDサービス

- Bitrise
- https://www.bitrise.io/

=== 用語解説

- CI (Continuous Integration) 継続的インテグレーション
  - 例: PullRequestの作成時やmasterブランチ変更時に自動ビルドとテストを実行し、品質の安定を図る
- CD (Continuous Delivery) 継続的デリバリー
  - 例: masterブランチが変更されるたびに自動でビルドし、自動でテスターに配布する

=== 使い方

※この本が出版された後に手順が変わる可能性があるので、大体の手続きだけ説明します

- アカウントの作成
- アプリを登録する（アプリ名とか）
- リポジトリを登録する (optional: Github連携)
- ブランチを選択 (ex. master)

アプリの登録が終わると、次は自動ビルド時に使う用の証明書をBitriseサービスに登録します。

- アプリ > Workflow > Code Signingを開く
- PROVISIONING PROFILEセクションに.mobileprovisionファイルをドラッグしてアップロード
- CODE SIGNING IDENTITYセクションに.p12ファイルをドラッグしてアップロード

その後、`Start/Schedule` ボタンを押してbranchを`master`にすると自動ビルドが走ります。
自動ビルド後にテストを走らせたいだとか、Slackに結果を送信したい・・・といったことをしたい場合は `Workflows`を開き、適当にポチポチと追加していくだけで実現できます。

== Fastlane

iOS/Androidアプリ開発者向けのCI/CD用ライブラリ

- Fastlane
- https://github.com/fastlane/fastlane
- https://docs.fastlane.tools/

スクリーンショットの作成、ProvisioningProfileの処理、アプリのデプロイ、リリース等の作業を自動化できます。

=== 導入

今回は、試しにTestflightへコマンド一発でデプロイできる仕組みを作ってみます。まずはプロジェクトにfastlaneを導入するため、次のコマンド郡を実行してください。

```
# xcode commandline toolの導入
xcode-select --install
# RubyGems を利用してのインストール
sudo gem install fastlane -NV
# プロジェクトへ移動
cd YOUR_XCODE_PROJECT
# fastlaneの導入
fastlane init
```

自動でセットアップすることもできますが、今回はマニュアルでセットアップしていきます。

```
ryo-takahashi@~/workspace/ios/MiruCall_Swift[introduce-fastlane]> fastlane init
[✔] 🚀
[✔] Looking for iOS and Android projects in current directory...
[23:20:43]: Created new folder './fastlane'.
[23:20:43]: Detected an iOS/macOS project in the current directory: 'MiruCall_Swift.xcworkspace'
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
```

4（マニュアルセットアップ）を入力したあと、各種ファイルの自動生成とfastlaneのイロイロについての説明が色々出力されるので基本Enter連打で進めて下さい。完了すると、次のようなファイル群が生成されます。

- fastlane/Appfile
  - AppleIDやアプリのBundleIdentifierを定義
- fastlane/Fastfile
  - 自動化処理を記述
  - 各種laneを定義
    - lane➔１つ１つの自動化処理の名前のようなもの
    - 自動デプロイするlane、自動スクショ撮るlane、自動テストするlane等

前提
- Apple Developer > IdentifiersでアプリのIDを登録している
- Apple DeveloperでアプリのProvisioning Profileを作成している

試しに、自動でテストを走らせるlaneを定義してみます。その場合は、Fastfileを開き次のように編集します

```
default_platform(:ios)

platform :ios do
  desc "test"
  lane :test do
    run_tests # 実行する処理、actionと呼ばれている
  end
end
```

その後、次のコマンドを入力すると自動でテストが走ります

```
fastlane test
```

また、actionはもっとカスタマイズすることができます。

```
platform :ios do
  desc "test"
  lane :test do
    run_tests(
      devices: ["iPhone 6s", "iPad Air"],
      clean: true
    )
  end
end
```

他にも、AppleStoreへの自動デプロイ、Testflightへの自動デプロイ等いくつかactionが用意されています。詳しくはドキュメントをご参照下さい。(https://docs.fastlane.tools/actions/)
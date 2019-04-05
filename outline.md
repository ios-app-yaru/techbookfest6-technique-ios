# 一歩先へ進みたいiOSアプリ開発初心者のための開発をもっと便利にするテクニック集
# はじめに

こんにちは、@k0uhashiです。本書を手にとって頂き、誠にありがとうございます。

## 対象読者

ひとことでいうと、「簡単なiOSアプリなら開発できるようになったけど、もっとできるようになるためにはどうすればいいんだろう？」と悩んでいる人

## 必須知識

本書では、基礎的なSwiftの扱いやXcodeの操作、UIKitの扱いなどは解説しません。なので、本書を読むにあたって以下の知識を蓄えている必要があります。

- プログラミングの基礎知識
  - 変数
  - 関数
  - クラス
  - if, for, switch等
- Swiftの言語仕様の基礎
  - クロージャ
  - optional
  - delegate等

## 推奨知識

本書を読むにあたって知っておくとより理解が進む概念について挙げていきます。

- ライブラリ
- フレームワーク
- ライブラリとフレームワークの違い
- SaaS, PaaS, mBaaS

## 想定環境

本書では、以下の環境をターゲットとしています。

- Xcode10.2 もしくは 10.1
- Swift5.0 もしくは 4.2

基本５で解説しますが、執筆時点で対応していないライブラリもあるので、一部4.2で動作させている部分があります。

## 本書に関するお問い合わせ

- twitter: https://twitter.com/k0uhashi

## サンプルリポジトリ

- WIP

## 免責事項

本書は有志によって作成されているもので、米Apple社とは一切関係がありません。
また、掲載されている内容は情報の提供のみを目的にしていて、本書を用いた開発・運用は必ず読者の責任と判断によって行ってください。
著者は本書の内容による開発、運用の結果によっての結果について、いかなる責任も負いません。

# iOSアプリ開発において読んでおくべきもの

本章では、これからのiOSアプリ開発において、読んでおくべきだと感じたリファレンスや書物、サイトを紹介していきます。

## Human Interface Guidelines

- Human Interface Guidelines (https://developer.apple.com/design/human-interface-guidelines/)
- 以下、HIG

AppleによるUI設計の原則を定めたガイドライン。なんかイマイチなUIだな〜、使い心地良くないな〜・・・と感じるのであれば、一度見てみましょう。感じていなくても、見ましょう！
例えば、次のようなことが書かれています。
- 2個くらい紹介する

## iOSアプリ開発ベストプラクティス

- iOS-factor (https://ios-factor.com/ja/)
- リポジトリ (https://github.com/ios-factor/ios-factor.com)

これまでのiOSアプリ開発プラクティスの歴史や現代のiOSアプリ開発の開発環境の設定やデプロイ、開発における考え方（すべてのユーザーが最新バージョンにアップデートすることを前提にしない...）など現代のiOSアプリ開発者にとってとても役に立つプラクティス集です。オープンソースプロジェクトで有志によって更新されています。

例えば、次のようなことが書かれています。

```
V. Prefer local over remote
できるだけバックエンドなしで動作するように iOS アプリをスマートに保つ

-- （中略)

さまざまな理由でできるだけ多くのビジネスロジックと計算をデバイス上で実行すべきです。

プライバシー：リモートサーバーにデータを送信しないようにする
スピード：サーバーへのデータ送信やレスポンス待ちには時間がかかり失敗するかもしれない（不安定な Wi-Fi など)
データ利用：ユーザーには毎月のデータ制限があることが多い
スケーリング：アプリが流行った場合は、バックエンドサービスをスケールアップする責任がある
バッテリ寿命：モバイルデータを使うとバッテリを浪費する
信頼性：まだ信頼性の低い LTE/3G 回線を持つ国がある
```

## Swift実践入門 ── 直感的な文法と安全性を兼ね備えた言語 (WEB+DB PRESS plus)

- 技術評論社より出版

Swiftとはなんぞや？というところから、言語仕様解説、実際の業務でどう使うか？まで解説していて、初心者〜上級者までこれ１冊でいけるといっても過言ではないくらい良い本です。必須。実際、著者（僕）もiOSアプリ開発に入門するときに一番最初に購入しました。

# Xcodeテクニック
## ショートカット

XcodeでiOSアプリを効率的に開発する上で習得必須な便利ショートカットをここで紹介していきます。

caps lock -> control
control -> command

### Build周り
- Command + B
  - ビルド
- Command + R
  - ビルド後にアプリを実行
- Command + Control + R
  - 直近でビルドした成果物を利用してアプリを実行
  - 開発中にアプリがクラッシュしたときや何らかの影響でアプリが落ちた時に、デバッガを有効にした状態で起動したい場合に便利！
- Command + U
  - テスト実行
- Command + Control + R
  - 直近でビルドした成果物を利用してテスト実行
- Command + . (ドット)
  - 実行中のビルドやアプリを終了
- Command + K
  - クリーン
- Command + \
  - ブレークポイントの追加や削除
- Command + Control + Y
  - ブレークポイントのところから再開

### 検索周り
- Command + F
  - エディタ内の検索
- Command + Option + F
  - エディタ内の置換
- Command + Shift + F
  - プロジェクト内の検索
- Command + Shift + Option + F
  - プロジェクト内の置換
- Command + Control + Y
  - ファイルの検索
- Command + Shift + O（オー）
  - プロジェクト内のファイル名やメソッドの検索
  - これを覚えるとでかい！

### コードエディタ周り
- Command + Shift + J
  - プロジェクトナビゲータで現在編集しているファイルの位置をフォーカスさせる
- Option + Click
  - 軽くリファレンスを表示

### シミュレータ
- Command + S
  - スクリーンショットの撮影
- Command + K
  - キーボードの表示、非表示の切り替え
- Command + Shift + H
  - ホーム画面に戻る

### Project Settings
- production schemaとproduction-debug schemaとDebug schemaを作成する方法について

# ライブラリ
## CocoaPods
Rubyで作られているiOS/MacOS向けのライブラリ管理ツール。オープンソースプロジェクトであり、GitHub上で有志によって開発されている (https://github.com/CocoaPods/CocoaPods) 
いちいちGitHubからライブラリをダウンロードして導入しなくても、これを使うことによって自動で依存を解決しつつ、ライブラリをプロジェクトに簡単に導入することができるようになる。

### 導入

前提として、PCにrubyがインストールされている必要がありますが、MacOSではデフォルトで導入されているので、そのインストールは省略します。

CocoaPodsをPCに導入するにはterminalを開いて、次のコマンドを実行

```
sudo gem install cocoapods
pod setup
```

その後、terminalでXcodeプロジェクトの階層へ移動し、次のコマンドを実行

```
pod init
```

これでライブラリ管理する準備は完了！あとは生成された `Podfile` ファイルにどのライブラリをインストールするか記述していきます。

例えば、PKHUD (https://github.com/pkluz/PKHUD) というライブラリを導入したい場合、Podfileを次のように編集します。

```
source 'https://github.com/CocoaPods/Specs.git'

target 'MiruCall_Swift' do
  use_frameworks!

  pod 'PKHUD'
end
```

その後、次のコマンドでライブラリの更新とインストールを行います。

```
pod update
```

このコマンドを打つと、インストールするライブラリのバージョンと、それをどこからとってくるか・・・等が`Podfile.lock` というファイルに記録されて出力されます。
`pod install` コマンドを実行すると、この `Podfile.lock`の中身を参照して、書かれているバージョンにあわせてライブラリを自動でインストールできます。

使い分けの例

- `pod install` 
  - 新たにチームメンバーが増えたときに環境を揃えられる
    - プロジェクトを `git clone` して `pod install`
- `pod update`
  - ライブラリのバージョンをアップデートしたい

## Carthage

前節で説明したものと同じようなライブラリ管理ツールとしてCarthage（カーセッジ、カルタゴ）があります。こちらはSwiftで作られていて、同じようにオープンソースプロジェクトとしてGitHubで公開されています。

CocoaPodsとの違いを大まかにすると、CocoaPodsでライブラリ管理をするより、Carthageでライブラリ管理をしたほうが**コンパイル時間が短縮できる**というメリットがあります。というのも、Carthageはライブラリをインストールするとそれを事前にビルドし、フレームワークを作成してくれるからです。

ただし、一部のライブラリは対応していなかったり、導入が少し難しいという点があります。

インストールや扱いについては変に噛み砕いて説明するより (https://github.com/Carthage/Carthage)の`README.md`のほうがわかりやすいためこちらをご参照下さい。

## R.swift

https://github.com/mac-cain13/R.swift
プロジェクトにインポートした画像やViewControllerのnib名を安全に取得できるようにするライブラリ

例えば、いま開発中のプロジェクト内で画像、ViewControllerを扱うときに次のような書き方をしている場合

```
let icon = UIImage(named: "settings-icon")
let font = UIFont(name: "San Francisco", size: 42)
let color = UIColor(named: "indictator highlight")
let viewController = CustomViewController(nibName: "CustomView", bundle: nil)
let string = String(format: NSLocalizedString("welcome.withName", comment: ""), locale: NSLocale.current, "Arthur Dent")
```

R.swiftを使うことで、次のようにタイプセーフに扱うことができるようになります。

```
let icon = R.image.settingsIcon()
let font = R.font.sanFrancisco(size: 42)
let color = R.color.indicatorHighlight()
let viewController = CustomViewController(nib: R.nib.customView)
let string = R.string.localizable.welcomeWithName("Arthur Dent")
```

ライブラリの導入に少し手順がありますが、導入するとタイプセーフにリソースを扱えるようになるので、typoのミスを極力減らせます！

## SwiftLint

オープンソースの静的解析ツール
- https://github.com/realm/SwiftLint

GithubのSwift Style Guide (https://github.com/github/swift-style-guide)に基づいてSwiftのコードスタイルを強制してくれるツールです。

例えば、次のようにコード規約に反したコードを書いたときに自動的に指摘をしてくれるようになります。

チーム開発では必須ですね

## SwiftDate

- オープンソースの日付パース、フォーマット、カスタム日付作成がSwiftで簡単にできるようになるライブラリ
- https://github.com/malcommac/SwiftDate

次のように扱えます。

```
// 例えば、このようにテキストから日付に設定できたり
let _ = "2010-05-20 15:30".toDate("yyyy-MM-dd HH:mm")
// 次のように日付計算できたり
let _ = ("2010-05-20 15:30:00".toDate() + 3.months - 2.days)
let _ = Date() + 3.hours
let _ = date1 + [.year:1, .month:2, .hour:5]
let _ = date1 + date2
// 次のように判定できたりします
let _ = date.compare(.isToday)
let _ = date.compare(.isNight)
let _ = date.compare(.isNextWeek)
let _ = date.compare(.isThisMonth)
let _ = date.compare(.startOfWeek)
let _ = date.compare(.isNextYear)
```

日付によってXXしたい、N時間後にXしたい等、日付に関わる処理をしたいときに便利！

## PKHUD

- 簡単にいろいろなHUDを表示できるライブラリ
- https://github.com/pkluz/PKHUD

処理中、成功、失敗等のHUDを簡単に表示できるライブラリ。

例えば、次のように表示させることができます。（アニメーション付き）

## Nuke

- 画像読み込み、キャッシュライブラリ
- https://github.com/kean/Nuke

2019年4月現在、周りでよく使われている印象があります👀
ImagePipelineという仕組みがとても便利で、簡単に画像取得の優先度を設定できたりタスクのキャンセルが行えます。筆者が扱っているプロダクトでは、以前はSDWebImageを使っていたのですが、それよりもNukeを使ったほうが画像表示が早く扱いやすく、すぐに乗り換えました。

# Firebase

この章では、iOSアプリ開発においてもはや無くてはならぬ手軽で強力なモバイルおよびWebアプリのバックエンドサービスである、「Firebase」の機能について紹介します。
Firebaseのサービスはいくつかありますが、その中でもモバイルアプリに関わり、本書と趣旨があうものだけを抜粋していきます。

## Firebase Crashlytics

Firebase Crashlyticsはリアルタイムなクラッシュレポートツールで、アプリの品質を低下する要因（クラッシュや非重大なエラー）を追跡することができ、修正するのに役立ちます。

- Firebase Crashlytics
- https://firebase.google.com/docs/crashlytics/?hl=ja

例えば、これを導入してビルド、インストールしたアプリにクラッシュが起きると自動でレポートがFirebaseに蓄積されていきます。次のようにFirebaseのCrashlytics項目を選択すると確認できます。

どのクラスのどの行でクラッシュしたか、iOSの特定のバージョンの問題なのか、どれくらい起きているのか等を確認できます。
何らかのタイミングでクラッシュが急増した場合にも、メール等で自動通知してくれます。

## Firebase Performance Monitoring

iOS/Androidアプリのパフォーマンスを自動で収集し、Firebaseにレポートしてくれる便利なライブラリ

- Firebase Performance Monitoring
- https://firebase.google.com/docs/perf-mon/?hl=ja

主に、次のような指標を収集します。

- レンダリングの速さ
- ネットワークレスポンス
- 起動時の所要時間 ex. 中央値

// TODO: - 参考画像

ここからさらに端末別、OS別、国別等でフィルタリングして表示することができます。
また、このツールを使ってパフォーマンス改善したという記事を弊社のテックブログで公開しています。興味がある方は見てみてください！

- エンジニアドリブンでユーザー体験を約250％改善した話
- https://techblog.tokubai.co.jp/entry/kaizen-ux-lead-by-engineer


## Firebase RemoteConfig

アプリのアップデートをしなくてもリアルタイムでアプリ内の動作や外観を変えることができる便利なツール

- https://firebase.google.com/docs/remote-config/?hl=ja
- Firebase RemoteConfig

主に機能をユーザ属性別（性別、国、年代等）に出したり、新機能を段階公開できたり、ABテストをやりたいときに使用します。
例えば、次のように書くことができます。

```
// 前提: RemoteConfigで取得したデータを管理するRemoteConfigManagerというシングルトンインスタンスがある
// やりたいこと: 性別ごとに一部レイアウトの色が変わるようにしてみたい
navigationController.backgroundColor = RemoteConfigManager.shared.appThemeColor ?? .white // RemoteConfigの値が取得できなかった場合に白
```

## Firebase Authentication

サービス内で匿名ユーザーログイン、メールアドレス＋パスワードログイン、Googleアカウント連携、Twitterアカウント連携等といった実装を簡単に行えるような仕組み

- https://firebase.google.com/docs/auth/?hl=ja

一時的な匿名ユーザーでのログインは、次のような書き方で行うことができます

```
Auth.auth().signInAnonymously() { (authResult, error) in
  let user = authResult.user
  let isAnonymous = user.isAnonymous  // true
  let uid = user.uid
}
```

メールアドレスとパスワードを使ってサインアップしたいときは次のような書き方でできます。（※匿名ユーザからの引き継ぎではないので注意）

```
Auth.auth().createUser(withEmail: email, password: password) { (authResult, error) in
  guard let user = authResult?.user else { return }
  let user = authResult.user
  let isAnonymous = user.isAnonymous  // false
  let uid = user.uid
}
```

同様に、Google連携やTwitter連携も簡単にできるのでドキュメントを参照してみてください。

# テスト
## XCTest

ユニットテスト、パフォーマンステスト、UIテストなどを作成、実行できるフレームワーク

- Apple - XCTest
- https://developer.apple.com/documentation/xctest

特に何もライブラリを導入しなくても、標準のXcodeでも実行できます。

- TODO: 実際に１つテストを書いてみる

## Quick

RSpecやSpecta等のライブラリに似たテスト用ライブラリ

- Quick
- https://github.com/Quick/Quick

先程のXCTestを使って書いたテストコードを、Quickを使って書き直してみます。

- TODO: XCTestで書いたテストをQuickで書き直す

# CI/CD
## Bitrise

モバイルアプリケーション用のCI/CDサービス

- Bitrise
- https://www.bitrise.io/

### 用語解説

- CI (Continuous Integration) 継続的インテグレーション
  - 例: PullRequestの作成時やmasterブランチ変更時に自動ビルドとテストを実行し、品質の安定を図る
- CD (Continuous Delivery) 継続的デリバリー
  - 例: masterブランチが変更されるたびに自動でビルドし、自動でテスターに配布する

### 使い方

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

## Fastlane

iOS/Androidアプリ開発者向けのCI/CD用ライブラリ

- Fastlane
- https://github.com/fastlane/fastlane
- https://docs.fastlane.tools/

スクリーンショットの作成、ProvisioningProfileの処理、アプリのデプロイ、リリース等の作業を自動化できます。

### 導入

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

# 次のステップへ

ここまで、iOSアプリ開発初心者向けにさらにステップアップするためのツールやライブラリ等を解説してきました。では、次のステップでは何をすればよいのか？

と、その前にここまででやってきたことを少し振り返ってみます。

- ライブラリ管理ツールの導入 (Cocoapods, Carthage)
- ライブラリの導入 (R.swift, Nuke等)
- 品質向上のためのツール導入（Crashlytics、Performance Monitorning等）
- テスト (XCTest, Quick)
- CI/CD (Bitrise, fastlane)

ここまででは、アプリ開発のおけるいわゆる基盤といった部分を支える仕組みを導入してきました。
では、基盤を整えたら次は何をするか？そう、グロースです。

次は、アプリを成長させましょう！！！！

アプリを成長させるためのツールとしては、本書で少し紹介した `RemoteConfig` の他にも `Firebase A/BTesting`、`Firebase Cloud Messaging`等、たくさんありますが、それはまた次のお話ということで・・・。

# 最後に

ここまで読んで頂き、ありがとうございました。本書ではiOSアプリ開発初心者にむけて、また、「チュートリアル終わって、サンプルアプリを作れるようになったけど、次なにすりゃいいの？というかみんなどんなツール使ってるの？モダンな環境ってなんだろう？教えて〜〜」と過去に思っていた当時の自分に向けて最高の本を作ろうと思い、書き始めました。

が、業務が押していたりWWDC当選したせいで英語の勉強が挿し込んだり縁があって副業を週1.5でやることになったりと技術同人誌執筆に割く時間が減ってしまい、結果、各ツールやライブラリについて深堀りしていくことができず、広く・浅くの解説になってしまいました。が！、それでも過去の自分がこの本を見て「めっちゃ最高に役立つじゃん！」と思えるような本になんとか頑張って仕上げました。

これからのアプリ開発でどこかしらの部分で、本書で得た知識を活かして頂ければとても嬉しいです。

# 著者紹介

- @k0uhashi　(本名：髙橋　凌 (Ryo Takahashi))

情報系専門学校を2017年に卒業、同年入社した受託開発会社を経て、2018年に株式会社トクバイに入社。
以来、破壊的イノベーションで小売業界を変革するためiOSアプリエンジニアとして従事。
著書はインプレスR＆D社出版の「比較して学ぶRxSwift入門」、前回の技術書典5では「比較して学ぶRxSwift4入門」を頒布
最近は副業として、スタートアップでテックリードをやってたりしてます。
# 一歩先へ進みたいiOSアプリ開発初心者のための開発をもっと便利にするテクニック集
# 0章
- はじめに
- 対象読者
- 必須知識
- 推奨知識
- 想定環境
- 本書に関するお問い合わせ
- サンプルリポジトリ
- ツイッター
- 免責事項
- 表記関係について
- 底本について
# iOSアプリ開発において読んでおくべきもの
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
- XCTest
- Quick
# CI/CD
- Bitrise
- Fastlane
# n-1章 次のステップへ
# end 著者紹介
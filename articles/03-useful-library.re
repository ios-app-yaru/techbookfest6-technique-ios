= ライブラリ
== CocoaPods
Rubyで作られているiOS/MacOS向けのライブラリ管理ツール。オープンソースプロジェクトであり、GitHub上で有志によって開発されている

  * CocoaPods
  * https://github.com/CocoaPods/CocoaPods

GitHubからライブラリをいちいちダウンロードして導入しなくても、これを使うことによって自動でライブラリ間の依存を解決しつつ、ライブラリをプロジェクトに簡単に導入することができるようになります。

=== 導入

前提として、PCにrubyがインストールされている必要がありますが、MacOSではデフォルトで導入されているので、今回はRubyのインストールは省略します。

CocoaPodsをPCに導入するにはterminalを開いて、次のコマンドを実行して下さい。

//emlist[]{
sudo gem install cocoapods
pod setup
//}

その後、terminalでXcodeプロジェクトの階層へ移動し、次のコマンドを実行

//emlist[]{
cd YOUR_PROJECT_DIR
pod init
//}

これでライブラリ管理する準備は完了！あとは生成された @<b>{Podfile} ファイルにどのライブラリをインストールするか記述していきます。

例えば、後に本書で紹介するPKHUD (https://github.com/pkluz/PKHUD) というライブラリを導入したい場合、Podfileを次のように編集します。

//emlist[]{
source 'https://github.com/CocoaPods/Specs.git'

target 'YOUR_PROJECT_TARGET_NAME' do
  use_frameworks!

  pod 'PKHUD'
end
//}

その後、次のコマンドでライブラリの更新とインストールを行います。

//emlist[]{
pod update
//}

このコマンドを打つと、インストールするライブラリのバージョンと、それをどこからとってくるか・・・等が @<b>{Podfile.lock} というファイルに記録されて出力されます。@<br>{}
@<b>{pod install} コマンドを実行すると、この @<b>{Podfile.lock} の中身を参照して、書かれているバージョンにあわせてライブラリを自動でインストールできます。

使い分けの例

  * @<b>{pod install}
  ** 新たにチームメンバーが増えたときに環境を揃えられる
  ** プロジェクトを @<b>{git clone} して @<b>{pod install}
  * @<b>{pod update}
  ** ライブラリのバージョンをアップデートしたい

== Carthage

前節で説明したものと同じようなライブラリ管理ツールとしてCarthage（カーセッジ、カルタゴ）があります。こちらはSwiftで作られていて、同じようにオープンソースプロジェクトとしてGitHubで公開されています。

CocoaPodsとの違いを@<b>{大まかに}すると、CocoaPodsでライブラリ管理をするより、Carthageでライブラリ管理をしたほうが@<b>{コンパイル時間が短縮できる}というメリットがあります。というのも、Carthageはライブラリをインストールするとそれを事前にビルドし、フレームワークを作成してくれるからです。@<br>{}
ただし、導入が少し難しかったり、一部のライブラリは対応していなかったりするのでCocoaPodsと共存することが多いです。

実際に、Carthageを使ってライブラリを導入してみます。

  * WIP

== R.swift

  * https://github.com/mac-cain13/R.swift
  * プロジェクトにインポートした画像やViewControllerのnib名を安全に取得できるようになるライブラリ

例えば、いま開発中のプロジェクト内で画像、ViewControllerを扱うときに次のような書き方をしている場合

//emlist[]{
let icon = UIImage(named: "settings-icon")
let font = UIFont(name: "San Francisco", size: 42)
let color = UIColor(named: "indictator highlight")
let viewController = CustomViewController(nibName: "CustomView", bundle: nil)
let string = String(format: NSLocalizedString("welcome.withName", comment: ""),
      locale: NSLocale.current, "Arthur Dent")
//}

R.swiftを使うことで、次のようにタイプセーフに扱うことができるようになります。

//emlist[]{
let icon = R.image.settingsIcon()
let font = R.font.sanFrancisco(size: 42)
let color = R.color.indicatorHighlight()
let viewController = CustomViewController(nib: R.nib.customView)
let string = R.string.localizable.welcomeWithName("Arthur Dent")
//}

ライブラリの導入に少し手順が必要ですが、導入するとタイプセーフにリソースを扱えるようになり、typoを減らせてかなり便利になります！

  * インストール詳細はコチラ
  * (https://github.com/mac-cain13/R.swift#cocoapods-recommended)

== SwiftLint

  * オープンソースの静的解析ツール
  * https://github.com/realm/SwiftLint

GithubのSwift Style Guide (https://github.com/github/swift-style-guide)に基づいてSwiftのコードスタイルをフォーマットしてくれるツールです。

例えば、次のようにコードスタイルガイドに反したコードを書いたときに自動的に指摘をしてくれます。

//image[swiftlint-example][Swiftlintを実行した時の指摘]{
//}

チーム開発では必須ですね！

デフォルトだと、自分のプロダクトのコード以外にもCocoaPodで導入したライブラリのコードに対してもLintをかけてしまうので、プロジェクトの配下に@<b>{.swiftlint.yml}という名前で設定ファイルを作り、中身を次のように書き換えて下さい。

//emlist[]{
# lint対象とするディレクトリ
included:
  - [あなたのプロジェクトの.swiftファイル群が置かれているディレクトリを指定]
# デフォルトのlint設定は、force castはコンパイルエラーレベルにしているが、warning（黄色いやつ）レベルまでに変更したいときにはこう書く
force_cast: warning
# 上と同じような感じ
force_try:
  severity: warning
# 変数名のlintの除外パターン指定
variable_name:
  excluded:
    - e
    - id
# １つの関数の行数制限
# 80−100まではwarning(黄色）
# 100以上はコンパイルエラー
function_body_length:
  - 80
  - 100
//}

== SwiftDate

  * オープンソースの日付パース、フォーマット、カスタム日付作成がSwiftで簡単にできるようになるライブラリ
  * https://github.com/malcommac/SwiftDate

次のように扱えます。

//emlist[]{
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
//}

日付によってXXしたい、N時間後にXしたい等、日付に関わる処理をしたいときに便利！

== PKHUD

  * 簡単にいろいろなHUDを表示できるライブラリ
  * https://github.com/pkluz/PKHUD

処理中、成功、失敗等のHUDを簡単に表示できるライブラリ。

例えば、次のように表示させることができます。（アニメーション付き）

//image[pkhud-example][PKHUDで使えるHUD集]{
//}

== Nuke

  * 画像読み込み、キャッシュライブラリ
  * https://github.com/kean/Nuke

ImagePipelineという仕組みがとても便利で、簡単に画像取得の優先度を設定できたりタスクのキャンセルが行えます。

筆者が扱っているプロダクトでは、以前はSDWebImageを使っていたのですが、それよりもNukeを使ったほうが画像表示が早く扱いやすかったので乗り換えました。

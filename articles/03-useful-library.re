= ライブラリ
== CocoaPods
Rubyで作られているiOS/MacOS向けのライブラリ管理ツール。オープンソースプロジェクトであり、GitHub上で有志によって開発されている (https://github.com/CocoaPods/CocoaPods) 
いちいちGitHubからライブラリをダウンロードして導入しなくても、これを使うことによって自動で依存を解決しつつ、ライブラリをプロジェクトに簡単に導入することができるようになる。

=== 導入

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

  * `pod install` 
  * 新たにチームメンバーが増えたときに環境を揃えられる
  * プロジェクトを `git clone` して `pod install`
  * `pod update`
  * ライブラリのバージョンをアップデートしたい

== Carthage

前節で説明したものと同じようなライブラリ管理ツールとしてCarthage（カーセッジ、カルタゴ）があります。こちらはSwiftで作られていて、同じようにオープンソースプロジェクトとしてGitHubで公開されています。

CocoaPodsとの違いを大まかにすると、CocoaPodsでライブラリ管理をするより、Carthageでライブラリ管理をしたほうが**コンパイル時間が短縮できる**というメリットがあります。というのも、Carthageはライブラリをインストールするとそれを事前にビルドし、フレームワークを作成してくれるからです。

ただし、一部のライブラリは対応していなかったり、導入が少し難しいという点があります。

インストールや扱いについては変に噛み砕いて説明するより (https://github.com/Carthage/Carthage)の`README.md`のほうがわかりやすいためこちらをご参照下さい。

== R.swift

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

== SwiftLint

オープンソースの静的解析ツール
  * https://github.com/realm/SwiftLint

GithubのSwift Style Guide (https://github.com/github/swift-style-guide)に基づいてSwiftのコードスタイルを強制してくれるツールです。

例えば、次のようにコード規約に反したコードを書いたときに自動的に指摘をしてくれるようになります。

チーム開発では必須ですね

== SwiftDate

  * オープンソースの日付パース、フォーマット、カスタム日付作成がSwiftで簡単にできるようになるライブラリ
  * https://github.com/malcommac/SwiftDate

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

== PKHUD

  * 簡単にいろいろなHUDを表示できるライブラリ
  * https://github.com/pkluz/PKHUD

処理中、成功、失敗等のHUDを簡単に表示できるライブラリ。

例えば、次のように表示させることができます。（アニメーション付き）

== Nuke

  * 画像読み込み、キャッシュライブラリ
  * https://github.com/kean/Nuke

2019年4月現在、周りでよく使われている印象があります👀
ImagePipelineという仕組みがとても便利で、簡単に画像取得の優先度を設定できたりタスクのキャンセルが行えます。筆者が扱っているプロダクトでは、以前はSDWebImageを使っていたのですが、それよりもNukeを使ったほうが画像表示が早く扱いやすく、すぐに乗り換えました。

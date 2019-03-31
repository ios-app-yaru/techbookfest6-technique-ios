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

- Bundler
- R.swift
- RxSwift
- SwiftLint
- HyperioniOS
- SwiftDate
- PKHUD
- Nuke
# Firebase
- Crashlytics
- Performance
- RemoteConfig
# テスト
- XCTest
- Quick
# CI/CD
- Bitrise
- Fastlane
# n-1章 次のステップへ
# end 著者紹介
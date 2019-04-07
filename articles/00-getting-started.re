= はじめに

この本を手にとって頂き、ありがとうございます。@<br>{}
本書では、「比較して学ぶ」をテーマにcallback、delegate、KVOとRxSwiftでの実装パターンを比較しながらRxSwiftについて解説していきます。@<br>{}
解説はRxSwiftをまったく触ったことのない人向けに思想・歴史から基礎知識、よく使われる文法、実際にアプリの部品としてどう書くかまでできるだけわかりやすく書きました。

RxSwiftは2016年頃にiOSアプリ開発者界隈へ一気に普及し、2018年現在ではいわゆる「イケてる」アプリのほとんどがRxSwift（もしくはReactiveSwift）を採用しています。@<br>{}
...主語がデカいですが、筆者の観測範囲の中ではそれくらいあたりまえのように使われています。

ほとんどがRxSwiftを採用しているということは、扱いを知っていなければ機能を開発していくことができません。@<br>{}
しかし、その概念を習得するためには学習コストが高く、iOSアプリエンジニアになってから日の浅い人にとっては、高い壁になっているのではないかと感じます。

筆者もまだ日が浅かった頃は、Google検索で出てきた技術ブログ、Qiitaの解説記事やRxSwiftのリポジトリ内のドキュメントなど各メディアに分散されている知見を参照しながら実装していて、@<br>{}
「RxSwiftを日本語で解説してて体系的に学べる本、無いかなーあったら楽だなー」と思いながら試行錯誤してコードを書いていました。

本書はそんな過去の自分と、これからRxSwiftについて学びたい方に向けて体系的に学べるコンテンツを提供したいという思いから生まれました。@<br>{}
この本を読んで、RxSwiftの概念がわかった！理解がもっと深まった！完全に理解した！RxSwiftﾁｮｯﾄﾃﾞｷﾙ！となってくれたら嬉しいです。

== 対象読者

本書は次の読者を対象として作成しています。

  * SwiftによるiOSアプリの開発経験が少しだけある（3ヶ月〜1年未満）
  * RxSwiftライブラリを使った開発をしたことがない・ほんの少しだけある

== 必須知識

  * Swiftの基本的な言語仕様
  ** if、for、switch、enum、class、struct
  ** よく使われる高階関数の扱い
  *** mapやfilterなど
  * Xcodeの基本的な操作
  * よく使われるUIKitの大まかな仕様
  ** UILabel、UITextView、UITableView、UICollectionView

== 推奨知識

  * 設計パターン
  ** MVPアーキテクチャ
  ** MVVMアーキテクチャ
  * デザインパターン
  ** delegateパターン
  ** KVOパターン
  ** Observerパターン

== 想定環境

  * OSX High Sierra
  * Xcode 10
  * Swift 4.2
  * cocoapods 1.5.3

== お問い合わせ先

  * Twitter
  ** https://twitter.com/k0uhashi

== 免責事項

本書は有志によって作成されているもので、米Apple社とは一切関係がありません。@<br>{}
また、掲載されている内容は情報の提供のみを目的にしていて、本書を用いた開発・運用は必ず読者の責任と判断によって行ってください。@<br>{}
著者は本書の内容による開発、運用の結果によっての結果について、いかなる責任も負いません。

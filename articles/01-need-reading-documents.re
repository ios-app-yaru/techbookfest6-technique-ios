= iOSアプリ開発において読んでおくべきもの

本章では、これからのiOSアプリ開発において、読んでおくべきだと感じたリファレンスや書物、サイトを紹介していきます。

== Human Interface Guidelines

  * Human Interface Guidelines (https://developer.apple.com/design/human-interface-guidelines/)
  * 以下、HIG

AppleによるUI設計の原則を定めたガイドライン。なんかイマイチなUIだな〜、使い心地良くないな〜・・・と感じるのであれば、一度見てみましょう。感じていなくても、見ましょう！
例えば、次のようなことが書かれています。

  * 2個くらい紹介する

== iOSアプリ開発ベストプラクティス

  * iOS-factor (https://ios-factor.com/ja/)
  * リポジトリ (https://github.com/ios-factor/ios-factor.com)

これまでのiOSアプリ開発プラクティスの歴史や現代のiOSアプリ開発の開発環境の設定やデプロイ、開発における考え方（すべてのユーザーが最新バージョンにアップデートすることを前提にしない...）など現代のiOSアプリ開発者にとってとても役に立つプラクティス集です。オープンソースプロジェクトで有志によって更新されています。

例えば、次のようなことが書かれています。

//emlist[]{
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
}

== Swift実践入門 ── 直感的な文法と安全性を兼ね備えた言語 (WEB+DB PRESS plus)

  * 技術評論社より出版

Swiftとはなんぞや？というところから、言語仕様解説、実際の業務でどう使うか？まで解説していて、初心者〜上級者までこれ１冊でいけるといっても過言ではないくらい良い本です。必須。実際、著者（僕）もiOSアプリ開発に入門するときに一番最初に購入しました。

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

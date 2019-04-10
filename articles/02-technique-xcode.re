= Xcode超活用術

本章では、Xcodeの便利ショートカットから便利なデバッグの方法、コードスニペット等についてを紹介しています。これらの知識があるとなしの場合ではかなり開発効率が違ってくるので、ぜひ覚えてみましょう！

== ショートカット

XcodeでiOSアプリを効率的に開発する上で習得必須な便利ショートカットをここで紹介していきます。

=== Build周り
  * Command + B
  ** ビルド
  * Command + R
  ** ビルド後にアプリを実行
  * Command + Control + R
  ** 直近でビルドした成果物を利用してアプリを実行
  ** 開発中にアプリがクラッシュしたときや何らかの影響でアプリが落ちた時に、デバッガを有効にした状態で起動したい場合に便利！
  * Command + U
  ** テスト実行
  * Command + Control + R
  ** 直近でビルドした成果物を利用してテスト実行
  * Command + . (ドット)
  ** 実行中のビルドやアプリを終了
  * Command + K
  ** クリーン
  * Command + \
  ** ブレークポイントの追加や削除
  * Command + Control + Y
  ** ブレークポイントのところから再開

=== 検索周り
  * Command + F
  ** エディタ内の検索
  * Command + Option + F
  ** エディタ内の置換
  * Command + Shift + F
  ** プロジェクト内の検索
  * Command + Shift + Option + F
  ** プロジェクト内の置換
  * Command + Control + Y
  ** ファイルの検索
  * Command + Shift + O（オー）
  ** プロジェクト内のファイル名やメソッドの検索
  ** これを覚えるとでかい！

=== コードエディタ周り
  * Command + Shift + J
  ** プロジェクトナビゲータで現在編集しているファイルの位置をフォーカスさせる
  * Option + Click
  ** 軽くリファレンスを表示

=== シミュレータ
  * Command + S
  ** スクリーンショットの撮影
  * Command + K
  ** キーボードの表示、非表示の切り替え
  * Command + Shift + H
  ** ホーム画面に戻る

== デバッグ術

Xcodeでは、デバッグするときにprint文を使って値を追っていく方法の他に、ソースコードエディタの行数の部分をクリックして、@<b>{ブレークポイント}を設定して値を方法もあります。（外すときは青い矢印を外にドラッグ）

//image[set-break-point][ブレークポイントの設定][scale=0.9]{
//}

Xcodeでビルド＆実行中にこの設定したブレークポイントの部分の処理が実行されると、そこで一時停止ができ変数の中身を確認できます。（右下で@<code>{po 変数名} コマンドを入力すると同じように確認できます。

//image[step-break-point][ブレークポイントで一時停止][scale=0.9]{
//}

しかし、for文の中の値を見たい場合繰り返されるたびに一時停止して値を確認するのは面倒です。Xcodeにはブレークポイントで一時停止させずに変数の結果だけ出力させる方法もあるのでそれを使ってみます。

次のように設定してみてください

//image[setup-auto-continue-action-break-point][ブレークポイントの詳細設定]{
//}

==== expression

また、ブレークポイントで一時停止させている時に変数へ値を代入できます。
一時停止したら@<b>{(lldb)}のところで@<code>{expression 変数 = 新しい変数}とやってみてください

//image[use-expression][expressionの使用]{
//}

@<b>{let}で定義されている変数でも代入できました！

== 魔法のコードスニペット

Xcodeには、似たコードをいちいち書かなくても良いように、@<b>{Code Snippet}という機能が搭載されています。
試しに、Xcode上で@<b>{Command + Shift + L}を押して呼び出してみてください。

何も設定を変更していなければ、次の画面がでてきます。

//image[show-code-snippet][Code Snippet][scale=0.6]{
//}

それをEnterかエディタ上へドラッグアンドドロップすると、指定したスニペットがエディタ上に貼り付けられます。

//image[use-sample-snippet][サンプル][scale=0.9]{
//}

ここの灰色の部分は@<b>{<# #>}で文字を囲むと作れます。

新しくsnippetを作る場合は、上部メニューバーの Editor > Create Code Snippet から作成します。
ちなみに、筆者は次のようなものを作って使っています。

//emlist[]{
// テスト用のテンプレ (後に紹介するQuickというテストフレームワーク用)
import XCTest
import Nimble
import Quick
@testable import <# Product Name #>

class <# test class name ex. LocalNotificationTests #>: QuickSpec {

    override func spec() {

        beforeEach {
        }

        describe("<# test title ex. Test Location Manager #>") {

            <# local variables #>

            context("<# context name ex. Append Notification #>", {
                it("<# it name ex. Simple Append #>", closure: {

                })
            })
        }
    }
}
//}

//emlist[]{
// R.swiftを用いてCustomViewを作る時
import UIKit

class <# View Class Name #>: UIView {

    override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        commonInit()
    }

    private func commonInit() {
        if let view = R.nib.<# View Class Name #>.firstView(owner: self) {
            view.frame = self.bounds
            view.autoresizingMask = [.flexibleHeight, .flexibleWidth]
            self.addSubview(view)
        }
    }
}
//}

//emlist[]{
@IBOutlet private weak var <# variable name #>: <# class name #>
//}

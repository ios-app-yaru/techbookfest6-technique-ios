= テスト
== XCTest

ユニットテスト、パフォーマンステスト、UIテストなどを作成、実行できるフレームワーク

  * Apple - XCTest
  * https://developer.apple.com/documentation/xctest

特に何もライブラリを導入しなくても、標準のXcodeでも実行でき、次のようにテストを書いていきます。

//emlist[]{
import XCTest
@testable import test_sample

class test_sampleTests: XCTestCase {

    override func setUp() {
        // テスト実行前の準備
        // ex. UserDefaultsの値の削除など
    }

    override func tearDown() {
        // test○○の終了後の掃除
    }

    func testExample() {
        // サンプルテストケース
    }

    func testPerformanceExample() {
        // パフォーマンス計測用
        self.measure {
            // 計測したいコードを書く
        }
    }
}
//}

試しにいくつかサンプルを書いてみます

//emlist[]{
// Int+Common.swift
extension Int {
    func increment() -> Int {
        return self + 1
    }
    func decrement() -> Int {
        return self - 1
    }
}
// Array+Common.swift
extension Array {
    func isNotEmpty() -> Bool {
        return !self.isEmpty
    }
}
//}

この場合、テストは次のように実装できます。

//emlist[]{
// Int+CommonTest.swift
import XCTest
@testable import test_sample

class IntCommonTest: XCTestCase {
    func testIncrement() {
        let number = 0
        XCTAssertEqual(number.increment(), 1)
        XCTAssertEqual(number.increment().increment(), 2)
    }

    func testDecrement() {
        let number = 0
        XCTAssertEqual(number.decrement(), -1)
        XCTAssertEqual(number.decrement().decrement(), -2)
    }
}

// Array+CommonTest.swift
import XCTest
@testable import test_sample

class ArrayCommonTest: XCTestCase {
    func testIsNotEmpty() {
        let emptyArray: [Int] = []
        let oneArray: [Int] = [0]
        let twoArray: [Int] = [1,2]

        XCTAssertFalse(emptyArray.isNotEmpty())
        XCTAssertTrue(oneArray.isNotEmpty())
        XCTAssertTrue(twoArray.isNotEmpty())
    }
}
//}

== Quick

RSpecやSpecta等のライブラリに似たテスト用ライブラリ

  * Quick
  * https://github.com/Quick/Quick

まずは、ライブラリを導入します

//emlist[]{
# Podfile
target 'test-sample' do
  use_frameworks!

  target 'test-sampleTests' do
    inherit! :search_paths
    pod 'Quick'
    pod 'Nimble'
  end

  target 'test-sampleUITests' do
    inherit! :search_paths
  end

end
//}

//emlist[]{
pod install
//}

先程のXCTestを使って書いたテストコードを、Quickを使って書き直してみます。

//emlist[]{
// Int+CommonTest.swift
import XCTest
import Quick
import Nimble

@testable import test_sample

class IntCommonTest: QuickSpec {
    override func spec() {
        describe("Test Extension") {
            let number = 0
            it("Test Increment") {
                expect(number.increment()).to(equal(1))
                expect(number.increment().increment()).to(equal(2))
            }
            it("Test Decrement") {
                expect(number.decrement()).to(equal(-1))
                expect(number.decrement().decrement()).to(equal(-2))
            }
        }
    }
}

// Array+CommonTest.swift
import XCTest
import Quick
import Nimble
@testable import test_sample

class ArrayCommonTest: QuickSpec {
    override func spec() {
        describe("Test Extension") {
            it("Test isNotEmpty") {
                let emptyArray: [Int] = []
                let oneArray: [Int] = [0]
                let twoArray: [Int] = [1,2]

                expect(emptyArray.isNotEmpty()).to(equal(false))
                expect(oneArray.isNotEmpty()).to(equal(true))
                expect(twoArray.isNotEmpty()).to(equal(true))
            }
        }
    }
}
//}

@<b>{Test Success!!}

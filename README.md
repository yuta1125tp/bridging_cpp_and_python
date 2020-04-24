# PythonとC++の橋渡し

## numpyを組み合わせた利用方法
以下のQiitaの記事を丸コピ。記事にはVisual StudioのDebugerが効かないとあったが、debug時のパスの誤認識か？$(ProjectDir)に読み込み対象のpythonスクリプトを置くとデバッグできる。  
[C++ から Numpy付 Boost を介して Pythonを呼ぶ （Visual Studio 2017 対応）](https://qiita.com/SatoshiTerasaki/items/03e5d9b6a1c353d7273b)

## Boostのビルド
boost_1_72で確認  
ダウンロードと解凍も結構時間がかかるので注意

user-config.jamでanacondaのpythonの.exeとlibsとincludeを指定して *--with-python* を付けてb2.exeを実行する。  

c++のコードをvisual studioでビルドしたときに以下のエラーが発生した。  
> 重大度レベル	コード	説明	プロジェクト	ファイル	行	抑制状態
エラー	LNK1181	入力ファイル 'libboost_python36-vc142-mt-sgd-x64-1_72.obj' を開けません。	PyLib	C:\Users\yshira\Work\VAR\src\PyLib\PyLib\LINK	1	  

ビルド済みのboostライブラリを見るとsgdじゃなくてgdならあった。sgdとgdの違いはruntime-linkがsharedかstaticかの違いらしい。Runtime-link=staticにして再度b2を実行したら解決した。


```cmd
REM 実行した内容はこんな感じ。
> cd $(PATH_TO_BOOST_SRC)
>.\bootstrap.bat
>vim tools\build\src\user-config.jam
>.\b2 toolset=msvc-14.2 variant=debug,release runtime-link=static,shared link=static --build-type=complete stage --abbreviate-paths architecture=x86 address-model=64 install -j6 --with-python
```

[user-config.jamについて](https://stackoverflow.com/questions/30379543/not-able-to-find-user-config-jam-while-installing-boost-libraries)  
[pythonパスの設定方法](https://github.com/boostorg/build/issues/194#issuecomment-299030791)


# 
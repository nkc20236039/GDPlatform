@echo off
setlocal

REM ビルドディレクトリを作成（なければ）
if not exist build (
    mkdir build
)

REM ビルドディレクトリに移動
cd build

REM CMakeでVisual Studio用のプロジェクトファイル生成
cmake -G "Visual Studio 17 2022" ..

REM Release構成でビルド
cmake --build . --config Release

REM ビルドされた実行ファイルを実行（パスは適宜変更）
.\Release\GDPlatform.exe

endlocal
pause
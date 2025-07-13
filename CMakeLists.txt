cmake_minimum_required(VERSION 3.20)
project(GDPlatform CXX)

# C++20 を有効にする
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)  # 拡張無効で標準準拠

# src 配下の .cpp ファイルをすべて再帰的に取得
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# 実行ファイルターゲットを定義
add_executable(GDPlatform WIN32 ${SOURCES})

# include ディレクトリをこのターゲットにだけ適用
target_include_directories(GDPlatform PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Visual Studio の IDE 内表示用にグループ分け
source_group(TREE ${CMAKE_SOURCE_DIR}/src PREFIX "Source Files" FILES ${SOURCES})
/*********************************************************************
 * @file   lib.h
 * @brief  プロジェクトに必要なライブラリのリンクを定義
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#pragma once

 // DirectX11描画処理
#pragma comment(lib, "d3d11.lib")
// DirectX11グラフィックスインターフェイス
#pragma comment(lib, "dxgi.lib")
// DirectX11シェーダーコンパイラ
#pragma comment(lib, "d3dcompiler.lib")
// DirectX11GUID
#pragma comment(lib, "dxguid.lib")
// サウンド
#pragma comment(lib, "xaudio2.lib")
// XBoxコントローラー入力
#pragma comment(lib, "xinput.lib")
// 日本語IDE対応
#pragma comment(lib, "imm32.lib")
// Windows APIの基本機能
#pragma comment(lib, "winmm.lib")
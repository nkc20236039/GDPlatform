/*********************************************************************
 * @file   WindowManager.cpp
 * @brief  ウィンドウ管理の実装
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#include "System/WindowManager.h"

#include "WindowSetting.h"

using namespace GDPlatform;

// ウィンドウマネージャのコンストラクタ
bool WindowManager::Init() {
	// ウィンドウの初期化をし、失敗したらこの関数も失敗と返す
	if (!InitWindow()) { return false; }

	// ウィンドウを表示
	ShowWindow(hWnd, SW_SHOWNORMAL);

	// ウィンドウを更新
	UpdateWindow(hWnd);

	// ウィンドウにフォーカスする
	SetFocus(hWnd);

	// ウィンドウ初期化が成功
	return true;
}

// クリーンアップ処理
void WindowManager::CleanUp() {

}

// ウィンドウの初期化
bool WindowManager::InitWindow() {
	// ウィンドウクラス登録
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;	// ウィンドウスタイル
	wcex.lpfnWndProc = wndProc;				// ウィンドウのメッセージを処理するコールバック関数へのポインタ
	wcex.cbClsExtra = 0;					// ウィンドウクラス構造体の後ろに割り当てる補足のバイト数
	wcex.cbWndExtra = 0;					// ウィンドウインスタンスの後ろに割り当てる補足のバイト数
	wcex.hInstance = hInstance;				// このクラスのためのウィンドウプロシージャがあるハンドル
	wcex.hIcon = nullptr;					// アイコン
	wcex.hCursor = nullptr;					// マウスカーソル
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;// ウィンドウ背景色
	wcex.lpszMenuName = nullptr;			// デフォルトメニュー名
	wcex.lpszClassName = WindowSetting::GetWindowClassName();		// ウィンドウクラス名
	wcex.hIconSm = nullptr;					// 小さいアイコン
	// ウィンドウクラスの登録
	if (!RegisterClassEx(&wcex)) { return false; }

	// ウィンドウ生成 成功時はウィンドウハンドル、失敗時はnullが返る
	hWnd = CreateWindow(
		WindowSetting::GetWindowClassName(),	// RegisterClass()で登録したクラスの名前
		WindowSetting::GetWindowTitle(),		// タイトルバー
		WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,	// ウィンドウスタイル
		CW_USEDEFAULT,							// ウィンドウ左上x座標
		CW_USEDEFAULT,							// ウィンドウ左上y座標
		WindowSetting::GetWidth(),				// ウィンドウ幅
		WindowSetting::GetHeight(),				// ウィンドウ高さ
		nullptr,								// 親ウィンドウのハンドル
		nullptr,								// メニューのハンドル
		wcex.hInstance,							// ウィンドウを作成するモジュールのハンドル
		nullptr									// WM_CREATEでLPARAMに渡したい値
	);
	// エラーが発生した場合失敗(false)を返す
	if (!hWnd) { return false; }

	// 正常終了
	return true;
}

// ウィンドウのイベントを処理するコールバック関数
LRESULT CALLBACK WindowManager::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CLOSE:		// 閉じるボタンが押されたメッセージ
		PostMessage(hWnd, WM_DESTROY, 0, 0);
		break;
	case WM_DESTROY:	// ウィンドウが終了するメッセージ
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	// 既定のウィンドウプロシージャを呼び出して処理を返す
	return DefWindowProc(hWnd, message, wParam, lParam);
}
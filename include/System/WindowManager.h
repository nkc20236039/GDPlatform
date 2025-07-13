/*********************************************************************
 * @file   WindowManager.h
 * @brief  アプリケーションのウィンドウ管理
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#pragma once

#include <Windows.h>

#include "System/SystemSetup.h"

namespace GDPlatform {
/**
 * @brief アプリのウィンドウ管理
 */
class WindowManager : public SystemSetup
{
public:
	WindowManager() : hWnd(nullptr), hInstance(nullptr) {}
	~WindowManager() = default;

	/**
	 * bool Init
	 * @brief システム開始時に初期化を行う
	 *
	 * @return (bool) 初期化に成功した場合TRUEが返される
	 */
	bool Init() override;

	/**
	 * void CleanUp
	 * @brief システムが終了する際にクリーンアップを行う
	 */
	void CleanUp() override;
private:
	HWND hWnd;	///< ウィンドウハンドル
	HINSTANCE hInstance;	///< インスタンスハンドル

	/**
	 * bool initWindow
	 * @brief
	 *
	 * @return (bool) 初期化に成功した場合TRUEが返される
	 */
	bool InitWindow();

	/**
	 * LRESULT wndProc
	 * @brief ウィンドウのイベントを処理するコールバック
	 *
	 * @param hWnd    ウィンドウハンドル
	 * @param message イベントメッセージ
	 * @param wParam  ウィンドウの情報
	 * @param lParam  メッセージの追加情報
	 * @return        メッセージの処理結果
	 */
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
}
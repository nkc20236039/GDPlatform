/*********************************************************************
 * @file   WinMain.cpp
 * @brief  アプリのエントリポイント
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#include <windows.h>

#include "System/WindowManager.h"
#include "lib.h"

using namespace GDPlatform;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow) {
	auto window = WindowManager();

	window.Init();
}
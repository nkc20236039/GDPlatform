/*********************************************************************
 * @file   WindowSetting.cpp
 * @brief  ウィンドウの設定をするクラスの実装
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#include "WindowSetting.h"

using namespace GDPlatform;

// 初期化処理
int WindowSetting::width = 1280;
int WindowSetting::height = 720;
const wchar_t* WindowSetting::windowTitle = L"GDPlatform";
const wchar_t* WindowSetting::className = L"GDPlatformWindowClass";

// ウィンドウの幅を取得
int GDPlatform::WindowSetting::GetWidth()
{
	return width;
}

// ウィンドウの高さを取得
int GDPlatform::WindowSetting::GetHeight()
{
	return height;
}

// ウィンドウのタイトルを取得
const wchar_t* GDPlatform::WindowSetting::GetWindowTitle()
{
	return windowTitle;
}

// ウィンドウのクラス名を取得
const wchar_t* GDPlatform::WindowSetting::GetWindowClassName()
{
	return className;
}

// ウィンドウのサイズを設定
void GDPlatform::WindowSetting::SetWindowSize(int width, int height)
{
	WindowSetting::width = width;
	WindowSetting::height = height;
}

// ウィンドウのクラス名を設定
void GDPlatform::WindowSetting::SetClassName(const wchar_t* name)
{
	className = name;
}

// ウィンドウのタイトルを設定
void GDPlatform::WindowSetting::SetWindowTitle(const wchar_t* title)
{
	windowTitle = title;
}
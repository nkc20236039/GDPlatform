/*********************************************************************
 * @file   WindowSetting.h
 * @brief  ウィンドウの設定を管理する
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

#pragma once

namespace GDPlatform {

/**
 * @brief ウィンドウの設定を管理するクラス
 *
 * このクラスはウィンドウのサイズやタイトル、クラス名などの設定を管理します。
 * インスタンス化はできません。全ての設定は静的メソッドを通じて行います。
 */
class WindowSetting final {
public:
	// このクラスはインスタンス化できないようにする
	WindowSetting() = delete;
	~WindowSetting() = delete;
	// Getter
	/**
	 * @brief ウィンドウの幅を取得する
	 *
	 * @return (int) ウィンドウの幅
	 */
	static int GetWidth();
	/**
	 * int GetHeight
	 * @brief ウィンドウの高さを取得する
	 *
	 * @return (int) ウィンドウの高さ
	 */
	static int GetHeight();
	/**
	 * const wchar_t * GetWindowTitle
	 * @brief ウィンドウのタイトルを取得する
	 *
	 * @return (const wchar_t*) ウィンドウのタイトル
	 */
	static const wchar_t* GetWindowTitle();
	/**
	 * const wchar_t * GetWindowClassName
	 * @brief ウィンドウのクラス名を取得する
	 *
	 * @return (const wchar_t*) ウィンドウのクラス名
	 */
	static const wchar_t* GetWindowClassName();

	// Setter
	/**
	 * void SetWindowSize
	 * @brief ウィンドウのサイズを設定する
	 *
	 * @param width  設定するウィンドウの幅
	 * @param height 設定するウィンドウの高さ
	 */
	static void SetWindowSize(int width, int height);
	/**
	 * void SetClassName
	 * @brief ウィンドウのクラス名を設定する
	 *
	 * @param name 設定するウィンドウクラス名
	 */
	static void SetClassName(const wchar_t* name);
	/**
	 * void SetWindowTitle
	 * @brief ウィンドウのタイトルを設定する
	 *
	 * @param title 設定するウィンドウのタイトル
	 */
	static void SetWindowTitle(const wchar_t* title);

private:
	static int width;	///< ウィンドウの幅
	static int height;	///< ウィンドウの高さ
	static const wchar_t* windowTitle;	///< ウィンドウのタイトル
	static const wchar_t* className;	///< ウィンドウクラス名
};
}

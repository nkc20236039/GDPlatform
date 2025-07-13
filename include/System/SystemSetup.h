/*********************************************************************
 * @file   SystemSetup.h
 * @brief  システムの初期化処理とクリーンアップを行うインターフェース
 *
 * @author Uto
 * @date   2025/7/13
 *********************************************************************/

namespace GDPlatform {
/**
 * @brief システムの初期化とクリーンアップを行うインターフェース
 */
class SystemSetup
{
public:
	SystemSetup() = default;
	~SystemSetup() = default;
	/**
	 * bool Init
	 * @brief システム開始時に初期化を行う
	 * 
	 * @return (bool) 初期化に成功した場合TRUEが返される
	 */
	virtual bool Init() = 0;
	/**
	 * void CleanUp
	 * @brief システムが終了する際にクリーンアップを行う
	 */
	virtual void CleanUp() = 0;
};
}
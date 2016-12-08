// Main_config.h: interface for the Main_config class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_)
#define AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_
#define PATH_SIZE 1000
#include "Config.h"

// 主配置文件封装
class Main_config
{
public:
	// @brief 获取实例
	static Main_config& instance();

	// @brief 获取配置Config对象
	const Config& get_config();

	// @brief 导入配置文件
	bool load_config();

private:
	Main_config();

	virtual ~Main_config();

	// 配置对象
	Config* _config;

	// 配置文件路径
	char _conf_path[PATH_SIZE];

	// 配置文件名
	char _conf_name[PATH_SIZE];
};

#endif // !defined(AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_)

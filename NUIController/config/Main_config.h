// Main_config.h: interface for the Main_config class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_)
#define AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_
#define PATH_SIZE 1000
#include "Config.h"

// �������ļ���װ
class Main_config
{
public:
	// @brief ��ȡʵ��
	static Main_config& instance();

	// @brief ��ȡ����Config����
	const Config& get_config();

	// @brief ���������ļ�
	bool load_config();

private:
	Main_config();

	virtual ~Main_config();

	// ���ö���
	Config* _config;

	// �����ļ�·��
	char _conf_path[PATH_SIZE];

	// �����ļ���
	char _conf_name[PATH_SIZE];
};

#endif // !defined(AFX_MAIN_CONFIG_H__B4BEEE3F_3D81_4428_A25F_66E6B56318F2__INCLUDED_)

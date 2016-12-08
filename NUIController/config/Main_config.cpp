// Main_config.cpp: implementation of the Main_config class.
//
//////////////////////////////////////////////////////////////////////

#include "Main_config.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Main_config::Main_config()
{
	_snprintf(_conf_name, sizeof(_conf_name), "%s", "config.ini");
}

Main_config::~Main_config()
{
	if(_config)
	{
		delete _config;
	}
}

bool Main_config::load_config()
{
	bool ret = true;
	
	_config = new(std::nothrow) Config(_conf_name);
	if (_config == NULL)
	{
		return false;
	}

	return ret;
}

Main_config& Main_config::instance()
{
	static Main_config main_config;
	return main_config;
}

const Config& Main_config::get_config()
{
	return *_config;
}



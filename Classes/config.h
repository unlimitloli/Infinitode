#pragma once

class CsbConfig
{
public:
	char * start_layer = "cocostudio/StartLayer.csb";
	char * game_layer = "cocostudio/GameLayer.csb";
	char * menu_layer = "cocostudio/MenuLayer.csb";
};

extern CsbConfig csb_config;
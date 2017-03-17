#pragma once

class CsbConfig
{
public:
	char * start_layer = "cocostudio/StartLayer.csb";
	char * game_layer = "cocostudio/GameLayer.csb";
	char * menu_layer = "cocostudio/MenuLayer.csb";

	char * tower_cell = "cocostudio/cells/tower_cell.csb";
};

extern CsbConfig csb_config;
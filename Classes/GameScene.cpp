#include "GameScene.h"
#include "GameLayer.h"

USING_NS_CC;

bool GameScene::init()
{
	if (!Scene::init())
		return false;

	m_game_layer = GameLayer::create();
	addChild(m_game_layer);

	return true;
}
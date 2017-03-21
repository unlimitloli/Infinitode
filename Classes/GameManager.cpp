#include "GameManager.h"
#include "GameLayer.h"
#include "MenuLayer.h"
#include "MapCell.h"
#include "GameMap.h"

USING_NS_CC;

GameManager * manager = nullptr;

GameManager * GameManager::getInstance()
{
	if (manager == nullptr)
	{
		manager = new GameManager();
		if (manager && manager->init())
		{
			manager->autorelease();
			manager->retain();
			return manager;
		}
		else
		{
			CC_SAFE_RELEASE_NULL(manager);
			return nullptr;
		}
	}

	return manager;
}

void GameManager::start()
{
	if (manager != nullptr)
	{
		_win->addChild(this, (int)OrderType::system);
	}
}

void GameManager::end()
{
	if (manager != nullptr)
	{
		manager->removeFromParentAndCleanup(true);
		manager->release();
		manager = nullptr;
	}
}

bool GameManager::init()
{
	if (!Node::init())
		return false;

	return true;
}

void GameManager::setGameLayer(GameLayer *layer)
{
	m_game_layer = layer;
}

void GameManager::setMenuLayer(MenuLayer *layer)
{
	m_menu_layer = layer;
}

GameLayer * GameManager::getGameLayer()
{
	return m_game_layer;
}

MenuLayer * GameManager::getMenuLayer()
{
	return m_menu_layer;
}

MonsterManager * GameManager::getMonsterManager()
{
	return m_game_layer->getGameMap()->getMonsterManager();
}

BulletManager * GameManager::getBulletManager()
{
	return m_game_layer->getGameMap()->getBulletManager();;
}

void GameManager::openMenu(MapCell *map_cell)
{
	m_menu_layer->show(map_cell);
}


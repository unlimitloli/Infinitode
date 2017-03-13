#include "GameManager.h"

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

void GameManager::close()
{
	if (manager != nullptr)
	{
		manager->removeFromParentAndCleanup(true);
		manager = nullptr;
	}
}

bool GameManager::init()
{
	if (!Node::init())
		return false;

	win->addChild(this, (int)OrderType::system);

	return true;
}
#include "Win.h"
#include "StartLayer.h"
#include "GameLayer.h"
#include "MenuLayer.h"

USING_NS_CC;
using namespace std;

static Win * win_class = nullptr;

Win * Win::getInstance()
{
	if (win_class == nullptr)
	{
		win_class = new Win();
		if (win_class && win_class->init())
		{
			win_class->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(win_class);
		}
	}
	return win_class;
}

cocos2d::Layer * Win::open(cocos2d::Layer * layer, OrderType z_order)
{
	if (m_layers.contains(layer))
		return layer;
	
	addChild(layer, (int)z_order);
	m_layers.pushBack(layer);
	return layer;
}

cocos2d::Layer * Win::open(LayerType type, OrderType z_order)
{
	Layer *layer = nullptr;
	switch (type)
	{
	case LayerType::StartLayer:
		layer = StartLayer::create();
		break;
	case LayerType::GameLayer:
		layer = GameLayer::create();
		break;
	case LayerType::MenuLayer:
		layer = MenuLayer::create();
		break;
	default:
		break;
	}

	if (layer != nullptr)
		return open(layer, z_order);

	return nullptr;
}

void Win::close(cocos2d::Layer * layer)
{
	if (!m_layers.contains(layer))
		return;

	m_layers.eraseObject(layer);
	layer->removeFromParentAndCleanup(true);
}

void Win::addTouch(cocos2d::ui::Widget *widget, const std::function<void(cocos2d::Ref *, int)> &callback, int param, int music)
{
	widget->addTouchEventListener([=](cocos2d::Ref *sender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			callback(sender, param);
		}
	});
}

bool Win::init()
{
	if (!Scene::init())
		return false;

	return true;
}

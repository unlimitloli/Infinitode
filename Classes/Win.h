#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"

#define _win			Win::getInstance()

enum class LayerType
{
	StartLayer,
	GameLayer,
	MenuLayer,
};

enum class OrderType
{
	system = 10,
	ui = 100,
	view = 200,
	menu = 300,
	dialog = 400,
	tips = 1000,
};

class Win : public cocos2d::Scene
{
public:
	static Win * getInstance();

	cocos2d::Layer * open(cocos2d::Layer *layer, OrderType z_order = OrderType::ui);
	cocos2d::Layer * open(LayerType type, OrderType z_order = OrderType::ui);
	void close(cocos2d::Layer *layer);

	void addTouch(cocos2d::ui::Widget *widget, const std::function<void (cocos2d::Ref *sender, int type)> &callback, int param = 0, int music = 0);

protected:
	virtual bool init() override;

	cocos2d::Vector<cocos2d::Layer *> m_layers;
};
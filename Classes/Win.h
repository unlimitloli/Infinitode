#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"

#define win			Win::getInstance()

enum class LayerType
{
	StartLayer,
	GameLayer,
};

enum class OrderType
{
	ui = 100,
	view = 200,
	dialog = 300,
	tips = 1000,
};

class Win : public cocos2d::Scene
{
public:
	static Win * getInstance();

	void open(cocos2d::Layer *layer, OrderType z_order = OrderType::ui);
	void open(LayerType type, OrderType z_order = OrderType::ui);
	void close(cocos2d::Layer *layer);

	void addTouch(cocos2d::ui::Widget *widget, const std::function<void (cocos2d::Ref *sender, int type)> &callback, int param = 0, int music = 0);

protected:
	virtual bool init() override;

	cocos2d::Vector<cocos2d::Layer *> m_layers;
};
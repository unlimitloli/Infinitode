#include "AttrCell.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace std;

AttrCell * AttrCell::create(TowerAttribute attr)
{
	auto attr_cell = new AttrCell();
	if (attr_cell && attr_cell->init(attr))
	{
		attr_cell->autorelease();
		return attr_cell;
	}
	else
	{
		CC_SAFE_DELETE(attr_cell);
		return nullptr;
	}
	return nullptr;
}

bool AttrCell::init(TowerAttribute attr)
{
	if (!Widget::init())
		return false;

	do
	{
		m_attr = attr;
		
		auto csb_node = CSLoader::createNode(csb_config.attr_cell);
		CC_BREAK_IF(csb_node == nullptr);
		m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));
		CC_BREAK_IF(m_root == nullptr);
		m_root->removeFromParentAndCleanup(false);
		addChild(m_root);

		setContentSize(m_root->getContentSize());

		updateDraw();

		return true;
	} while (false);

	return false;
}

void AttrCell::updateDraw()
{
	Text *Text_attr_name = dynamic_cast<Text *>(Helper::seekWidgetByName(m_root, "Text_attr_name"));
	Text *Text_attr_value = dynamic_cast<Text *>(Helper::seekWidgetByName(m_root, "Text_attr_value"));

	Text_attr_name->setString(m_attr.typeToString());
	Text_attr_value->setString(m_attr.valueToString());
}

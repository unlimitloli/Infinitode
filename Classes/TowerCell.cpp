#include "TowerCell.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

TowerCell * TowerCell::createWithId(int tower_id)
{
	auto tower_cell = new TowerCell();
	if (tower_cell && tower_cell->initWithId(tower_id))
	{
		tower_cell->autorelease();
		return tower_cell;
	}
	else
	{
		CC_SAFE_DELETE(tower_cell);
		return nullptr;
	}
	return nullptr;
}

bool TowerCell::initWithId(int tower_id)
{
	if (!Node::init())
		return false;

	do
	{
		auto csb_node = CSLoader::createNode(csb_config.tower_cell);
		CC_BREAK_IF(csb_node == nullptr);
		m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));
		CC_BREAK_IF(m_root == nullptr);
		addChild(m_root);

		m_tower_id = tower_id;

		updateDraw();
	} while (false);

	return true;
}

void TowerCell::updateDraw()
{
	Sprite *Sprite_tower = dynamic_cast<Sprite *>(m_root->getChildByName("Sprite_tower"));
	ImageView *Image_select = dynamic_cast<ImageView *>(m_root->getChildByName("Image_select"));
	Text *Text_gold = dynamic_cast<Text *>(m_root->getChildByName("Text_gold"));

	if (m_is_lock == false)
	{

	}
}

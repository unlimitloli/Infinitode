#include "TowerCell.h"
#include "GameManager.h"
#include "MenuLayer.h"

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
		m_tower_id = tower_id;

		auto csb_node = CSLoader::createNode(csb_config.tower_cell);
		CC_BREAK_IF(csb_node == nullptr);
		m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));
		CC_BREAK_IF(m_root == nullptr);
		m_root->removeFromParentAndCleanup(false);
		addChild(m_root);
		
		setContentSize(m_root->getContentSize());
		setAnchorPoint(Vec2::ZERO);
		m_root->setPosition(Vec2::ZERO);

		m_root->addTouchEventListener([&](cocos2d::Ref *sender, cocos2d::ui::Widget::TouchEventType type) {
			if (type == Widget::TouchEventType::ENDED)
			{
				_game->getMenuLayer()->selectTower(m_tower_id);
			}
		});

		updateDraw();
	} while (false);

	return true;
}

void TowerCell::updateDraw()
{
	Sprite *Sprite_tower = dynamic_cast<Sprite *>(m_root->getChildByName("Sprite_tower"));
	ImageView *Image_select = dynamic_cast<ImageView *>(m_root->getChildByName("Image_select"));
	Text *Text_gold = dynamic_cast<Text *>(m_root->getChildByName("Text_gold"));
	Image_select->setVisible(false);
	Text_gold->setString("");

	int pic = _config->getData("tower_config").getInt(m_tower_id, (int)tower_config::pic);
	std::string cost = _config->getData("tower_config").getString(m_tower_id, (int)tower_config::build_cost);
	Sprite_tower->setTexture(StringUtils::format("images/tower/tower_%d.png", pic));
	Text_gold->setString(cost);

	if (m_is_lock == false)
	{
		
	}
}

void TowerCell::setSelected(bool flag)
{
	ImageView *Image_select = dynamic_cast<ImageView *>(m_root->getChildByName("Image_select"));
	Image_select->setVisible(flag);
}

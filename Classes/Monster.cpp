#include "Monster.h"
#include "SimpleMoveControl.h"
#include "MonsterManager.h"
#include "MonsterMoveControl.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Monster * Monster::createWithId(int monster_id)
{
	auto monster = new Monster();
	if (monster && monster->initWithId(monster_id))
	{
		monster->autorelease();
		return monster;
	}
	else
	{
		CC_SAFE_DELETE(monster);
		return nullptr;
	}
	return nullptr;
}

bool Monster::initWithId(int monster_id)
{
	if (!Node::init())
		return false;

	do
	{
		m_monster_id = monster_id;

		auto csb_node = CSLoader::createNode(csb_config.monster_cell);
		CC_BREAK_IF(csb_node == nullptr);
		m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));
		CC_BREAK_IF(m_root == nullptr);
		m_root->removeFromParentAndCleanup(false);
		addChild(m_root);

		setContentSize(m_root->getContentSize());
		setAnchorPoint(Vec2(0.5f, 0.5f));

		updateDraw();
		return true;
	} while (false);

	return false;
}

void Monster::updateDraw()
{
	if (m_monster_id == 0)
		return;

	Sprite *Sprite_monster = dynamic_cast<Sprite *>(m_root->getChildByName("Sprite_monster"));
	int pic = _config_int("monster_config", m_monster_id, monster_config::pic);

	Sprite_monster->setTexture(StringUtils::format("images/monster/monster_%d.png", pic));
}

void Monster::reload(int monster_id)
{
	m_monster_id = monster_id;
	m_is_alive = true;
	updateDraw();
}

void Monster::unload()
{
	m_is_alive = false;
	clearUI();
}

void Monster::clearUI()
{
	Sprite *Sprite_monster = dynamic_cast<Sprite *>(m_root->getChildByName("Sprite_monster"));
	ListView *ListView_buff = dynamic_cast<ListView *>(m_root->getChildByName("ListView_buff"));

	ListView_buff->removeAllItems();
}

void Monster::runWithPath(const std::vector<cocos2d::Vec2>& path, MoveControlProtocol::TRANSFORM_FUNC tranform)
{
	m_path = path;
	m_move_control = new MonsterMoveControl(this);
	m_move_control->startWithPath(path, tranform);
	m_move_control->setSpeed(20.0f);
}

void Monster::moveToNext(float dt)
{
	if (m_move_control != nullptr)
	{
		m_move_control->move(dt);
	}
}

bool Monster::isAlive() const
{
	return m_is_alive;
}

bool Monster::checkHit(const cocos2d::Vec2 & pos)
{
	auto rect = getBoundingBox();
	if (rect.containsPoint(pos))
		return true;
	return false;
}

void Monster::rotateToAngle(float angle, float dt)
{
	Sprite *Sprite_monster = dynamic_cast<Sprite *>(m_root->getChildByName("Sprite_monster"));
	if (dt > 0)
		Sprite_monster->runAction(RotateTo::create(0.2f, angle));
	else
		Sprite_monster->setRotation(angle);
}

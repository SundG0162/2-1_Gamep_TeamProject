#include "Crossbow.h"
#include"Cell.h"
#include"MapManager.h"

Crossbow::Crossbow(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

Crossbow::~Crossbow()
{
}

vector<Enemy*> Crossbow::defineTargets()
{
	/*vector<Enemy*> targetVec;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
	int maxCount = 0;
	Vector2 attackCellPos = Vector2();
	for (int i = y; i < y + _attackRange; i++)
	{
		for (int j = x; j < x + _attackRange; j++)
		{
			Vector2 pos = Vector2(j, i);
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			if (cell->type == MAP_TYPE::ROAD)
			{
				vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
				if (maxCount <= vec.front()->getMoveCount())
				{
					attackCellPos = pos;
				}
			}
		}
	}
	targetVec.push_back(GET_SINGLETON(MapManager)->
		getCell(attackCellPos)->
		getEntities<Enemy>(ENTITY_TYPE::ENEMY).front());
	return targetVec;*/
	vector<Enemy*> targetVec;
	Enemy* target = nullptr;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
	for (int i = y; i < y + _attackRange; i++)
	{
		for (int j = x; j < x + _attackRange; j++)
		{
			Vector2 pos = Vector2(j, i);
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			if (cell->type == MAP_TYPE::ROAD)
			{
				vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
				for (auto i : vec)
				{
					if (target == nullptr)
					{
						target = i;
						continue;
					}
					if (target->getMoveCount() < i->getMoveCount())
					{
						target = i;
					}
				}
			}
		}
	}
	if (target != nullptr)
		targetVec.push_back(target);
	return targetVec;
}

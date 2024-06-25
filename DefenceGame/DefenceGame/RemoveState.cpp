#include "RemoveState.h"
#include"EntityManager.h"
#include"MapManager.h"
#include"Player.h"
RemoveState::RemoveState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void RemoveState::update()
{
	_currentMousePos = GET_SINGLETON(MapManager)->consolePosToCellPos(getMousePos());

	if (getMouseInput())
	{
		Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
		bool isValid = isInMap(_currentMousePos) && !isCellEmpty() && cell->type == MAP_TYPE::PLACE;
		if (isValid)
		{
			Ally* ally = cell->getEntities<Ally>(ENTITY_TYPE::ALLY).front();
			if (ally != nullptr)
			{
				GET_SINGLETON(EntityManager)->despawnEntity(ally);
				_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
			}
		}
	}
	if (keyController() == KEY::ESC)
	{
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
	}
}

void RemoveState::render()
{
	gotoxy(40, 0);
	cout << "���ϴ� ���� ���콺�� Ŭ���Ͽ� �Ʊ��� �����ϼ���.";
	gotoxy(43, 1);
	cout << "���� ������ ��ġ���� �÷� ǥ�õ˴ϴ�.";

	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	bool isValid = isInMap(_currentMousePos) && !isCellEmpty() && cell->type == MAP_TYPE::PLACE;
	if (isValid)
	{
		setColor((int)COLOR::RED, (int)cell->bgColor);
		gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
		cout << "��";
		setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	}
}

bool RemoveState::isInMap(const Vector2& pos)
{
	bool isXIn = _currentMousePos.x >= 0 && _currentMousePos.x < MAP_WIDTH;
	bool isYIn = _currentMousePos.y >= 0 && _currentMousePos.y < MAP_HEIGHT;
	return isYIn && isXIn;
}

bool RemoveState::isCellEmpty()
{
	return GET_SINGLETON(MapManager)->getCell(_currentMousePos)->getEntities().size() == 0;
}

#include "PlaceState.h"
#include"Vector2.h"
#include<Windows.h>
#include"MapManager.h"
#include"Define.h"
#include"Player.h"
#include"EntityManager.h"


PlaceState::PlaceState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void PlaceState::update()
{
	_currentMousePos = GET_SINGLETON(MapManager)->consolePosToCellPos(getMousePos());

	if (getMouseInput())
	{
		if (!isInMap(_currentMousePos)) return;
		if (!isCellEmpty()) return;
		Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
		if (cell->type != MAP_TYPE::PLACE)
			return;
		GET_SINGLETON(Player)->getAlly()->setPos(_currentMousePos);
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
	}

	if (keyController() == KEY::ESC)
	{
		GET_SINGLETON(EntityManager)->despawnEntity(GET_SINGLETON(Player)->getAlly());
		_inGameScene->changeState(INGAMESCENE_STATE::SELECT);
	}
}

void PlaceState::render()
{
	gotoxy(40, 0);
	cout << "���ϴ� ���� ���콺�� Ŭ���Ͽ� �Ʊ��� ��ġ�ϼ���.";
	gotoxy(43, 1);
	cout << "��ġ ������ ��ġ���� �ڷ� ǥ�õ˴ϴ�.";
	if (!isInMap(_currentMousePos)) return;
	if (!isCellEmpty()) return;
	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	if (cell->type != MAP_TYPE::PLACE)
		return;
	setColor((int)COLOR::BLACK, (int)cell->bgColor);
	gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
	cout << "��";
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}
bool PlaceState::isInMap(const Vector2& pos)
{
	bool isXIn = _currentMousePos.x >= 0 && _currentMousePos.x < MAP_WIDTH;
	bool isYIn = _currentMousePos.y >= 0 && _currentMousePos.y < MAP_HEIGHT;
	return isYIn && isXIn;
}

bool PlaceState::isCellEmpty()
{
	return GET_SINGLETON(MapManager)->getCell(_currentMousePos)->getEntities().size() == 0;
}
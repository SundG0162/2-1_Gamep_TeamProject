#include "IdleState.h"
#include"InGameScene.h"
#include<conio.h>
#include"console.h"
#include"WaveManager.h"

IdleState::IdleState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void IdleState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::ONE:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::SELECT);
		break;
	}
	case KEY::TWO:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::REMOVE);
		break;
	}
	case KEY::THREE:
	{
		GET_SINGLETON(WaveManager)->nextWave();
		break;
	}
	case KEY::FOUR:
	{
		break;
	}
	}
}

void IdleState::render()
{
	gotoxy(27, 27);
	cout << "(1) �Ʊ� ���\t\t(2)�Ʊ� ����\t\t(3) ���� ����!\t\t";
}
#include "IdleState.h"
#include "InGameScene.h"
#include<conio.h>
#include "console.h"
#include "WaveManager.h"
#include "SceneManager.h"

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
		_inGameScene->changeState(INGAMESCENE_STATE::BATTLE);
		GET_SINGLETON(WaveManager)->nextWave();
		break;
	}
	case KEY::FOUR:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::ASK);
		break;
	}
	}
}

void IdleState::render()
{
	gotoxy(49, 0);
	cout << " ���� ���̺� :  " << GET_SINGLETON(WaveManager)->getCurrentWave() + 1;
	gotoxy(22, 27);
	cout << "(1) �Ʊ� ���\t\t(2) �Ʊ� ����\t\t(3) ���� ����!\t\t(4) ���� ����";
}
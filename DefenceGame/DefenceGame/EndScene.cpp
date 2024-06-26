#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"
#include "Player.h"

using namespace std;

EndScene::EndScene() {}

EndScene::~EndScene() {}

void EndScene::render()
{
    cout << "��ƾ ���̺� : " << WaveManager::getInstance()->getCurrentWave() << endl;
    cout << "���� ��� : " << GET_SINGLETON(Player)->getGold() << endl;
}

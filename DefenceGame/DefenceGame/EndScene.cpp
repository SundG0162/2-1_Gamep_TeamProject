#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"

EndScene::EndScene() {}

EndScene::~EndScene() {}

void EndScene::render() {
    std::cout << "���� ���̺�: " << WaveManager::getInstance()->getCurrentWave() << std::endl;
}

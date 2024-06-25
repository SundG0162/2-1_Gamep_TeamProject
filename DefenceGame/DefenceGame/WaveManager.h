#pragma once
#include"Define.h"
#include"WaveInfo.h"
class WaveManager
{
	DECLARE_SINGLETON(WaveManager)
public:
	void init();
public:
	void nextWave();
	void spawnEnemy();
private:
	vector<WaveInfo> _waveInfoVec;
	ENEMY_TYPE _currentSpawnEnemy = ENEMY_TYPE::GOBLIN;
	ROAD_TYPE _spawnRoad = ROAD_TYPE::FIRST;
	int _leftSpawnEnemy = 0;
	int _currentWave = -1;
	int _spawnDelay = 800;
	clock_t _lastSpawnTime = 0;
	clock_t _spawnTimer = 0;
};


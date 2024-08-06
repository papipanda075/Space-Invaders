#include "Enemyservice.h"
#include"../ENEMY/EnemyController.h"
namespace Enemy {
	void Enemy::EnemyService::Destroy()
	{
		delete(enemy);
	}

	Enemy::EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	Enemy::EnemyService::~EnemyService()
	{
		Destroy();

	}

	void Enemy::EnemyService::initialize()
	{
		spawnEnemy();
	}

	void Enemy::EnemyService::update()
	{
		enemy->update();
	}

	void Enemy::EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* Enemy::EnemyService::spawnEnemy()
	{
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}
}
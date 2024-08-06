#include "EnemyController.h"
#include"../../ENEMY/EnemyModel.h"
#include"../../ENEMY/EnemyView.h"
#include"../../Headers/Global/ServiceLocator.h"
namespace Enemy {

	using namespace Global;
	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
		
	}
	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}
	void Enemy::EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this); // we will discuss this soo
	}

	void Enemy::EnemyController::update()
	{
		enemy_view->update();
	}

	void Enemy::EnemyController::render()
	{
		enemy_view->render();
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();

	}
}
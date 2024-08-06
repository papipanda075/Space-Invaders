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
		move();
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
	void EnemyController::move()
	{
		switch (enemy_model->getmovementdirection())
		{
		case MovementDirection::LEFT:
			moveLeft();
			break;
		case MovementDirection::RIGHT:
			moveRight();
			break;
		case MovementDirection::DOWN:
			moveDown();
			break;
		}

	}
	void EnemyController::moveLeft()
	{
		sf::Vector2f currentposition = enemy_model->getEnemyPosition();
		currentposition.x -= enemy_model->movement_speed * ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
		if (currentposition.x <= enemy_model->left_most.x) {
			enemy_model->setmovementdirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentposition);
		}
		else {
			enemy_model->setEnemyPosition(currentposition);
		}
	}
	void EnemyController::moveRight()
	{
		sf::Vector2f currentposition = enemy_model->getEnemyPosition();
		currentposition.x += enemy_model->movement_speed * ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
		if (currentposition.x >= enemy_model->right_most.x) {
			enemy_model->setmovementdirection(MovementDirection::DOWN);
			enemy_model->setEnemyPosition(currentposition);
		}
		else {
			enemy_model->setEnemyPosition(currentposition);

		}
	}
	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += enemy_model->movement_speed * ServiceLocator::getInstance()->gettimeservice()->getdeltatime();

		//check if enemy has moved the specified distance downwards
		if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->downward_distance)
		{

			if (enemy_model->getReferencePosition().x >= enemy_model->right_most.x) {

				enemy_model->setmovementdirection(MovementDirection::LEFT);

			}
			else {

				enemy_model->setmovementdirection(MovementDirection::RIGHT);
			}


		}
		else {
			enemy_model->setEnemyPosition(currentPosition);
		}


	}
}
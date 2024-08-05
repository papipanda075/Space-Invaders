#include"../../Enemy/EnemyController.h"
#include"../../Enemy/EnemyModel.h"
#include"../../Enemy/EnemyView.h"
namespace enemy {
	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyMode();
	 
	}
	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}
	void EnemyController::initialize()
	{
		enemy_model->intialize();
		enemy_view->intialize(this);
	}
	void EnemyController::update()
	{
		enemy_view->update();
	}
	void EnemyController::render()
	{
		enemy_view->render();
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getenemytposition();
	}
}
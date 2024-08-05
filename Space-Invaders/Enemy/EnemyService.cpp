#include"../../Enemy/Enemyservice.h"
#include"../../Enemy/EnemyController.h"
#include"../../Enemy/EnemyModel.h"
#include"../../Enemy/EnemyView.h"
#include"../../Headers/Global/ServiceLocator.h"
namespace enemy {
	using namespace Global;



	void EnemyService::destroy()
	{
		delete(Enemy);
	}

	enemy::EnemyService::EnemyService()
	{
		Enemy = nullptr;

	}


	enemy::EnemyService::~EnemyService()
	{
		Enemy = new EnemyController();
		destroy();
	}

	void enemy::EnemyService::intialize()
	{
		spawnenemy();
	}

	void enemy::EnemyService::update()
	{

	}

	void enemy::EnemyService::render()
	{
		Enemy->render();
	}

	EnemyController* EnemyService::spawnenemy()
	{
		
		Enemy->initialize();
		return Enemy;
	}



	

}
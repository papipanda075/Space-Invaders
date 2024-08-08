#include "GameplayService.H"
#include"../../Gameplay/GameplayController.h"
namespace Gameplay {
	Gameplay::GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	Gameplay::GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}

	void Gameplay::GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void Gameplay::GameplayService::update()
	{
		gameplay_controller->update();
	}

	void Gameplay::GameplayService::render()
	{
		gameplay_controller->render();
	}
}
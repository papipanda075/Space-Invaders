#include "GameplayController.h"
#include"../../Gameplay/GameplayView.H"
namespace Gameplay {
	Gameplay::GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView();
	}

	Gameplay::GameplayController::~GameplayController()
	{
		delete(gameplay_view);
		
	}

	void Gameplay::GameplayController::initialize()
	{
		gameplay_view->initialize();
	}

	void Gameplay::GameplayController::update()
	{
		gameplay_view->update();
	}

	void Gameplay::GameplayController::render()
	{
		gameplay_view->render();
	}
}
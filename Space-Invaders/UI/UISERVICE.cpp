#include "UISERVICE.h"
#include"../../Headers/main/GameService.h"
namespace UI {
	using namespace Main;
	using namespace MainMenu;
	void UI::UiService::createControllers()
	{
		main_menu_controller = new MainMenuUI();
	}

	void UI::UiService::intializecontrollers()
	{
		main_menu_controller->intialize();
	}

	void UI::UiService::destroycontrollers()
	{
		delete(main_menu_controller);
	}

	UI::UiService::UiService()
	{
		main_menu_controller = nullptr;
		createControllers();
	}

	UI::UiService::~UiService()
	{
		destroycontrollers();
	}

	void UI::UiService::intialize()
	{

		

		main_menu_controller->intialize();
		intializecontrollers();



	}

	void UI::UiService::update()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->update();
			break;
		}
	}

	void UI::UiService::render()
	{
		

		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->render();
			break;
		}
	}
}
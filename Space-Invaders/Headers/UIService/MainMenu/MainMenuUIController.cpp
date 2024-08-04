#include "MainMenuUIController.h"
#include"../../Headers/main/GameService.h"
#include"../../Headers/Global/ServiceLocator.h"
#include"../../Headers/Graphic/GraphicService.h"

namespace UI {
	namespace MainMenu {

		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace event;

		UI::MainMenu::MainMenuUIController::MainMenuUIController()
		{
			game_window = nullptr;
		}

		void UI::MainMenu::MainMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}

		void UI::MainMenu::MainMenuUIController::update()
		{
		}

		void UI::MainMenu::MainMenuUIController::render()
		{
		}
	}
}
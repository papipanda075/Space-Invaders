#include "UIService.h"
#include"../main/GameService.h"



using namespace Main;
using namespace MainMenu;


void UI::UiService::createControllers()
{
	main_menu_controller = new MainMenuUIController();
}

void UI::UiService::initializeControllers()
{
	main_menu_controller->initialize();
}

void UI::UiService::destroy()
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
	destroy();
}

void UI::UiService::initialize()
{
	initializeControllers();
}

void UI::UiService::update()
{
}

void UI::UiService::render()
{
}

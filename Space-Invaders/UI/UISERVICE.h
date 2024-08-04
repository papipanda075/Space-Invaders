#pragma once
#include"../../UI/MainMenu/MainMenuUIController.h"
namespace UI {
	class UiService {

	private:
		void createControllers();
		void intializecontrollers();
		void destroycontrollers();
		MainMenu::MainMenuUI* main_menu_controller;
	public:
		UiService();
		~UiService();
		void intialize();
		void update();
		void render();
	};

}
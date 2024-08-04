#pragma once
#include"../../Headers/UIService/MainMenu/MainMenuUIController.h"
namespace UI{
	class UiService {
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UiService();
		~UiService();

		void initialize();
		void update();
		void render();

	};
}
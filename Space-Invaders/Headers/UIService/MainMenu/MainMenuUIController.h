#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:

			sf::RenderWindow* game_window;

		public:
			MainMenuUIController();

			void initialize();
			void update();
			void render();

		};
	}
}
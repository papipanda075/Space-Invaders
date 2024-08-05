#pragma once

#include <SFML/Graphics.hpp>
#include"../Global/ServiceLocator.h"
enum class GameState //create the enum
{
	BOOT,
	MAIN_MENU,
	GAMEPLAY,
};


	

namespace Main {

	using namespace Global;
	using namespace Main;

	class GameService
	{
	private:


		static GameState current_state;

		ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();// Handles game initialization.
		void destroy();			// Handles cleanup tasks.

	public:

		GameService();			// Constructor for initializing the GameService object.
		~GameService();	// Destructor for cleaning up resources upon object deletion.

		void ignite();			// Initiates the game.
		void update();			// Updates the game logic and game state.
		void render();			// Renders each frame of the game.
		bool isRunning();// Checks if the game is currently running.
		static void setGameState(GameState new_state);
		static GameState getGameState();

		void showmainmenu();
	
	
	};
}
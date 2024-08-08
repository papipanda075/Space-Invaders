#pragma once
#include<SFML/Graphics.hpp>
namespace Gameplay {
	class GameplayController;

	class GameplayService {
	public:
		
		GameplayController* gameplay_controller;

	public:

		
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();


	};
}
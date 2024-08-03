#pragma once
#include<SFML/Graphics.hpp>
namespace player {

	enum class PlayerState;
	class PlayerView;
	class PlayerModel;

	class PlayerController {

	private:



		void processinput();
		void processmoveleft();
		void processmoveright();
	public:

		PlayerModel* model;
		PlayerView* view;
		PlayerController();
		~PlayerController();
		void intialize();
		void update();
		void render();




		sf::Vector2f getPlayerPosition();

	};

}
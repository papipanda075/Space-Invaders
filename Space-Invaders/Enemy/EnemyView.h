#pragma once
#include <SFML/Graphics.hpp>
namespace enemy {

	class EnemyController;
	class EnemyView{

		


	private:



		const sf::String enemy_texture_path = "assets/textures/enemy_ship.png";

		const float enemy_sprite_width = 100.f;
		const float enemy_sprite_height = 100.f;

		EnemyController* enemy_controller;

		sf::RenderWindow* game_window;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		void initializeEnemySprite();
		void scaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();
		void intialize(EnemyController* controller);
		void update();
		void render();
	};
}
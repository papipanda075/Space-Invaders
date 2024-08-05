#pragma once
#include <SFML/Graphics.hpp>
namespace enemy 
{
	
class EnemyView;
class EnemyMode; 
	class EnemyController {
	private:
		EnemyView* enemy_view;
		EnemyMode* enemy_model;

	public:

		EnemyController();
		~EnemyController();
		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
	};
}
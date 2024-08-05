#pragma once
#include<SFML/Graphics.hpp>
namespace enemy {
	class EnemyMode {

	private:
		sf::Vector2f enemypostion;
		sf::Vector2f reference_position = sf::Vector2f(0.f, 0.f);


	public:
		EnemyMode();
		~EnemyMode();
		void setenemyposition(sf::Vector2f pos);
		sf::Vector2f getenemytposition();
		void setrefgpos(sf::Vector2f spos);
		sf::Vector2f getrefpos();

		void intialize();
		void update();
		void render();
	};
}
#pragma once
#include<SFML/Graphics.hpp>
namespace enemy {
	class EnemyController;
	class EnemyService {
	private:
		EnemyController* Enemy;
		void destroy();
	public:
		EnemyService();
		virtual ~EnemyService();

		void intialize();
		void update();
		void render();
		EnemyController* spawnenemy();
	
	};
}
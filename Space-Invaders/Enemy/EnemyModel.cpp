#include"../../Enemy/EnemyModel.h"
namespace enemy {
	EnemyMode::EnemyMode()
	{
	}
	EnemyMode::~EnemyMode()
	{
	}
	void EnemyMode::setenemyposition(sf::Vector2f pos)
	{
		enemypostion = pos;
	}
	sf::Vector2f EnemyMode::getenemytposition()
	{
		return enemypostion;
	}
	void EnemyMode::setrefgpos(sf::Vector2f spos)
	{
		reference_position = spos;
	}
	sf::Vector2f EnemyMode::getrefpos()
	{
		return reference_position;
	}
	void EnemyMode::intialize()
	{
		enemypostion = reference_position;
	}

	void EnemyMode::update()
	{
	}

	void EnemyMode::render()
	{
	}
	
	}
	

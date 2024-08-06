#include "EnemyModel.h"
namespace Enemy {
	Enemy::EnemyModel::EnemyModel()
	{
		
	}

	Enemy::EnemyModel::~EnemyModel()
	{
		enemy_position = reference_position;
	}

	void Enemy::EnemyModel::initialize()
	{
		movement_direction = MovementDirection::RIGHT;
		enemy_position = reference_position;
	}

	sf::Vector2f Enemy::EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void Enemy::EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}

	sf::Vector2f Enemy::EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void Enemy::EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}
	MovementDirection EnemyModel::getmovementdirection()
	{
		return movement_direction;
	}
	void EnemyModel::setmovementdirection(MovementDirection direction)
	{
		movement_direction = direction;
	}
}
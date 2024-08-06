#include "EnemyView.h"
#include"../../Headers/Global/ServiceLocator.h"
#include"../../Headers/Graphic/GraphicService.h"
#include"../../ENEMY/EnemyController.h"
namespace Enemy {
	using namespace Global;
	using namespace Graphic;
	void Enemy::EnemyView::initializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path)) //check if the texture loaded
		{
			enemy_sprite.setTexture(enemy_texture); //set the sprite
			scaleEnemySprite(); // call the method to scale the sprite
		}
	}

	void Enemy::EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	Enemy::EnemyView::EnemyView()
	{
	}

	Enemy::EnemyView::~EnemyView()
	{
	}

	void Enemy::EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}

	void Enemy::EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void Enemy::EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
}
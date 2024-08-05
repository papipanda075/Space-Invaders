#include"../../Enemy/EnemyView.h"
#include"../../Headers/Graphic/GraphicService.h"
#include"../../Headers/main/GameService.h"
#include"../../Enemy/EnemyController.h"
namespace enemy {
	using namespace Global;
	using namespace Graphic;
	
	EnemyView::EnemyView()
	{
	}
	EnemyView::~EnemyView()
	{
	}
	void EnemyView::initializeEnemySprite() 
	{
		if (enemy_texture.loadFromFile("enemy_texture_path)")) {
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
	}
	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale(static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y);
	}

	void EnemyView::intialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}
	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}
	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
}
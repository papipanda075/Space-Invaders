//#include "../Headers/PlayerService.h"
//#include"../Headers/ServiceLocator.h"
//#include"../Headers/player/PlayerController.h"
#include"../Headers/Global/ServiceLocator.h"
#include"../Headers/player/PlayerService.h"
#include"../Headers/player/PlayerController.h"
#include"../Headers/EVENT/EventService.h"

namespace player {
	using namespace event;
	using namespace Global;
	
	
	void PlayerService::initializePlayerSprite()
	{
		if (player_texture.loadFromFile(player_texture_path)) {
			player_sprite.setTexture(player_texture);
		}
	}

	void PlayerService::processPlayerInput()
	{

		EventService* checkkey = ServiceLocator::getInstance()->getEventService();
		if (checkkey->isKeyboardEvent()) {
			if (checkkey->pressedLeftKey()) {
				moveLef();
			}

			if (checkkey->pressedRightKey()) {
				moveRight();
			}
		}
	}

	PlayerService::PlayerService()
	{
		game_window = nullptr;
		player_controller = new PlayerController;
	}

	PlayerService::~PlayerService()
	{
		delete player_controller;
	}

	void PlayerService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		player_controller->intialize();
		initializePlayerSprite();
	}

	void PlayerService::update()
	{
		processPlayerInput();
		player_controller->update();
		player_sprite.setPosition(getPlayerPosition());
	}

	void PlayerService::render()

	{
		player_controller->render();
		
	}

	void PlayerService::moveLef()
	{

		position.x -= ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
	}

	void PlayerService::moveRight()
	{

		position.x += ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
	}



	int PlayerService::getMoveSpeed()
	{
		return movement_speed;
	}

	sf::Vector2f PlayerService::getPlayerPosition()
	{
		return position;
	}
	
}
#include "PlayerService.h"
#include"ServiceLocator.h"


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
}

PlayerService::~PlayerService()
{
}

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
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

#include"../Headers/player/PlayerController.h"
#include"../Headers//EVENT/EventService.h"
#include"../Headers/Global/ServiceLocator.h"
#include"../Headers/player/PlayerModel.h"
#include"../Headers//player/PlayerView.h"
#include<algorithm>
namespace player{
	using namespace Global;
	void PlayerController::processinput()
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			processmoveright();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			processmoveleft();
		}
	}

	void PlayerController::processmoveleft()
	{

		sf::Vector2f current_position = model->getPlayerPosition();
		current_position.x -= model->player_movement_speed * ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
		current_position.x = std::max(current_position.x, model->left_most_position.x);
		model->setPlayerPosition(current_position);
	}


	void PlayerController::processmoveright()
	{
		sf::Vector2f current_position = model->getPlayerPosition();
		current_position.x += model->player_movement_speed * ServiceLocator::getInstance()->gettimeservice()->getdeltatime();
		current_position.x = std::min(current_position.x, model->right_most_position.x);
		model->setPlayerPosition(current_position);

	}

	PlayerController::PlayerController()
	{

		model = new PlayerModel();
		view = new PlayerView();
	}

	PlayerController::~PlayerController()
	{
		delete (view);
		delete (model);
	}

	void PlayerController::intialize()
	{
		model->initialize();
		view->initialize(this);
	}

	void PlayerController::update()
	{
		processinput();
		view->update();
	}

	void PlayerController::render()
	{
		view->render();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return model->getPlayerPosition();
	}
}

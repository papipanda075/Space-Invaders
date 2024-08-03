//#include"PlayerModel.h"
#include"../Headers/player/PlayerModel.h"
namespace player {

	PlayerModel::PlayerModel() { }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); }

	void PlayerModel::reset()
	{

		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	PlayerState PlayerModel::getplayerstate()
	{
		return player_state;
	}

	void PlayerModel::setplayerstate(PlayerState state)

	{
		player_state = state;

	}

}














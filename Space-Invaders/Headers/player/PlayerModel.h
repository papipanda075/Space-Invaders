#pragma once
#include <SFML/Graphics.hpp>


enum class PlayerState //Our Enum
{
    ALIVE,
    DEAD,
    // we will add more states later
};


class PlayerModel
{
private:

    const sf::Vector2f initial_player_position = sf::Vector2f(500.f, 500.f); //new var
    sf::Vector2f player_position; //new var
    PlayerState player_state;
   
    int player_score = 0;


public:
    const sf::Vector2f left_most_position = sf::Vector2f(50.f, 0.f);
    const sf::Vector2f right_most_position = sf::Vector2f(700.f, 0.f);

    const float player_movement_speed = 200.0f;

    PlayerModel();
    ~PlayerModel();

    void initialize();

    void reset(); //new method


   

    //getters and setters
    sf::Vector2f getPlayerPosition();
    void setPlayerPosition(sf::Vector2f position);

    PlayerState getplayerstate();

    
    void setplayerstate(PlayerState state);

    

};
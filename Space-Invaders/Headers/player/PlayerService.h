#pragma once
#include<SFML/Graphics.hpp>"
#include"../TIME/TimeService .h"
#include"../player/PlayerController.h"


namespace player {
    class PlayerService
    {



    private:



        int health = 3;
        sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
        float movement_speed = 5.0f;
        int player_score = 0;
        const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);

        const sf::String player_texture_path = "assets/textures/player_ship.png";

        sf::Texture player_texture;
        sf::Sprite player_sprite;

        sf::RenderWindow* game_window; //as always

        void initializePlayerSprite();
        void processPlayerInput();

        PlayerController* player_controller;
        

    public:


        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

        const float player_movement_speed = 350.0f;


        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();

        void moveLef();
        void moveRight();
        int getMoveSpeed();
        sf::Vector2f getPlayerPosition();

    };
}
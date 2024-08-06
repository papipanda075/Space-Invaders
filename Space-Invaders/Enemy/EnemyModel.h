#pragma once
#include<SFML/Graphics.hpp>
namespace Enemy {
    enum class MovementDirection {

        RIGHT,
        LEFT,
        DOWN,
    };

	class EnemyModel {

    private:
       
        MovementDirection movement_direction;
        

    public:
        EnemyModel();
        ~EnemyModel();


        sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemy_position;

       const float movement_speed = 250.f;
        const sf::Vector2f right_most = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f left_most = sf::Vector2f(50.f, 950.f);
        float downward_distance = 100.f;

        void initialize();

        sf::Vector2f getEnemyPosition();
        void setEnemyPosition(sf::Vector2f position);

        sf::Vector2f getReferencePosition();
        void setReferencePosition(sf::Vector2f position);

        MovementDirection getmovementdirection();
        void setmovementdirection(MovementDirection direction);
        

	};
}
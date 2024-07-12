#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Player {

private:

    int health;
    int playerscore;
    sf::Vector2f position;
public:
    sf::Texture texture;
    sf::Sprite sprite;


    void TakeDamage();
    void move();
    void shootbullets();

};
int main()
{
    return 0;
}
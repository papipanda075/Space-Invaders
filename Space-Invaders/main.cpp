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
    sf::VideoMode videomode = sf::VideoMode(1920, 1080);
    sf::RenderWindow window(videomode, "SPACE INVADER");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);

        Player One;
        One.texture.loadFromFile("assets/textures/player_ship.png");
        One.sprite.setTexture(One.texture);
        One.sprite.setPosition(960, 540);

        sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

        sf::Keyboard::isKeyPressed(sf::Keyboard::Left);


   
        window.draw(One.sprite);
        window.display();

    }

    return 0;
}
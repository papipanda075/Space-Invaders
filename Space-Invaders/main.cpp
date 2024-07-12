#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Player {

private:

    int health;
    int playerscore;
    int movement_speed = 5;
    sf::Vector2f position = sf::Vector2f(960,540);
public:
    sf::Texture texture;
    sf::Sprite sprite;


    void TakeDamage();
    void move(float offset) {
        position.x += offset;
    }
    void shootbullets();

    int getspeed() {
        return movement_speed;
   }

    sf::Vector2f getposition() {
        return position;
    }

};
int main()

{
    sf::VideoMode videomode = sf::VideoMode(1920, 1080);
    sf::RenderWindow window(videomode, "SPACE INVADER");



    Player One;
    One.texture.loadFromFile("assets/textures/player_ship.png");
    One.sprite.setTexture(One.texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);
;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            One.move(1.0 * One.getspeed());

        }
            
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            One.move(-1.0 * One.getspeed());
       }


        One.sprite.setPosition(One.getposition());
        window.draw(One.sprite);
        window.display();

    }

    return 0;
}
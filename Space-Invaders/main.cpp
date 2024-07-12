#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    sf::VideoMode video = sf::VideoMode(800, 600);
    sf::RenderWindow window(video, "SPACE INVADERS");
   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Black);

        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 300);

        sf::RectangleShape square(sf::Vector2f(100,100));
        square.setFillColor(sf::Color::Red);
        square.setPosition(1, 0);
        

        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        int size =100;
        triangle.setPoint(0, sf::Vector2f(0, 0)); // Top vertex
        triangle.setPoint(1, sf::Vector2f(size, 0)); // Bottom-right vertex
        triangle.setPoint(2, sf::Vector2f(size / 2.f, std::sqrt(3.f) / 2.f * size));
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(750-size/2,0);

        sf::Texture texture;
        texture.loadFromFile("assets/textures/outscal_logo.png");
        sf::Sprite spirite;
        spirite.setTexture(texture);
        spirite.setScale(0.5,0.5);
        spirite.setPosition(300,250);

        
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");

        sf::Text text("SFML is Awesome",font,50);
        text.setFillColor(sf::Color::White);
        text.setPosition(1, 0);

        // Display whatever you draw
        //window.draw(circle);
        //window.draw(square);
        //window.draw(triangle);
        window.draw(spirite);
        window.draw(text);
        window.display();
    }

 
    return 0;
}
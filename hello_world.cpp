/** 
 * sudo apt-get install libsfml-dev
 * sudo apt install build-essential
 * g++ -c hello_world.cpp
 * g++ hello_world.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 */

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Hello World!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
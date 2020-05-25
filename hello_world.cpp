/** 
 * sudo apt-get install libsfml-dev
 * sudo apt install build-essential
 * g++ -c hello_world.cpp
 * g++ hello_world.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;

#define WIN_WIDTH       300.f
#define WIN_HEIGHT      WIN_WIDTH
#define CIRCLE_RAD      ((WIN_WIDTH / 3) / 2)
#define RECT_WIDTH      (WIN_WIDTH / 3)
#define RECT_HEIGHT     RECT_WIDTH

Vector2f coords[] =
{
    // first row
    Vector2f(RECT_WIDTH * 0, RECT_WIDTH * 0),
    Vector2f(RECT_WIDTH * 1, RECT_WIDTH * 0),
    Vector2f(RECT_WIDTH * 2, RECT_WIDTH * 0),

    //second row
    Vector2f(RECT_WIDTH * 0, RECT_WIDTH * 1),
    Vector2f(RECT_WIDTH * 1, RECT_WIDTH * 1),
    Vector2f(RECT_WIDTH * 2, RECT_WIDTH * 1),

    //third row
    Vector2f(RECT_WIDTH * 0, RECT_WIDTH * 2),
    Vector2f(RECT_WIDTH * 1, RECT_WIDTH * 2),
    Vector2f(RECT_WIDTH * 2, RECT_WIDTH * 2),
};
const size_t coords_len = sizeof(coords) / sizeof(Vector2f);

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT),
        "Hello World!");
    
    CircleShape circle(CIRCLE_RAD);
    circle.setFillColor(Color::Blue);

    RectangleShape rect(Vector2f(RECT_WIDTH, RECT_HEIGHT));
    rect.setFillColor(Color::Red);

    uint32_t coord_idx = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Right)
                    {
                        coord_idx = (coord_idx + 1) % coords_len;
                    }
                    else { /* Some other key */ }
                    break;
            }
        }

        window.clear();

        rect.setPosition(coords[coord_idx]);
        window.draw(rect);        
        circle.setPosition(coords[coord_idx]);
        window.draw(circle);

        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <Simulation.h>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode( WIDTH, HEIGHT ), "Lissajous Curves");
    window.setFramerateLimit(60);

    sf::Font ubuntuFont;
    ubuntuFont.loadFromFile("Ubuntu-R.ttf");

    Simulation simulation(&ubuntuFont);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                simulation.onInput(event.key);
            }
        }

        //x = amplitude * sin ( omegaX*t+phiX );
        //y = amplitude * sin ( omegaY*t+phiY );

        //t+= 0.1f;

        //shape.setPosition(x+WIDTH/2.f,y+HEIGHT/2.f);
        //image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::White);

        simulation.update();

        window.clear();
        simulation.draw(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}

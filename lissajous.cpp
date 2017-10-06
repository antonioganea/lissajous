#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

const unsigned int WIDTH = 600;
const unsigned int HEIGHT = 600;

sf::Image image;
float t = M_PI;

float x, y;
float amplitude = 50.f;
float omegaX = 1.f, omegaY = 4.f;
float phiX = 0.f, phiY = 0.f;

float segment = M_PI;
float segsize = 0.2f;

void plot(){
    image.create(WIDTH,HEIGHT);
    for ( t = 0; t < M_PI*2.f; t+= 0.001f ){
        x = amplitude * sin ( omegaX*t+phiX );
        y = amplitude * sin ( omegaY*t+phiY );
        if ( abs( t - segment ) < segsize )
            image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::Red);
        else
            image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::White);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode( WIDTH, HEIGHT ), "Lissajous Curves");
    window.setFramerateLimit(60);
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(5.f,5.f);

    sf::Texture tex;
    plot();
    tex.loadFromImage(image);

    sf::RectangleShape background;
    background.setTexture(&tex, true);
    background.setSize((sf::Vector2f)image.getSize());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //x = amplitude * sin ( omegaX*t+phiX );
        //y = amplitude * sin ( omegaY*t+phiY );

        //t+= 0.1f;

        //shape.setPosition(x+WIDTH/2.f,y+HEIGHT/2.f);
        //image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::White);
        phiX+=0.01f;

        segment-= 0.02f;
        if ( segment < 0 )
            segment = M_PI*2.f;

        plot();
        tex.loadFromImage(image);

        window.clear();
        window.draw(background);
        //window.draw(shape);
        window.display();
    }

    return 0;
}

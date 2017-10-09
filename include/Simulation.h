#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#include "Config.h"

#define amplitude m_values[0]
#define omegaX m_values[1]
#define omegaY m_values[2]
#define phiX m_values[3]
#define phiY m_values[4]

class Simulation{
    public:
        Simulation( sf::Font * font );
        void plot();
        void update();
        void onInput( sf::Event::KeyEvent keyEvent );
        void draw ( sf::RenderWindow & window );

        float m_values[5];
    private:
        sf::Image image;
        sf::Texture tex;
        sf::RectangleShape background;
        float x, y, t;
        sf::Font * m_font;

        sf::Text m_text[5];
        char m_buffer[64];

        bool animatePhi;

        bool animateCircles;
        sf::CircleShape circles[3];
        float circle_t;

        //float segment = 0, segsize = 0.1f;
};

#endif // SIMULATION_H_INCLUDED

#include "Simulation.h"
#include <string>
#include <string.h>

const char m_textNames[5][16]={
    "Amplitude",
    "OmegaX",
    "OmegaY",
    "PhiX",
    "PhiY",
};

Simulation::Simulation( sf::Font * font ){
    m_font = font;
    plot();
    tex.loadFromImage(image);
    background.setTexture(&tex, true);
    background.setSize((sf::Vector2f)image.getSize());

    amplitude = 150.f;
    omegaX = 3.f;
    omegaY = 5.f;
    phiX = 0.f;
    phiY = 0.f;

    animatePhi = false;

    //sf::Text phiX, phiY, omegaX, omegaY, amplitude;
    for ( int i = 0; i < 5; i++ ){
        m_text[i].setFont( *m_font );
        m_text[i].setPosition(0,i*25);
        m_text[i].setCharacterSize(20);
        m_text[i].setColor( sf::Color(64,64,64) );
        strcpy( m_buffer, m_textNames[i] );
        strcpy( m_buffer+strlen(m_buffer), " = " );
        strcpy( m_buffer+strlen(m_buffer), std::to_string(m_values[i]).c_str() );
        m_text[i].setString(m_buffer);
    }
}

void Simulation::plot(){
    image.create(WIDTH,HEIGHT);
    for ( t = 0; t < M_PI*2.f; t+= 0.001f ){
        x = amplitude * sin ( omegaX*t+phiX );
        y = amplitude * sin ( omegaY*t+phiY );

        /*
        float compensate = segment + M_PI;
        if ( compensate >= M_PI*2.f )
            compensate -= M_PI*2.f;

        if ( abs( t - segment ) < segsize )
            image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::Red);
        else if ( abs ( t - compensate ) < segsize )
            image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::Blue);
        else
        */
        image.setPixel(x+WIDTH/2.f,y+HEIGHT/2.f,sf::Color::White);
    }
}

void Simulation::onInput(sf::Event::KeyEvent keyEvent){
    switch( keyEvent.code ){
        case sf::Keyboard::A:
            omegaX-=1.0f;
            break;
        case sf::Keyboard::S:
            omegaX+=1.0f;
            break;
        case sf::Keyboard::Z:
            omegaY-=1.0f;
            break;
        case sf::Keyboard::X:
            omegaY+=1.0f;
            break;
        case sf::Keyboard::Q:
            amplitude-=1.0f;
            break;
        case sf::Keyboard::W:
            amplitude+=1.0f;
            break;
        case sf::Keyboard::C:
            phiX-=0.01f;
            if ( phiX < 0 )
                phiX += M_PI*2.f;
            break;
        case sf::Keyboard::V:
            phiX+=0.01f;
            if ( phiX > 0 )
                phiX -= M_PI*2.f;
            break;
        case sf::Keyboard::D:
            phiY-=0.01f;
            if ( phiY < 0 )
                phiY += M_PI*2.f;
            break;
        case sf::Keyboard::F:
            phiY+=0.01f;
            if ( phiY > 0 )
                phiY -= M_PI*2.f;
            break;
        case sf::Keyboard::R:
            animatePhi = !animatePhi;
            break;
        case sf::Keyboard::T:
            phiX = phiY = 0;
            break;
        default:;
    }
}


void Simulation::update(){
    if ( animatePhi ){
        phiX+=0.01f;
        if ( phiX >= M_PI*2.f )
            phiX -= M_PI*2.f;
    }

    /*
    segment-= 0.02f;
    if ( segment < 0 )
        segment = M_PI*2.f;
    */

    for ( int i = 0; i < 5; i++ ){
        strcpy( m_buffer, m_textNames[i] );
        strcpy( m_buffer+strlen(m_buffer), " = " );
        strcpy( m_buffer+strlen(m_buffer), std::to_string(m_values[i]).c_str() );
        m_text[i].setString(m_buffer);
    }

    plot();
    tex.loadFromImage(image);
}

void Simulation::draw(sf::RenderWindow& window){
    window.draw( background );
    for ( int i = 0; i < 5; i++ ){
        window.draw(m_text[i]);
    }
}


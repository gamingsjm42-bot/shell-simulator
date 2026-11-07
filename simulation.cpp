//includes
#include <SFML/Graphics.hpp>
#include "physiques/velocity.h"
#include <iostream>
#include "math/productScalar.h"
//constanses
const int earthLength = 30;
//
int main()
{
    //set mouse Point
    Point<float> mousePoint = {0,0}, O(0,0), circlePoint(0,0);
    //
    float h = 1;
    //set dt & clock
    sf::Time dt;
    sf::Clock clk;
    sf::Time t;
    bool isOpened = false;
    //set angel var
    float angel = 21;
    //set ball event
    sf::CircleShape circle(30);
    //set properties
    circle.setFillColor(sf::Color::Red);
    circle.setPosition({100,900});
    //
    sf::RenderWindow window(sf::VideoMode({1920,1080},32),"shell simulation",sf::State::Fullscreen);
    //set is open window
    while (window.isOpen())
    {
        //refresh values
        mousePoint  = Point<float>(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
        circlePoint = Point<float>(circle.getPosition().x,circle.getPosition().y);
        Vector<float> d = {mousePoint,circlePoint};
        //fix variable angel
        if(!isOpened)
        //set first open
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&&!isOpened) 
        {
            //open text
            isOpened = true;
            //
            clk.restart(); 
            //
            h = abs(Vector<float>(circlePoint,mousePoint)); 
        }
        //angel = Angel<float>(O,mousePoint,circlePoint);
        //set dt as delta time
        dt =clk.getElapsedTime() -t;
        //set t
        t = clk.getElapsedTime();
        // 
        //set  event
        while (std::optional<sf::Event> event =window.pollEvent())
        {
            //set exit window
            if(event->getIf<sf::Event::Closed>()) window.close();
        } 
        if(isOpened) 
        {
            
            //moove
            circle.move({dt.asSeconds()*Vx(t.asSeconds(),std::sqrtf(2*g*h),angel),-dt.asSeconds()*Vy(t.asSeconds(),std::sqrtf(2*g*h),angel)});
        }
        //update var
        else
        {
        angel =std::atan2(d.y,d.x);
        }
        //set drqw function
        window.clear(sf::Color::Green);
        window.draw(circle); 
        //set draw events
        window.display();  
    }
    
}
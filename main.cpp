#include <chrono>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "MainCharacter.hpp"
#include "UI.hpp"
#include <ctime>

int main()
{
    sf::RenderWindow window;
    window.setFramerateLimit(120);
    window.create(sf::VideoMode(), "Game", sf::Style::Fullscreen);
    sf::View view(sf::FloatRect(0,0,1920,1080));//ogarnąć po powrocie

    maps ourMap = maps(120, 40);
    MainCharacter Character1 = MainCharacter();

    double deltaTime = 0.0;
    auto lastUpdateTime = std::chrono::high_resolution_clock::now();

    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.create(sf::VideoMode(1920, 1080), "Game");
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
      }

        deltaTime = std::chrono::duration<double>(std::chrono::high_resolution_clock::now()-lastUpdateTime).count();
        lastUpdateTime += (std::chrono::high_resolution_clock::now()-lastUpdateTime);


        if(Character1.deadChecking(window, ourMap)){
            Button * buttons = new Button[2]{{"Exit"},{"Restart"}};
            UI deadUI = UI(buttons, 2);
            deadUI.waitForUser(window, ourMap);
        }else {
            Character1.checkingKeyboard();
            Character1.fallSystem(ourMap.getCoordinates(), deltaTime, view, window);
            Character1.Moving(deltaTime, view, window);
            window.clear();
            ourMap.drawMap(window);
            Character1.drawCharacter(window);
            window.display();
        }
    }
    return 0;
}
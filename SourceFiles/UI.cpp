#include "../HeadersFiles/UI.hpp"
#include <iostream>

Button::Button(std::string _buttonName)
    :buttonName(_buttonName){
    textureToSprite[0].loadFromFile("../Assets/UI/Buttons/"+buttonName+"/1.png");
    textureToSprite[1].loadFromFile("../Assets/UI/Buttons/"+buttonName+"/2.png");
    buttonSprite.setTexture(textureToSprite[0]);
}

void Button::setPosition(int x, int y) {
    buttonSprite.setPosition(x, y);
}

void Button::drawButton(sf::RenderWindow & window) {
    window.draw(buttonSprite);

}

sf::Vector2i Button::getPosition() {
    sf::Vector2i toReturn;
    toReturn.x = buttonSprite.getPosition().x;
    toReturn.y = buttonSprite.getPosition().y;
    return toReturn;
}

void Button::changeTexture(int x) {
    buttonSprite.setTexture(textureToSprite[x]);
}

void Button::buttonFunctions(sf::RenderWindow&window) {

}

void Button::close(sf::RenderWindow&window) {
    window.close();
}

void Button::getOutFromWindow(sf::RenderWindow&window) {
    ON_OFF = false;
}

UI::UI(Button * _buttons, int _numberOfButtons)
    :buttons(_buttons), numberOfButtons(_numberOfButtons) {
    toSprite.loadFromFile("../Assets/UI/OwnWindow/window.png");
    ownWindow.setTexture(toSprite);
    toCursor.loadFromFile("../Assets/UI/Gears/Cursor.png");
    cursor.setTexture(toCursor);
    cursor.setPosition(1920/2, 1080/2);
    sf::Mouse::setPosition(sf::Vector2i(1920/2, 1080/2));
    ownWindow.setPosition(1920/2-400/2, 1080/2-640/2);
    for(int i = 0; i<numberOfButtons; ++i) {
        buttons[i].setPosition(1920/2-256/2, 266+i*210);
    }
    ON_OFF = true;
}

void UI::waitForUser(sf::RenderWindow & window, maps & ourMap) {
    while(ON_OFF) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        checkCursorPosition(window);
        isButtonPressed(window);
        window.clear();
        ourMap.drawMap(window);
        drawUI(window);
        window.display();
    }
}

void UI::drawUI(sf::RenderWindow & window) {
    window.draw(ownWindow);
    for(int i = 0; i<numberOfButtons; ++i) {
        buttons[i].drawButton(window);
    }
    window.draw(cursor);
}

void UI::checkCursorPosition(sf::RenderWindow & window) {
    if(sf::Mouse::getPosition(window).x < 1920/2 - 200 + 16) {
        sf::Mouse::setPosition(sf::Vector2i(1920/2 - 200 + 16, sf::Mouse::getPosition(window).y));
    }else if(sf::Mouse::getPosition(window).x > 1920/2 + 200 - 16) {
        sf::Mouse::setPosition(sf::Vector2i(1920/2 + 200 - 16, sf::Mouse::getPosition(window).y));
    }
    if(sf::Mouse::getPosition(window).y < 1080/2 - 320 + 16) {
        sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, 1080/2 - 320 + 16));
    }else if(sf::Mouse::getPosition(window).y > 1080/2 + 320 - 16) {
        sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, 1080/2 + 320 - 16));
    }
    cursor.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}

void UI::isButtonPressed(sf::RenderWindow & window) {
    for(int i = 0; i<numberOfButtons; ++i) {
        if(buttons[i].getPosition().x <= (sf::Mouse::getPosition().x+8) && (buttons[i].getPosition().x + 256) >= (sf::Mouse::getPosition().x-8) &&
            buttons[i].getPosition().y <= (sf::Mouse::getPosition().y+8) && (buttons[i].getPosition().y + 128) >= (sf::Mouse::getPosition().y-8)) {
            buttons[i].changeTexture(1);
        }else {
            buttons[i].changeTexture(0);
        }
    }
}




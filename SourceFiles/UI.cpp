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

void Button::buttonFunctions(sf::RenderWindow&window, UI * copyUI) {
    copyUI->ON_OFF = false; //tutaj problem
}

void Button::close(sf::RenderWindow&window) {
    window.close();
}

void Button::getOutFromWindow(sf::RenderWindow&window) {
}

UI::UI(Button * _buttons, int _numberOfButtons, sf::RenderWindow & window)
    :buttons(_buttons), numberOfButtons(_numberOfButtons) {
    toSprite.loadFromFile("../Assets/UI/OwnWindow/window.png");
    ownWindow.setTexture(toSprite);
    toCursor.loadFromFile("../Assets/UI/Gears/Cursor.png");
    cursor.setTexture(toCursor);
    cursor.setPosition(currenPosition.x + 1920/2, currenPosition.y + 1080/2);
    sf::Mouse::setPosition(sf::Vector2i(1920/2, 1080/2));
    ownWindow.setPosition(currenPosition.x + 1920/2-400/2, currenPosition.y + 1080/2-640/2);
    for(int i = 0; i<numberOfButtons; ++i) {
        buttons[i].setPosition(currenPosition.x + 1920/2-256/2, currenPosition.y + 266+i*210);
    }
    ON_OFF = true;
}

sf::Vector2f UI::currenPosition = sf::Vector2f(0,0);

void UI::waitForUser(sf::RenderWindow & window, maps & ourMap, UI * copyUI) {
    while(ON_OFF) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        checkCursorPosition(window);
        isButtonPressed(window, copyUI);
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
    cursor.setPosition(currenPosition.x+sf::Mouse::getPosition(window).x, currenPosition.y+sf::Mouse::getPosition(window).y);
}

void UI::isButtonPressed(sf::RenderWindow & window, UI * copyUI) {
    for(int i = 0; i<numberOfButtons; ++i) {
        if(buttons[i].getPosition().x - currenPosition.x <= (sf::Mouse::getPosition().x+8) && (buttons[i].getPosition().x - currenPosition.x + 256) >= (sf::Mouse::getPosition().x-8) &&
            buttons[i].getPosition().y -  currenPosition.y <= (sf::Mouse::getPosition().y+8) && (buttons[i].getPosition().y - currenPosition.y + 128) >= (sf::Mouse::getPosition().y-8)) {
            buttons[i].changeTexture(1);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                buttons[i].buttonFunctions(window,copyUI);
            }
        }else {
            buttons[i].changeTexture(0);
        }
    }
}






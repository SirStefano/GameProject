#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "./Map.hpp"
#include "./MainCharacter.hpp"

class UI;

class Button{
private:
    sf::Texture textureToSprite[2];
    sf::Sprite buttonSprite;
    std::string buttonName;

    void close(sf::RenderWindow & window);
    void getOutFromWindow(bool * toTurnOff);
public:
    Button(std::string _buttonName);
    void setPosition(int x, int y);
    void drawButton(sf::RenderWindow & window);
    sf::Vector2i getPosition();
    void changeTexture(int x);

    void buttonFunctions(sf::RenderWindow & window, UI * copyUI);
};

class UI{
private:
    Button * buttons;

    sf::Texture toSprite;
    sf::Sprite ownWindow;

    sf::Texture toCursor;
    sf::Sprite cursor;

    int numberOfButtons;

    bool ON_OFF;

    void isButtonPressed(sf::RenderWindow & window, UI * copyUI);

public:
    static sf::Vector2f currenPosition;

    UI(Button * _buttons, int _numberOfButtons, sf::RenderWindow & window);

    void waitForUser(sf::RenderWindow & window, maps & ourMap, UI * copyUI);
    void drawUI(sf::RenderWindow & window);
    void checkCursorPosition(sf::RenderWindow & window);

    void setBasics(sf::RenderWindow & window, sf::View & view, MainCharacter & character);

    friend void Button::buttonFunctions(sf::RenderWindow & window, UI * copyUI);
};
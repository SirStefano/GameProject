#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "./Map.hpp"

class Button{
private:
    sf::Texture textureToSprite[2];
    sf::Sprite buttonSprite;
    std::string buttonName;
public:
    Button(std::string _buttonName);
    void setPosition(int x, int y);
    void drawButton(sf::RenderWindow & window);
    sf::Vector2i getPosition();
    void changeTexture(int x);

    void buttonFunctions(sf::RenderWindow & window);
    void close(sf::RenderWindow & window);
    void getOutFromWindow(sf::RenderWindow & window);
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

    void isButtonPressed(sf::RenderWindow & window);

    friend void Button::buttonFunctions(sf::RenderWindow & window);
public:
    UI(Button * _buttons, int _numberOfButtons);
    void waitForUser(sf::RenderWindow & window, maps & ourMap);
    void drawUI(sf::RenderWindow & window);
    void checkCursorPosition(sf::RenderWindow & window);
};
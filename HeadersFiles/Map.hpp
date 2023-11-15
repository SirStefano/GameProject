#pragma once
#include <SFML/Graphics.hpp>

class maps{
private:
    int ** coordinates;
    int width;
    int height;
    sf::Texture titlesToSprite[24];
    sf::Sprite titles[24];
public:
    maps(int _width, int _height);
    ~maps();
    void drawMap(sf::RenderWindow & window);

    int ** getCoordinates();
};

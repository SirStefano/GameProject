#pragma once
#include <SFML/Graphics.hpp>
#include "./NPC.hpp"

class maps{
private:
    int ** coordinates;
    int width;
    int height;
    sf::Texture titlesToSprite[24];
    sf::Sprite titles[24];
    NPC crug;
public:
    maps(int _width, int _height, NPC _crug);
    ~maps();
    void drawMap(sf::RenderWindow & window, sf::Vector2f characterPosition);
    sf::Vector2f NPCpositionBroker();
    int ** getCoordinates();
};

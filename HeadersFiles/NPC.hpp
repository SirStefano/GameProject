#pragma once

class NPC {
private:
    sf::Texture walk[3];
    sf::Texture attack[4];
    sf:: Texture teleportBegin[8];
    sf:: Texture teleportEnd[8];
    sf::Texture dies[8];
    sf::Sprite creautre;
    int life = 10;
    int teleportStage;
    int moveNumber;
    void move(double dt);
    void teleport(sf::RenderWindow & window);
    bool collisionSystem(sf::Vector2f characterPosition);
public:
    NPC();
    void setPosition(int x, int y);
    void automaticlyMoving(sf::RenderWindow & window, sf::Vector2f characterPosition);
    void move();
    void dying();
    void drawNPC(sf::RenderWindow & window);
    sf::Vector2f getPosition();
};
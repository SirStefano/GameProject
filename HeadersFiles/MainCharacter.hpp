#pragma once
#include <SFML/Graphics.hpp>
#include <./Map.hpp>

class MainCharacter {
private:
    sf::Texture Basic;
    sf::Texture Attack[3];
    sf::Texture Crouching[3];
    sf::Texture Dodge[4];
    sf::Texture Dies[8];
    sf::Sprite MainCharacterS;

    int right; //całość do struktury zapewne
    int up;
    int left;
    int numberAttack;
    int numberCrouching;
    int numberDodge;

    void Move(sf::View & view, sf::RenderWindow & window, float x, float y);
    void AttackMove();
    void CrouchingMove();
    void DodgeMove();
    bool collisionSystem(int ** coordinates, bool x, bool y, sf::Vector2f crugPosition);

    bool isFallSystemWorking;
    int life;
public:
    MainCharacter();
    void drawCharacter(sf::RenderWindow & window);
    void checkingKeyboard();
    void Moving(double dt, sf::View & view, sf::RenderWindow & window, sf::Vector2f & changePosition, int ** coordinates, sf::Vector2f crugPosition); //trzeba by było cały obiekt map przerzucać, czas do zajęć (:
    void fallSystem(int ** coordinates, double dt, sf::View & view, sf::RenderWindow & window, sf::Vector2f & changePosition);
    bool deadChecking(sf::RenderWindow & window, maps & ourMap);
    void changeLife(int x);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
};
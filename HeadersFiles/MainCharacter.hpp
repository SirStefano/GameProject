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

    bool isFallSystemWorking;
    int life;
public:
    MainCharacter();
    void drawCharacter(sf::RenderWindow & window);
    void checkingKeyboard();
    void Moving(double dt, sf::View & view, sf::RenderWindow & window, sf::Vector2f & changePosition);
    void fallSystem(int ** coordinates, double dt, sf::View & view, sf::RenderWindow & window, sf::Vector2f & changePosition);
    bool deadChecking(sf::RenderWindow & window, maps & ourMap);
    void changeLife(int x);
    void setPosition(int x, int y);
};
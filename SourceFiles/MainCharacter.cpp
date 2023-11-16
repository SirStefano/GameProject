#include "../HeadersFiles/MainCharacter.hpp"
#include <iostream>
#include <string>
#include <chrono>

MainCharacter::MainCharacter() {
    Basic.loadFromFile("../Assets/Characters/MainCharacter/Basic/Basic.png");
    for(int i = 0; i<3; ++i) {
        Attack[i].loadFromFile("../Assets/Characters/MainCharacter/Attack/Attack"+std::to_string(i+1)+".png");
        Crouching[i].loadFromFile("../Assets/Characters/MainCharacter/Crouching/Crouching"+std::to_string(i+1)+".png");
    }
    for(int i = 0; i<4; ++i) {
        Dodge[i].loadFromFile("../Assets/Characters/MainCharacter/Dodge/Dodge"+std::to_string(i+1)+".png");
    }
    for(int i = 0; i<8; ++i) {
        Dies[i].loadFromFile("../Assets/Characters/MainCharacter/Dies/Dies"+std::to_string(i+1)+".png");
    }
    MainCharacterS.setTexture(Basic);
    MainCharacterS.setPosition(928, 8*64);

    right = 0;
    up = 0;
    left = 0;
    numberAttack = 0;
    numberCrouching = 0;

    isFallSystemWorking = false;
    life = 10;
}

void MainCharacter::drawCharacter(sf::RenderWindow & window) {
    window.draw(MainCharacterS);
}


void MainCharacter::checkingKeyboard() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        right++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && up == 0 && isFallSystemWorking == false) {
        up=1000;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //only for tests, later to delete
        left++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        numberAttack = 601;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        numberCrouching = 601;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        numberDodge = 801;
        life = 0;
    }
}

void MainCharacter::Moving(double dt, sf::View & view, sf::RenderWindow & window) {
    if(right >= 1) {
        Move(view, window, 100*dt, 0);
        right--;
    }
    if(up>0) {
        Move(view, window, 0, -(up*dt));
        up--;
    }
    if(left >= 1) {
        Move(view, window, -(100*dt),0);
        left--;
    }
    if(numberAttack>0) {
        AttackMove();
        numberAttack--;
    }else if(numberCrouching>0) {
        CrouchingMove();
        numberCrouching--;
    }else if(numberDodge>0) {
        DodgeMove();
        numberDodge--;
    }
}

void MainCharacter::Move(sf::View & view, sf::RenderWindow & window, float x, float y) {
    MainCharacterS.move(x, y);
    view.move(x, y);
    window.setView(view);
}

void MainCharacter::fallSystem(int ** coordinates, double dt, sf::View & view, sf::RenderWindow & window) {
    sf::Vector2f toTransfer = MainCharacterS.getPosition();
    int xBack = (((int)toTransfer.x)+15)/64;
    int xFront = (((int)toTransfer.x)+64-15)/64;
    int y = (((int)toTransfer.y+128)/64);
    if(coordinates[xBack][y]==414 && coordinates[xFront][y]==414) {
        isFallSystemWorking = true;
        MainCharacterS.move(0,200*dt);
        view.move(0, 200*dt);
        window.setView(view);
    }else {
        isFallSystemWorking = false;
    }
}

void MainCharacter::AttackMove() {
    if(numberAttack == 601 || numberAttack == 101) {
        MainCharacterS.setTexture(Attack[0]);
    }else if(numberAttack == 501 || numberAttack == 201) {
        MainCharacterS.setTexture(Attack[1]);
    }else if(numberAttack == 401) {
        MainCharacterS.setTexture(Attack[2]);
    }else if(numberAttack == 1) {
        MainCharacterS.setTexture(Basic);
    }
}

void MainCharacter::CrouchingMove() {
    if(numberCrouching == 601 || numberCrouching == 101) {
        MainCharacterS.setTexture(Crouching[0]);
    }else if(numberCrouching == 501 || numberCrouching == 201) {
        MainCharacterS.setTexture(Crouching[1]);
    }else if(numberCrouching == 401) {
        MainCharacterS.setTexture(Crouching[2]);
    }else if(numberCrouching == 1) {
        MainCharacterS.setTexture(Basic);
    }
}

void MainCharacter::DodgeMove() {
    if(numberDodge == 801 || numberDodge == 101) {
        MainCharacterS.setTexture(Dodge[0]);
    }else if(numberDodge == 701 || numberDodge == 201) {
        MainCharacterS.setTexture(Dodge[1]);
    }else if(numberDodge == 601 || numberDodge == 301) {
        MainCharacterS.setTexture(Dodge[2]);
    }else if(numberDodge == 501) {
        MainCharacterS.setTexture(Dodge[3]);
    }else if(numberDodge == 1) {
        MainCharacterS.setTexture(Basic);
    }
}

bool MainCharacter::deadChecking(sf::RenderWindow & window, maps & ourMap) {
    if(life == 0) {
        for(int i = 0; i<8; ++i) {
            MainCharacterS.setTexture(Dies[i]);
            _sleep(400);
            window.clear();
            ourMap.drawMap(window);
            drawCharacter(window);
            window.display();
        }
        _sleep(400);
        return true;
    }
    return false;
}

void MainCharacter::changeLife(int x) {
    life += x;
}













#include <SFML/Graphics.hpp>
#include "NPC.hpp"
#include <string>

NPC::NPC() {
    for(int i = 0; i<3; ++i) {
        walk[i].loadFromFile("../Assets/Characters/NPC/1/Walking/"+std::to_string(i+1)+".png");
    }
    for(int i = 0; i<4; ++i) {
        attack[i].loadFromFile("../Assets/Characters/NPC/1/Attack/"+std::to_string(i+1)+".png");
    }
    for(int i = 0; i<8; ++i) {
        teleportBegin[i].loadFromFile("../Assets/Characters/NPC/1/Teleport/Begin/"+std::to_string(i+1)+".png");
        teleportEnd[i].loadFromFile("../Assets/Characters/NPC/1/Teleport/End/"+std::to_string(i+1)+".png");
        dies[i].loadFromFile("../Assets/Characters/NPC/1/Dies/"+std::to_string(i+1)+".png");
    }
    creautre.setTexture(walk[0]);
    creautre.setPosition(3000,9*64);
    teleportStage = 0;
    moveNumber = 0;
}

void NPC::setPosition(int x, int y) {
    creautre.setPosition(x, y);
}

void NPC::automaticlyMoving(sf::RenderWindow & window, sf::Vector2f characterPosition) {
    if(teleportStage>0) {
        teleport(window);
    }else {
        if(creautre.getPosition().x < 2000) {
            teleportStage = 799;
        }else {
            if(!collisionSystem(characterPosition)) {
                move();
            }
            drawNPC(window);
        }
    }
}

void NPC::move() {
    if(moveNumber == 100) {
        creautre.setTexture(walk[1]);
    }else if(moveNumber == 200) {
        creautre.setTexture(walk[2]);
    }else if(moveNumber == 300) {
        creautre.setTexture(walk[0]);
        moveNumber = 0;
    }
    moveNumber++;
    creautre.move(-0.1, 0);
}

void NPC::teleport(sf::RenderWindow & window) {
    int x = teleportStage/100;
    creautre.setTexture(teleportBegin[x]);
    drawNPC(window);
    sf::Vector2f forFunction = creautre.getPosition();
    creautre.setTexture(teleportEnd[x]);
    creautre.setPosition(3000, 9*64);
    drawNPC(window);
    if(teleportStage!=1) {
        creautre.setPosition(forFunction);
    }
    teleportStage--;
}


void NPC::drawNPC(sf::RenderWindow&window) {
    window.draw(creautre);
}

sf::Vector2f NPC::getPosition() {
    return creautre.getPosition();
}

bool NPC::collisionSystem(sf::Vector2f characterPosition) {
    if(creautre.getPosition().x-54<=characterPosition.x && creautre.getPosition().x-53>=characterPosition.x) {
        return true;
    }
    return false;
}







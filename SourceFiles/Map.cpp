#include "../HeadersFiles/Map.hpp"
#include <string>
#include <iostream>

maps::maps(int _width, int _height){
    width = _width;
    height = _height;
    coordinates = new int * [width];
    for(int i = 0; i<width; ++i){
        *(coordinates+i) = new int [height];
    }
    for(int i = 0; i<width; ++i) {
        for(int ii = 0; ii<height; ++ii) {
            coordinates[i][ii] = 414;
        }
    }
    for(int i = 1; i<25; ++i){
        titlesToSprite[i-1].loadFromFile("../Assets/Map/"+std::to_string(i)+".png");
        titles[i-1].setTexture(titlesToSprite[i-1]);
    }
    for(int i = 0; i<width; ++i) {
        coordinates[i][16] = 13; //Trzeva rozwinąć, o system automatycznego tworzenia map
        coordinates[i][15] = 10;
        coordinates[i][14] = 10;
        coordinates[i][13] = 10;
        coordinates[i][12] = 10;
        coordinates[i][11] = 6;
        coordinates[i][10] = 0;
    }
    coordinates[30][10] = 414; //do usunięcia
    coordinates[20][9] = 0;
    coordinates[20][8] = 0;

    coordinates[25][6] = 0;
    coordinates[45][2] = 0;
}
maps::~maps(){
    for(int i = 0; i<width; ++i){
        delete[] *(coordinates+i);
    }
}

void maps::drawMap(sf::RenderWindow & window) {
    int x;
    for(int i = 0; i<width; ++i) {
        for(int ii = 0; ii<height; ++ii) {
            x = coordinates[i][ii];
            if(x != 414) {
                titles[x].setPosition(i*64, ii*64); //wiemy że klocek ma 64 piksele
                window.draw(titles[x]);
            }
        }
    }
}

int** maps::getCoordinates() {
    return coordinates;
}

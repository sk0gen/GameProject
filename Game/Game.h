//
// Created by sk0gen on 27/03/2018.
//

#ifndef PROJEKTGRAC_GAME_H
#define PROJEKTGRAC_GAME_H
#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <Box2D/Box2D.h>
//#include "GameObjects/Rectangle/Rectangle.h" // Tutaj jest problem. Gdy nie includuje tego pliku wszystko smiga, tylko jest to potrzebne :D.
#include <string>
#include <vector>
#include <memory>

class Rectangle;

class Game {
public:
    Game(float gravity_ = 800.f);
    ~Game();
    void run();
    void LoadTexture(std::string Filename);
    sf::RenderWindow window;
    std::vector<sf::Texture> textures;
    b2World world;
    sf::Texture Background;
    sf::Music Music;

private:
    void processEvents();
    void update();
    void render();
    void LoadBackground(const std::string &Filename);


};



#endif //PROJEKTGRAC_GAME_H

//
// Created by sk0gen on 27/03/2018.
//

#ifndef PROJEKTGRAC_GAME_H
#define PROJEKTGRAC_GAME_H
#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <Box2D/Box2D.h>
#include <string>
#include <vector>
#include <memory>
#include "GameObjects/Rectangle/Rectangle.h"
#include "GameObjects/Player/Player.h"
#include "GameObjects/Bullet/Bullet.h"

class Rectangle;
class Player;
class Bullet;


class Game {
public:
    Game(float gravity_ = 8.f);

    ~Game();

    void run();

    void LoadTexture(std::string Filename);

    sf::RenderWindow window;
    std::vector<sf::Texture> textures;
    b2World *world;
    sf::Texture Background;
    sf::Music Music;
    std::vector<Rectangle> Rectangles;
    std::vector<Bullet> Bullets;
    Player *player;

private:
    void processEvents();

    void update();

    void render(std::vector<Rectangle> &Rectangles,std::vector<Bullet> &Bullets);

    void LoadBackground(const std::string &Filename);

public:
    void setPlayer(Player *player) {
        Game::player = player;
    }

};


#endif //PROJEKTGRAC_GAME_H

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
#include "GameObjects/Monster/Monster.h"
#include "Listener/myListener.h"

#include <random>
#include <time.h>

class Rectangle;

class Player;

class Bullet;

class Monster;

class Game {


public:
    Game(float gravity_ = 8.f);

    ~Game();

    void run();

    void LoadTexture(std::string Filename);

    int SpawnCounter = 0;
    int ShootingSpeed = 0;
    int Points = 0;
    myListener listener;
    sf::RenderWindow window;
    std::vector<sf::Texture> textures;
    b2World *world;
    sf::Texture Background;
    sf::Music Music;
    std::vector<Rectangle> Rectangles;
    std::vector<Bullet> Bullets;
    std::vector<Monster> Monsters;
    Player *player;
    sf::Font font;
    sf::Text text;
    bool GamePlay = true;
private:
    void SetGame();
    void processEvents();

    void update();

    void render();

    void LoadBackground(const std::string &Filename);

    int randomInt();

    void Pause();

    void UnPause();

    void SpawnMonsterAndGiveSpeed();

    void DeleteConflictingMonsters();

    void DeleteConflictingBullets();

    void TextUpdate();

    void ShootingUpdate();

    void PlayerShooting();

public:
    void setPlayer(Player *player) {
        Game::player = player;
    }

};

/*class myListener : public b2ContactListener, public Game {
    void BeginContact(b2Contact *contact) {
        auto one = contact->GetFixtureA()->GetBody();
        auto two = contact->GetFixtureB()->GetBody();
        std::string *string1 = (std::string *) one->GetUserData();
        std::string *string2 = (std::string *) two->GetUserData();
        if ((*string1 == "bullet") && (*string2 == "monster")) {
            deleteBullet(one);
            deleteMonster(two);
        }
        if ((*string1 == "monster") && (*string2 == "bullet")) {
            deleteBullet(two);
            deleteMonster(one);
        }
    }
};*/


#endif //PROJEKTGRAC_GAME_H

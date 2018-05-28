//
// Created by sk0gen on 27/03/2018.
//

#include "Game.h"
#include "Units/Units.h"
#include <iostream>
#include <algorithm>
#include <math.h>

/** Prepare the window  + world*/
Game::Game(float gravity_) : window(sf::VideoMode(1600, 900, 32), "SomeGame") {
    world = new b2World(b2Vec2(0.f, gravity_));
    window.setFramerateLimit(60);
}

Game::~Game() {
    delete world;
    std::cout << "Finito";
}

void Game::run() {
    LoadBackground("../Img/Background.png");
    if (!Music.openFromFile("../Music/Shots.wav")) {
        return; // error
    }
    Music.setVolume(0.4f);
    Music.play();

    auto Ground = Rectangle(textures[2], 4000, 25, 50, 875, world, b2_staticBody);
    Rectangles.push_back(Ground);
    auto Wall1 = Rectangle(textures[2], 5, 2000, -100, 00, world, b2_staticBody);
    Rectangles.push_back(Wall1);
    auto Wall2 = Rectangle(textures[2], 5, 2000, 1700, 00, world, b2_staticBody);
    Rectangles.push_back(Wall2);
    auto Wall3 = Rectangle(textures[2], 4000, 5, 00, -100, world, b2_staticBody);
    Rectangles.push_back(Wall2);

    auto player = new Player(textures[0], 50, 50, 800, 700, world, b2_dynamicBody);
    this->setPlayer(player);


    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Right: {
                        player->body->SetLinearVelocity(b2Vec2(4.f, player->body->GetLinearVelocity().y));
                        break;
                    }
                    case sf::Keyboard::Left: {
                        player->body->SetLinearVelocity(b2Vec2(-4.f, player->body->GetLinearVelocity().y));

                        break;
                    }
                    case sf::Keyboard::Up: {
                        player->body->SetLinearVelocity(b2Vec2(player->body->GetLinearVelocity().x, -4.f));
                        break;
                    }
                    case sf::Keyboard::X : {

                        auto bullet = Bullet(textures[3], 8, player->x, player->y - 20, world, b2_dynamicBody);
                        double lenght = 0; //NORMALIZACJA WEKTORA w.x/|w|;;; w.y/|w|
                        lenght = sqrt(pow(Units::PixelsToMeters(
                                sf::Mouse::getPosition(window).x -
                                Units::MetersToPixels(player->body->GetPosition().x)), 2) + pow((Units::PixelsToMeters(
                                sf::Mouse::getPosition(window).y - 40 -
                                Units::MetersToPixels(player->body->GetPosition().y))), 2));


                        bullet.body->ApplyLinearImpulseToCenter(b2Vec2(Units::PixelsToMeters(
                                sf::Mouse::getPosition(window).x -
                                Units::MetersToPixels(player->body->GetPosition().x)) * 1.7 / lenght,
                                                                       (Units::PixelsToMeters(
                                                                               sf::Mouse::getPosition(window).y - 40 -
                                                                               Units::MetersToPixels(
                                                                                       player->body->GetPosition().y))) *
                                                                       1.7 / lenght),
                                                                true);
                        Bullets.push_back(bullet);
                        break;
                    }
                    case sf::Keyboard::Y : {
                        for (auto x:Bullets) {
                            x.Kill();

                        }
                        Bullets.clear();
                        break;
                    }
                    case sf::Keyboard::T : {
                        for (auto x:Rectangles) {
                            x.Kill();
                        }
                        Rectangles.clear();
                        break;
                    }
                }
            }
            case sf::Event::MouseButtonPressed: {
                switch (event.key.code) {
                    case sf::Mouse::Left: {
                        auto Rect = Rectangle(textures[1], 32, 32, sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y, world, b2_staticBody);
                        Rectangles.push_back(Rect);

                        break;
                    }
                    case sf::Mouse::Right: {
                        /*Rectangles[1].body->SetLinearVelocity(b2Vec2(1.f,-2.f));*/
                        auto bullet = Bullet(textures[3], 8, sf::Mouse::getPosition(window).x,
                                             sf::Mouse::getPosition(window).y, world, b2_dynamicBody);

                        Bullets.push_back(bullet);
                        break;
                    }
                        break;
                }
            }
        }

    }

}


void Game::update() {
    SpawnCounter++;
    if (SpawnCounter == 300) {
        Monster monster = Monster(textures[4], 50, 50, -50, 750, world, b2_dynamicBody);
        monster.body->SetLinearVelocity(b2Vec2(2.f, 0.f));
        Monsters.push_back(monster);
    }

    for (auto m:Monsters) {
        m.body->SetLinearVelocity(m.body->GetLinearVelocity());
    }
}

void Game::render() {

    window.clear(sf::Color::White);
    world->Step(1 / 60.f, 8, 3);

    //draw()
    sf::Sprite Background_(Background);
    window.draw(Background_);

    for (auto &x : Rectangles) {
        x.Rendering(this);
    }
    for (auto &x : Bullets) {
        x.Rendering(this);

    }
    for (auto &x: Monsters) {
        x.Rendering(this);
    }
    if (player->body != nullptr) {
        player->Rendering(this);
    }

//End the current frame
    window.display();
}

void Game::LoadBackground(const std::string &Filename) {
    Background.loadFromFile(Filename);
}

void Game::LoadTexture(std::string Filename) {
    sf::Texture Buffor;
    Buffor.loadFromFile(Filename);
    Buffor.setSmooth(true);
    textures.push_back(Buffor);
}





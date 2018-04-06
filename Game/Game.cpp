//
// Created by sk0gen on 27/03/2018.
//

#include "Game.h"
#include <iostream>
#include <algorithm>

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

    auto Ground = Rectangle(textures[2], 3200, 25, 50, 875, world, b2_staticBody);
    Rectangles.push_back(Ground);

    auto player = new Player(textures[0], 50, 50, 50, 700, world, b2_dynamicBody);
    this->setPlayer(player);

    while (window.isOpen()) {
        processEvents();
        update();
        render(Rectangles);
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
                        player->body->SetLinearVelocity(b2Vec2(3.f, 0.f));
                        break;
                    }case sf::Keyboard::Left: {
                        player->body->SetLinearVelocity(b2Vec2(-3.f, 0.f));
                        break;
                    }case sf::Keyboard::Up: {
                        player->body->SetLinearVelocity(b2Vec2(player->body->GetLinearVelocity().x, -2.f));
                        break;
                    }
                }
            }
            case sf::Event::MouseButtonPressed: {
                switch (event.key.code) {
                    case sf::Mouse::Left: {
                        auto Rect = Rectangle(textures[1], 32, 32, sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y, world, b2_dynamicBody);
                        Rectangles.push_back(Rect);
                        break;
                    }
                    case sf::Mouse::Right: {
                        /*Rectangles[1].body->SetLinearVelocity(b2Vec2(1.f,-2.f));*/
                        Rectangles[1].body->ApplyForceToCenter(b2Vec2(0.f, -100.f), true);
                        break;
                    }
                        break;
                }
            }
        }

    }

}


void Game::update() {
}

void Game::render(std::vector<Rectangle> &Rectangles) {
    std::cout << sf::Mouse::getPosition(window).y << std::endl;
    window.clear(sf::Color::White);
    world->Step(1 / 60.f, 8, 3);

    //draw()
    sf::Sprite Background_(Background);
    window.draw(Background_);

    for (auto &x : Rectangles) {
        x.Rendering(this);
    }
    player->Rendering(this);

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





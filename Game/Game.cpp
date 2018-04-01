//
// Created by sk0gen on 27/03/2018.
//

#include "Game.h"
#include <iostream>

/** Prepare the window  + world*/
Game::Game(float gravity_) : window(sf::VideoMode(1600, 900, 32), "SomeGame") {
    world = new b2World(b2Vec2(0.f, gravity_));
    window.setFramerateLimit(60);
}

Game::~Game() {
    std::cout << "Finito";
}

void Game::run() {
    LoadBackground("../Img/Background.png");
    if (!Music.openFromFile("../Music/Shots.wav")) {
        return; // error
    }
    Music.setVolume(0.4f);
    Music.play();

    auto Rect = Rectangle(textures[1], 32, 32, 250, 250, world, b2_dynamicBody);
    Rectangles.push_back(Rect);
    Rect = Rectangle(textures[2], 3200, 25, 50, 875, world, b2_staticBody);
    Rectangles.push_back(Rect);

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
            case sf::Event::MouseButtonReleased:
                switch (event.key.code) {
                    case sf::Mouse::Left: {
                        auto Rect = Rectangle(textures[1], 32, 32, sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y, world, b2_dynamicBody);
                        Rectangles.push_back(Rect);
                        break;
                    }

                        break;
                }
        }

    }

}


void Game::update() {
}

void Game::render(std::vector<Rectangle> Rectangles) {
    window.clear(sf::Color::White);
    world->Step(1 / 60.f, 8, 3);

    //draw()
    sf::Sprite Background_(Background);
    window.draw(Background_);
    for (auto &x : Rectangles) {
        x.Rendering(this);
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



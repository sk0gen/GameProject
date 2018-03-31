//
// Created by sk0gen on 27/03/2018.
//

#include "Game.h"
#include <iostream>
/** Prepare the window  + world*/
Game::Game(float gravity_) : window(sf::VideoMode(1600, 900, 32), "SomeGame"), world(b2Vec2(0.f, gravity_)) {
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
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void Game::update() {
}

void Game::render() {
    window.clear(sf::Color::White);
    world.Step(1 / 60, 8, 3);

    //draw()
    sf::Sprite Background_(Background);
    window.draw(Background_);


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



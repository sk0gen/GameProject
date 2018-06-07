//
// Created by sk0gen on 01/04/2018.
//

#ifndef PROJEKTGRAC_PLAYER_H
#define PROJEKTGRAC_PLAYER_H
#pragma once

#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "../GameObject.h"


class Player : public GameObject {
public:
    b2World* World = nullptr;
    sf::Texture Texture;
    int width;
    int height;
    b2Body *body;
public:
    Player(const sf::Texture &texture,int width,
              int height,float x,float y,
              b2World * World = nullptr,
              b2BodyType bodyType = b2_dynamicBody);

    void MoveLeft();
    void MoveRight();
    virtual void Rendering(Game *game) override;
    virtual void Kill() override ;


};


#endif //PROJEKTGRAC_PLAYER_H

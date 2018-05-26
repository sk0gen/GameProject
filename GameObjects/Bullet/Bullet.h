//
// Created by gawin on 17/05/2018.
//

#ifndef PROJEKTGRAC_BULLET_H
#define PROJEKTGRAC_BULLET_H
#pragma once

#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "../GameObject.h"

class Bullet : public  GameObject{
public:
    b2World *World = nullptr;
    sf::Texture Texture;
    int r;
    b2Body *body;
public:
    Bullet(const sf::Texture &texture, int r, float x, float y,
              b2World *World = nullptr,
              b2BodyType bodyType = b2_staticBody);

    virtual void Rendering(Game *game) override;

    virtual void Kill() override;
};


#endif //PROJEKTGRAC_BULLET_H

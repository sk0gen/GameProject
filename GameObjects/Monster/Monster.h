//
// Created by gawin on 26/05/2018.
//

#ifndef PROJEKTGRAC_MONSTER_H
#define PROJEKTGRAC_MONSTER_H



#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "../GameObject.h"


class Monster : public GameObject {
public:
    b2World *World = nullptr;
    sf::Texture Texture;
    int width;
    int height;
    b2Body *body;
public:
    Monster(const sf::Texture &texture, int width,
              int height, float x, float y,
              b2World *World = nullptr,
              b2BodyType bodyType = b2_staticBody);

    virtual void Rendering(Game *game) override;

    virtual void Kill() override;


};

#endif //PROJEKTGRAC_MONSTER_H

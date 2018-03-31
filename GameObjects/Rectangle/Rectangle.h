//
// Created by sk0gen on 27/03/2018.
//

#ifndef PROJEKTGRAC_RECTANGLE_H
#define PROJEKTGRAC_RECTANGLE_H
#pragma once

#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "../GameObject.h"


class Rectangle:public GameObject {
    b2World* someWorld = nullptr;
    sf::Texture Texture;
    int width;
    int height;
    b2Body *body;
public:
    Rectangle(const sf::Texture &texture,int width,
              int height,int x,int y,
              b2World * World = nullptr,
                b2BodyType bodyType = b2_staticBody);

    void Rendering(Game *game) override;

};


#endif //PROJEKTGRAC_RECTANGLE_H

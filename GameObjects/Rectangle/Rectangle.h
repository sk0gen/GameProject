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
public:
    b2World* World = nullptr;
    sf::Texture Texture;
    int width;
    int height;
    b2Body *body;
public:
    Rectangle(const sf::Texture &texture,int width,
              int height,float x,float y,
              b2World * World = nullptr,
                b2BodyType bodyType = b2_staticBody);

    virtual void Rendering(Game *game) override;


};


#endif //PROJEKTGRAC_RECTANGLE_H

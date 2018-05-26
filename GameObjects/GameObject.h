//
// Created by sk0gen on 23/03/2018.
//

#ifndef PROJEKTGRAC_GAMEOBJECT_H
#define PROJEKTGRAC_GAMEOBJECT_H
#pragma once


class Game;

class GameObject {
public:
    float x;
    float y;

    virtual void Rendering(Game *game)=0;

    virtual void Kill()=0;

};

#include "../Game/Game.h"

#endif //PROJEKTGRAC_GAMEOBJECT_H

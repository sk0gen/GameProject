//
// Created by sk0gen on 23/03/2018.
//

#ifndef PROJEKTGRAC_GAMEOBJECT_H
#define PROJEKTGRAC_GAMEOBJECT_H
#pragma once
#include "../Game/Game.h"

class GameObject {
public:
    int x;
    int y;

    virtual void Rendering(Game *game)=0;
    virtual void Delete_Body()=0;

};

#endif //PROJEKTGRAC_GAMEOBJECT_H

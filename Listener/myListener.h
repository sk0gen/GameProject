//
// Created by gawin on 05/06/2018.
//

#ifndef PROJEKTGRAC_MYLISTENER_H
#define PROJEKTGRAC_MYLISTENER_H
#pragma once
#include <Box2D/Box2D.h>


class myListener : public b2ContactListener{
    void BeginContact(b2Contact* contact);
};


#endif //PROJEKTGRAC_MYLISTENER_H

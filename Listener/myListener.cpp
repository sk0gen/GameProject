//
// Created by gawin on 05/06/2018.
//

#include "myListener.h"
#include <iostream>
#include <string>

void myListener::BeginContact(b2Contact *contact) {
    auto one = contact->GetFixtureA()->GetBody();
    auto two = contact->GetFixtureB()->GetBody();
    if(one->GetUserData() && two->GetUserData()) {
        auto string1 = (std::string *) one->GetUserData();
        auto string2 = (std::string *) two->GetUserData();
        if ((*string1 == "bullet") && (*string2 == "monster")) {
            *string1 = "delete";
            *string2 = "delete";
        }
        if ((*string1 == "monster") && (*string2 == "bullet")) {
            *string1 = "delete";
            *string2 = "delete";
        }
        if ((*string1 == "monster") && (*string2 == "monster")) {
            *string1 = "deleteNoPoint";
            *string2 = "deleteNoPoint";
        }
    }
}

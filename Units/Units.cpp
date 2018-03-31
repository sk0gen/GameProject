//
// Created by sk0gen on 27/03/2018.
//

#include "Units.h"

int Units::MetersToPixels(float meters) {
    return (int)((meters*50));
}

float Units::PixelsToMeters(int pixels) {
    return (float)(pixels*0.02);
}

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Main.hpp"
#include <Box2D/Box2D.h>
#include <iostream>
#include "Game/Game.h"
#include "GameObjects/Rectangle/Rectangle.h"
int main() {

    auto THEGAME = new Game;
    THEGAME->LoadTexture("../IMG/Player.png");
    THEGAME->LoadTexture("../IMG/Box.png");
    THEGAME->LoadTexture("../IMG/ground.png");


    THEGAME->run();

    return 0;
}



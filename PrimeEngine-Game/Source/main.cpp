#include "GameManager.h"
#include <SDL.h>

#undef main

int main(int argc, char** argv) {
    Application::GameManager game;
    game.Init();

    return 0;
}

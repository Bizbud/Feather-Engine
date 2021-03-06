#include "engine.h"
#include "game.h"

int main()
{
    engine_init();
    game_init();
    loop();
    game_cleanup();
    engine_cleanup();
    return 0;
}
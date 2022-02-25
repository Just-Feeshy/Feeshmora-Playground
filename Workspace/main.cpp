#include "../Application.cpp"

#include "statesLMAO/PlayState.cpp"
 
int main(int argv, char** argc) {
    WindowDisplay window;
    window.init();
    window.createSize(400, 400, false);
    window.setTitle("No Title");
    window.disableCursor();
    //window.setColor(0.0f, 0.0f, 0.0f, 0.0f);

    Application game(window);

    game.switchState<PlayState>();

    while(game.isOpen()) {
        game.update();
    }

    game.close();

    return 0;
}
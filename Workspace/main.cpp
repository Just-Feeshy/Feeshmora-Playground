#include "../Application.cpp"
#include "../FeshStates/TriangleState.cpp"

#include "statesLMAO/PlayState.cpp"
 
int main(int argv, char** argc) {
   WindowDisplay window;
   window.init();
   window.createSize(400, 400, false);
   window.setTitle("Funni Feesh Game");
   window.disableCursor();
 
   Application game(window);

   game.switchState<PlayState>();

   while(game.isOpen()) {
        game.update();
   }

   game.close();
 
   return 0;
}
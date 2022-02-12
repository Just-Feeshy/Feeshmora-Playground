#ifndef APP_INCLUDED
#define APP_INCLUDED

#include "FeshStates/BasicStates.h"
#include "Util/FPS.cpp"

#include <memory>
#include <vector>

using namespace std;

float extern elasped;

/**
* Not the best Application class.
*/
class Application {
    public:
        Application(WindowDisplay &window);

        void compile();
        void update();
        void customEvents();
        void close();
        bool isOpen();

        template<typename T, typename...obj> void switchState(obj&&...args);
        
        void destroyState();

        /**
        * I thought of making it a unique_ptr, but if
        * the system can't detect a proper window in
        * the first place, the program it self will
        * close.
        */
        WindowDisplay* daWindow = 0;
    protected:
        vector<unique_ptr<BasicStates>> _states;
        FPS fps;
};
#endif
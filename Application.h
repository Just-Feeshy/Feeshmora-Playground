#ifndef APP_INCLUDED
#define APP_INCLUDED

#include "FeshStates/BasicStates.h"
#include "Util/FPS.cpp"

#include <memory>
#include <functional>
#include <vector>

using namespace std;

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

        template<typename T> static void addEvent(T event, void (*call)());
        
        void destroyState();

        /**
        * I thought of making it a unique_ptr, but if
        * the system can't detect a proper window in
        * the first place, the program it self will
        * close.
        */
        WindowDisplay* daWindow = 0;
    private:
        vector<unique_ptr<BasicStates>> _states;
        FPS fps;
};
#endif
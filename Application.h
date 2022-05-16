#ifndef APP_INCLUDED
#define APP_INCLUDED

#include "FeshStates/BasicStates.h"
#include "FeshEvents/Event.h"
#include "Util/FPS.cpp"

#include <memory>
#include <vector>

using namespace std;

/**
* Not the best Application class.
*/
class Application {
    public:
        Application(WindowDisplay &window);
        ~Application();

        void compile();
        void update();
        void customEvents();
        bool isOpen();

        template<typename T, typename...obj> void switchState(obj&&...args);

        template<typename T> static void addEvent(T* event, void (*call)(Event*));

        static void clearEvents();

        void destroyState();

        /**
        * I thought of making it a unique_ptr, but if
        * the system can't detect a proper window in
        * the first place, the program it self will
        * close.
        */
        static WindowDisplay* daWindow;
    private:
        static vector<Event*> events;

        vector<unique_ptr<BasicStates>> _states;
        FPS fps;

        void updateEvents(float elapsed);
        void close();
};
#endif
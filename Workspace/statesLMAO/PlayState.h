#ifndef PLAYSTATE_INCLUDED
#define PLAYSTATE_INCLUDED

#include "../../FeshStates/BasicStates.h"
#include "../../Model/Light.cpp"

class PlayState: public BasicStates {
    public:
        PlayState() = default;
        ~PlayState();

        void onCreate() override;
        void update(float elapsed) override;
    private:
        Model square;
        Model funniObject;
        Model floor;

        Light lightsource;
};
#endif
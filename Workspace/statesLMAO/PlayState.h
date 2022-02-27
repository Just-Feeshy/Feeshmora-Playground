#ifndef PLAYSTATE_INCLUDED
#define PLAYSTATE_INCLUDED

#include "../../FeshStates/BasicStates.h"
#include "../../Model/Light/PointLight.cpp"
#include "../../Model/Light/SpotLight.cpp"

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

        SpotLight lightsource;
        PointLight lightsource2;
};
#endif
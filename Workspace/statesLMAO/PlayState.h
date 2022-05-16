#ifndef PLAYSTATE_INCLUDED
#define PLAYSTATE_INCLUDED

#include "../../FeshStates/AdvancedStates.hpp"
#include "../../Model/Light/DirectionalLight.cpp"
#include "../../FeshEvents/ControllerEvent.cpp"
#include "../../FeshEvents/MouseEvent.cpp"
#include "../../Model/Light/PointLight.cpp"
#include "../../Model/Light/SpotLight.cpp"
#include "../../Entities/Player.cpp"
#include "../../Application.cpp"

#include "../../Objects/MeshObjects.hpp"

#include <iostream>

class PlayState: public AdvancedStates {
    public:
        PlayState() = default;
        ~PlayState();

        void onCreate() override;
        void update(float elapsed) override;

        void test1(Event* event);
    private:
        Model* square;
        Model* funniObject;
        Model* floor;

        Entity* badman;


        SpotLight* lightsource;
        PointLight* lightsource2;

        DirectionalLight* sun;
};
#endif
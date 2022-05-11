#ifndef PLAYSTATE_INCLUDED
#define PLAYSTATE_INCLUDED

#include "../../FeshStates/AdvancedStates.hpp"
#include "../../Model/Light/DirectionalLight.cpp"
#include "../../Model/Light/PointLight.cpp"
#include "../../Model/Light/SpotLight.cpp"
#include "../../Entities/Entity.cpp"

#include "../../Objects/MeshObjects.hpp"

class PlayState: public AdvancedStates {
    public:
        PlayState() = default;
        ~PlayState();

        void onCreate() override;
        void update(float elapsed) override;
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
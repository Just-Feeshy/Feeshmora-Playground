#ifndef BASICSTATE_INCLUDED
#define BASICSTATE_INCLUDED

#include "../Renderer/Shaders/Shaders.cpp"
#include "../Graphics/Textures/FirstTextures.cpp"
#include "../Input/Controls.cpp"
#include "../Camera.cpp"

#include "../Model/Light/Light.h"

#include <memory>

using namespace std;

/**
* Most messy class I've ever made.
*/

class BasicStates {
    public:
        BasicStates() {
            if(!defaultShaders.loadedShaders()) {
                defaultShaders.loadFiles(
                    "Shaders/DefaultShaders.glsl",
                    "Shaders/DefaultShaders.fs"
                );

                defaultShaders.Init();
            }
        };

        ~BasicStates() {
            if(daCamera != nullptr) {
                daCamera.reset();
            }

            for(int i=0; i<_objects.size(); i++) {
                delete _objects[i];
            }

            _objects.clear();
        }
        
        virtual void onCreate() = 0;
        virtual void update(float elapsed) = 0;

        void add(auto &obj) {
            _objects.push_back(&obj);

            //Refresh
            if(dynamic_cast<Light*>(&obj) != nullptr) {
                auto lightType = dynamic_cast<Light*>(&obj) -> getType();

                if(lightType == POINT) {
                    lightAmounts[0] = lightAmounts[0] + 1;
                }else if(lightType == SPOT) {
                    lightAmounts[1] = lightAmounts[1] + 1;
                }

                defaultShaders.loadFiles(
                    "Shaders/DefaultShaders.glsl",
                    "Shaders/DefaultShaders.fs",
                    ShaderFragments::setMaximumLights(
                        lightAmounts[0],
                        lightAmounts[1],
                        1
                    ),
                    FRAGMENT
                );
            }

            obj.render();
        }

        void clear() {
            if(_objects.size() > 0) {
                _objects.clear();
            }
        }

        unique_ptr<Camera> daCamera;
    protected:
        Shaders defaultShaders;

        vector<Mesh*> _objects;
        Controls control;

        //Caculate lights in Application.
        glm::vec3 lightAmounts;
    private:
        friend class Application;

        /**
        * Stuff for the Application class to handle.
        */
        void updateAllObjs(float elapsed) {
            defaultShaders.uniformMat4("pViewMatrix", daCamera -> getProjectionView());

            defaultShaders.uniformVec3("cameraPos", Matrix::useVec3(daCamera -> getPosition(X), daCamera -> getPosition(Y), daCamera -> getPosition(Z)));

            daCamera -> update(elapsed);
            defaultShaders.update();

            glm::vec3 light = {0, 0, 0};

            for(GLuint i=0; i<_objects.size(); i++) {
                if(&defaultShaders == nullptr) {
                    break;
                }

                if(dynamic_cast<Light*>(_objects[i]) != nullptr) {
                    auto lightType = dynamic_cast<Light*>(_objects[i]) -> getType();

                    if(lightType == POINT) {
                        light[0] = light[0] + 1;
                    }else if(lightType == SPOT) {
                        light[1] = light[1] + 1;
                    }

                    auto &lightOBJ = *_objects[i];

                    if(lightType == POINT) {
                        lightOBJ.draw(&defaultShaders, light[0]-1);
                    }else if(lightType == SPOT) {
                        lightOBJ.draw(&defaultShaders, light[1]-1);
                    }
                }

                _objects[i] -> draw(&defaultShaders);
                _objects[i] -> update();
            }
        }

        void configWithWindow(WindowDisplay* window) {
            daCamera = make_unique<Camera>(window);
            control.bindToWindow(window);
        }
};
#endif
#ifndef ADVANCEDSTATES_INCLUDED
#define ADVANCEDSTATES_INCLUDED

#include "../Application.cpp"
#include "../Renderer/Shaders/DefaultShaders.cpp"
#include "../Graphics/Textures/FirstTextures.cpp"
#include "../UniqueBuffers/FrameBuffers.cpp"
#include "../Camera.cpp"
#include "BasicStates.h"

#include "../Model/Light/Light.h"

#include <memory>
#include <cmath>

using namespace std;

/**
* Messiest class I've ever made.
*/
class AdvancedStates: public BasicStates {
    public:
        AdvancedStates() {
            daCamera = new Camera();
            daCamera -> implementWindow(Application::daWindow);
            
            if(!defaultShaders.loadedShaders()) {
                defaultShaders.loadFiles(
                    "Shaders/DefaultShaders.glsl",
                    "Shaders/DefaultShaders.fs"
                );

                defaultShaders.Init();
            }
        };

        ~AdvancedStates() {
            _objects.clear();
            
            if(daCamera != nullptr) {
                delete daCamera;
            }
        }
        
        virtual void onCreate() override = 0;
        
        virtual void update(float elapsed) override {
            updateAllObjs(elapsed);
        }

        template<typename T> void add(T obj) {  
            _objects.push_back(obj);

            //Refresh
            if(dynamic_cast<Light*>(obj) != nullptr) {
                auto lightType = dynamic_cast<Light*>(obj) -> getType();

                if(lightType == POINT) {
                    lightAmounts[0] = lightAmounts[0] + 1;
                }else if(lightType == SPOT) {
                    lightAmounts[1] = lightAmounts[1] + 1;
                }

                defaultShaders.loadFiles(
                    "Shaders/DefaultShaders.glsl",
                    "Shaders/DefaultShaders.fs",
                    ShaderFragments::setMaximumLights(
                        fmax(1, lightAmounts[0]),
                        fmax(1, lightAmounts[1]),
                        1
                    ),
                    FRAGMENT
                );
            }

            obj -> implementWindow(Application::daWindow);
            obj -> render();
        }

        virtual void setWindow(WindowDisplay* window) override {
            
        }
    protected:
        DefaultShaders defaultShaders;
        vector<Mesh*> _objects;

        //Caculate lights in Application.
        glm::vec3 lightAmounts;

        Camera* daCamera;
    private:
        /**
        * Stuff for the Application class to handle.
        */
        void updateAllObjs(float elapsed) {
            for(GLuint i=0; i<_objects.size(); i++) {
                if(_objects[i] == nullptr) {
                    return;
                }
                
                _objects[i] -> update(elapsed);
            }

            if(daCamera != nullptr) {
                defaultShaders.update();
                defaultShaders.uniformMat4("pViewMatrix", daCamera -> getProjectionView());
    
                defaultShaders.uniformVec3("cameraPos", Matrix::useVec3(daCamera -> getPosition(X), daCamera -> getPosition(Y), daCamera -> getPosition(Z)));
    
                daCamera -> update(elapsed);
            }

            glm::vec3 light = {0, 0, 0};

            for(GLuint i=0; i<_objects.size(); i++) {
                _objects[i] -> draw(&defaultShaders);

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
                    }else {
                        lightOBJ.draw(&defaultShaders, 0);
                    }
                }
            }
        }
};
#endif
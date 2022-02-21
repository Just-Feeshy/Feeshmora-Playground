#ifndef BASICSTATE_INCLUDED
#define BASICSTATE_INCLUDED

#include "../Renderer/Shaders/Shaders.cpp"
#include "../Graphics/Textures/FirstTextures.cpp"
#include "../Input/Controls.cpp"
#include "../Camera.cpp"

#include <memory>

using namespace std;

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
        
        virtual void onCreate() = 0;
        virtual void update(float elapsed) = 0;

        void add(auto &obj) {
            _objects.push_back(&obj);

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

            for(GLuint i=0; i<_objects.size(); i++) {
                if(&defaultShaders == nullptr) {
                    break;
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
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
            std::vector<glm::mat4> storeMatrix;

            defaultShaders.uniformInt("MODELS_AMOUNT", _objects.size());

            /**
            for(GLuint i=0; i<_objects.size(); i++) {
                storeMatrix.push_back(_objects[i] -> getMatrix());
            }
            **/

            defaultShaders.uniformMat4("modelMatrix_Array", _objects[0] -> getMatrix());

            defaultShaders.uniformMat4("pViewMatrix", daCamera -> getProjectionView());

            daCamera -> update(elapsed);
            defaultShaders.update();

            for(GLuint i=0; i<_objects.size(); i++) {
                _objects[i] -> draw();
                _objects[i] -> update();
            }
        }

        void configWithWindow(WindowDisplay* window) {
            daCamera = make_unique<Camera>(window);
            control.bindToWindow(window);
        }
};
#endif
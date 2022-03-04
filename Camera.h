#ifndef CAM_INCLUDED
#define CAM_INCLUDED

#include "Model/Model.h"
#include "WindowDisplay.cpp"

#include <algorithm>

class Camera: public Model {
    public:
        Camera(WindowDisplay* window);
        ~Camera() = default;

        void setRotation(float yaw, float pitch, float roll) override;

        void draw(Shaders* shader) override;

        void update(float elapsed);

        glm::mat4 getMatrix() override;

        /**
        * There's no point to extending this class or 
        * it's methods.
        */
        glm::mat4 getProjection(WindowDisplay* window) const {
            return projection;
        };

        glm::mat4 getView() const {
            return view;  
        };

        glm::mat4 getProjectionView() const {
            return pView;   
        };

        std::vector<Shaders> getShaders() const {
            return shaderGroup;
        }

        glm::mat4 makeProjection(WindowDisplay* window);

        void addShaders(const Shaders shader);
        
        void setAsFPS();
    private:
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 pView;

        glm::vec3 cameraUP;
    public:
        WindowDisplay* thisWindow = 0;
};
#endif
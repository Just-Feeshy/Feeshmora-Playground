#ifndef CAM_INCLUDED
#define CAM_INCLUDED

#include "Model/Model.hpp"
#include "WindowDisplay.cpp"

#include <algorithm>

class Camera: public Model {
    public:
        Camera();
        ~Camera() = default;

        void setRotation(float yaw, float pitch, float roll) override;

        void draw(Shaders* shader) override;

        void implementWindow(WindowDisplay* window) override;

        WindowDisplay* getWindow() const;

        void update(float elapsed);

        glm::mat4 getMatrix() override;

        /**
        * There's no point to extending this class or 
        * it's methods.
        */
        glm::mat4 getProjection(WindowDisplay* window) const {
            return projection;
        }

        glm::mat4 getView() const {
            return view;  
        };

        glm::mat4 getProjectionView() const {
            return pView;   
        };

        std::vector<Shaders> getShaders() const {
            return shaderGroup;
        }

        glm::mat4 makeProjection();

        void addShaders(const Shaders shader);
    private:
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 pView;

        glm::vec3 cameraUP;

        WindowDisplay* thisWindow = 0;
};
#endif
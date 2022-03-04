#include "Camera.h"

Camera::Camera(WindowDisplay* window) {
    projection = makeProjection(window);

    thisWindow = window;
    
    movement.position = {0.0f, 0.0f, 0.0f};
}

void Camera::setRotation(float yaw, float pitch, float roll) {
    movement.rotation = {yaw, pitch, roll};

    glm::vec3 faceFront;

    faceFront = glm::vec3(
        sin(glm::radians(-pitch)),
        0,
        cos(glm::radians(pitch))
    );

    direction = glm::normalize(faceFront);
    angle = glm::normalize(glm::cross(direction, upwards));
    cameraUP = glm::normalize(glm::cross(angle, direction));
}

glm::mat4 Camera::makeProjection(WindowDisplay* window) {
    float width = (float)window -> width;
    float height = (float)window -> height;
    float fov = (float)window -> FOV;
    float rDistance = (float)window -> renderDistance;

    return Matrix::perspective(fov, width / height, 0.1f, rDistance * 100.0f);
}

glm::mat4 Camera::getMatrix() {
    glm::mat4 model(1.0f);

    model = glm::rotate(model, glm::radians(movement.rotation.x), {1, 0, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.y), {0, 1, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.z), {0, 0, 1});

    model = glm::translate(model, -movement.position);

    return model;
}

void Camera::addShaders(const Shaders shader) {
    shaderGroup.push_back(shader);
}

void Camera::draw(Shaders* shader) {
    shader -> uniformFloat("depthy.near", 0.1f);
    shader -> uniformFloat("depthy.far", 1600.0f);
}

void Camera::update(float elapsed) {
    if(shaderGroup.size() > 0) {
        std::for_each(shaderGroup.begin(), shaderGroup.end(), [](Shaders &shader) {
            shader.update();
        });
    }
    
    view = getMatrix();
    projection = makeProjection(thisWindow);
    pView = projection * view;
}

void Camera::setAsFPS() {
    glfwSetCursorPos(thisWindow -> window, thisWindow -> width / 2, thisWindow -> height / 2);
}
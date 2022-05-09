#pragma once

#include "Model.h"

Model::~Model() {
    if(buffers.size() > 0) {
        glDeleteBuffers(static_cast<GLsizei>(buffers.size()), buffers.data());
    }

    if(VAO != 0 && VAO) {
        glDeleteVertexArrays(1, &VAO);
    }
}

glm::mat4 Model::getMatrix() {
    glm::mat4 model(1.0f);

    model = Matrix::transform(movement.position, Quaternion::eularAngle(movement.rotation), glm::vec3(1, 1, 1));

    return model;
}

void Model::render() {
    setRotation(0, 0, 0);
}

void Model::draw(Shaders* shader) {
    //StencilBuffers::setStencilMask(0x00);
        
    if(VAO != 0 && VAO) {
        shader -> uniformMat4("modelMatrix", this -> getMatrix());

        texture.Draw(VAO, GL_TRIANGLES, 2, alignment.getMeshIndices().size(), true, shader);

        glBindVertexArray(0);
    }

    if(alpha > 0) {
        //RenderManager::blend(BLEND_NONE, BLEND_NONE);
    }
}

void Model::draw(Shaders* shader, const int index) {
    return;
}

Model* Model::create(MeshVertices &meshConfig) {
    if(!created) {
        createVAO();
        createBuffer(GL_ARRAY_BUFFER, meshConfig, false);
        createBuffer(GL_ELEMENT_ARRAY_BUFFER, meshConfig, true);
        compile();
        
        created = true;
    }

    /**
    Shaders shader(
        "Shaders/DefaultShaders.vert",
        "Shaders/DefaultShaders.frag"
    );

    shader.Init();
    shaderGroup.push_back(shader);
    **/

    return this;
}

void Model::bindVAO() {
    glBindVertexArray(VAO);
}

void Model::createVAO() {
    if(VAO != 0 && VAO) {
        glDeleteVertexArrays(1, &VAO);
    }

    glGenVertexArrays(1, &VAO);
    bindVAO();
}

void Model::createBuffer(GLenum type, MeshVertices &m, bool indices) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(type, buffer);

    if(indices) {
        glBufferData(type, sizeof(GLuint) * m.getMeshIndices().size(), &m.getMeshIndices()[0], GL_STATIC_DRAW);
    }else {
        glBufferData(type, sizeof(MeshVertex) * m.getMeshVertices().size(), &m.getMeshVertices()[0], GL_STATIC_DRAW);
    }

    alignment.cloneData(m);
    buffers.push_back(buffer);
}

void Model::compile() {
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, texCoords));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, colorRBG));

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, normalCoords));

    glBindVertexArray(0);
}

void Model::setAlpha(float value) {
    alpha = value;
}

void Model::setRotation(float yaw, float pitch, float roll) {
    movement.rotation = {yaw, pitch, roll};

    glm::vec3 faceFront;

    faceFront = glm::vec3(
        cos(glm::radians(pitch)),
        0,
        sin(glm::radians(-pitch))
    );

    direction = faceFront;
    angle = glm::normalize(glm::cross(direction, upwards));
}

void Model::setTexture(const std::string file, const TexEnum type, const TexParams params, const TexParams anti, int sides, const TexMap map) {
    texture.loadFile(file);
    texture.createTexture(type, params, anti, sides, map);
}

float Model::getAlpha() const {
    return alpha;
}

void Model::update() {
    if(shaderGroup.size() > 0) {
        std::for_each(shaderGroup.begin(), shaderGroup.end(), [](Shaders &shader) {
            shader.update();
        });
    }
}
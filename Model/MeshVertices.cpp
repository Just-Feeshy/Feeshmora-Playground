#include "MeshVertices.h"

MeshVertices::MeshVertices() {
    temp = new MeshVertex();
}

void MeshVertices::addVertexRow(float x, float y, float z) const {
    temp -> vertices = glm::vec3(x, y ,z);
    temp -> colorRBG = glm::vec3(0.5f, 0.5f, 0.5f);
}

void MeshVertices::addTexCoordRow(float x, float y) const {
    temp -> texCoords = glm::vec2(x, y);
}

void MeshVertices::addColorRow(float x, float y, float z) const {
    temp -> colorRBG = glm::vec3(x, y, z);
}

void MeshVertices::addNormalRow(float x, float y, float z) const {
    temp -> normalCoords = glm::vec3(x, y, z);
}


std::vector<MeshVertex> MeshVertices::getMeshVertices() const {
    return this -> vertices;
}

std::vector<GLuint> MeshVertices::getMeshIndices() const {
    return this -> indices;
}

void MeshVertices::storeIndices(int x, int y, int z) {

    //I got lazy
    indices.push_back(x);
    indices.push_back(y);
    indices.push_back(z);
}

void MeshVertices::cloneData(MeshVertices &m) {
    this -> vertices = m.vertices;
    this -> indices = m.indices;
}

void MeshVertices::storeThisArray() {
    temp -> normalCoords = glm::vec3(0.25, 0.25, 0.25);

    vertices.push_back(*temp);

    delete temp;
    temp = nullptr;

    temp = new MeshVertex();
}

MeshVertices::~MeshVertices() {
    if(temp != nullptr) {
        delete temp;
    }

    if(indices.size() > 0) {
        glDeleteBuffers(static_cast<GLsizei>(indices.size()), indices.data());
    }

    vertices.clear();
}
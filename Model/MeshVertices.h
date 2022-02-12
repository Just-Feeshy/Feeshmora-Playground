#ifndef MESH_VERTICES_INCLUDED
#define MESH_VERTICES_INCLUDED

#include "Mesh.h"

class MeshVertices {
    public:
        MeshVertices();
        ~MeshVertices();

        void addVertexRow(float x, float y, float z);
        void addTexCoordRow(float x, float y);
        void addColorRow(float x, float y, float z);
        
        void storeIndices(int x, int y, int z);

        void storeThisArray() {
            vertices.push_back(*temp);

            delete temp;
            temp = nullptr;

            temp = new MeshVertex();
        }

        std::vector<MeshVertex> getMeshVertices() const;
        std::vector<GLuint> getMeshIndices() const;
    private:
        MeshVertex* temp;
        
        std::vector<MeshVertex> vertices;
        std::vector<GLuint> indices;
    public:
        void cloneData(MeshVertices &m);
};
#endif
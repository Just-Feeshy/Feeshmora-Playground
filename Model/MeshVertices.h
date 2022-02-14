#ifndef MESH_VERTICES_INCLUDED
#define MESH_VERTICES_INCLUDED

#include "Mesh.h"

class MeshVertices {
    public:
        MeshVertices();
        ~MeshVertices();

        void addVertexRow(float x, float y, float z) const;
        void addTexCoordRow(float x, float y) const;
        void addColorRow(float x, float y, float z) const;
        void addNormalRow(float x, float y, float z) const;
        
        void storeIndices(int x, int y, int z);

        void storeThisArray();

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
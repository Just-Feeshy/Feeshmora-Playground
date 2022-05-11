#pragma once

#ifndef MESH_OBJECTS_INCLUDED
#define MESH_OBJECTS_INCLUDED

#include "../Model/MeshVertices.cpp"

namespace MeshObjects {
    MeshVertices* Cube() {
        MeshVertices* meshConfig = new MeshVertices();

        //Top
        meshConfig -> addVertexRow(0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        //Front
        meshConfig -> addVertexRow(-0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        //Right
        meshConfig -> addVertexRow(-0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        //Left
        meshConfig -> addVertexRow(0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        //Back
        meshConfig -> addVertexRow(0.25f, 0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, 0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        //Bottom
        meshConfig -> addVertexRow(0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(0.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(0.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, -0.25f);
        meshConfig -> addTexCoordRow(1.0f, 0.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> addVertexRow(-0.25f, -0.25f, 0.25f);
        meshConfig -> addTexCoordRow(1.0f, 1.0f);
        meshConfig -> storeThisArray();
    
        meshConfig -> storeIndices(3, 1, 0);
        meshConfig -> storeIndices(2, 1, 3);
        meshConfig -> storeIndices(7, 5, 4);
        meshConfig -> storeIndices(6, 5, 7);
        meshConfig -> storeIndices(11, 9, 8);
        meshConfig -> storeIndices(10, 9, 11);
        meshConfig -> storeIndices(15, 13, 12);
        meshConfig -> storeIndices(14, 13, 15);
        meshConfig -> storeIndices(19, 17, 16);
        meshConfig -> storeIndices(18, 17, 19);
        meshConfig -> storeIndices(20, 21, 23);
        meshConfig -> storeIndices(23, 21, 22);
        
        return meshConfig;
    }

    MeshVertices* Pyramid() {
        MeshVertices* meshConfig2 = new MeshVertices();

        //Bottom
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 1.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 1.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        //Left
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.0f, 0.5f, 0.0f);
        meshConfig2 -> addTexCoordRow(0.5f, 1.0f);
        meshConfig2 -> storeThisArray();
    
        //Back
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.0f, 0.5f, 0.0f);
        meshConfig2 -> addTexCoordRow(0.5f, 1.0f);
        meshConfig2 -> storeThisArray();
    
        //Right
        meshConfig2 -> addVertexRow(0.25f, 0.0f, -0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.0f, 0.5f, 0.0f);
        meshConfig2 -> addTexCoordRow(0.5f, 1.0f);
        meshConfig2 -> storeThisArray();
    
        //Front
        meshConfig2 -> addVertexRow(0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(1.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(-0.25f, 0.0f, 0.25f);
        meshConfig2 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig2 -> storeThisArray();
    
        meshConfig2 -> addVertexRow(0.0f, 0.5f, 0.0f);
        meshConfig2 -> addTexCoordRow(0.5f, 1.0f);
        meshConfig2 -> storeThisArray();
    
    
        meshConfig2 -> storeIndices(2, 1, 0);
        meshConfig2 -> storeIndices(3, 2, 0);
        meshConfig2 -> storeIndices(5, 6, 4);
        meshConfig2 -> storeIndices(8, 9, 7);
        meshConfig2 -> storeIndices(11, 12, 10);
        meshConfig2 -> storeIndices(14, 15, 13);

        return meshConfig2;
    }

    MeshVertices* Floor() {
        MeshVertices* meshConfig3 = new MeshVertices();

        //Floor
        meshConfig3 -> addVertexRow(-3.0f, 0.0f, 3.0f);
        meshConfig3 -> addTexCoordRow(0.0f, 0.0f);
        meshConfig3 -> storeThisArray();
    
        meshConfig3 -> addVertexRow(-3.0f, 0.0f, -3.0f);
        meshConfig3 -> addTexCoordRow(0.0f, 6.0f);
        meshConfig3 -> storeThisArray();
    
        meshConfig3 -> addVertexRow(3.0f, 0.0f, -3.0f);
        meshConfig3 -> addTexCoordRow(6.0f, 6.0f);
        meshConfig3 -> storeThisArray();
    
        meshConfig3 -> addVertexRow(3.0f, 0.0f, 3.0f);
        meshConfig3 -> addTexCoordRow(6.0f, 0.0f);
        meshConfig3 -> storeThisArray();
    
        meshConfig3 -> storeIndices(0, 1, 2);
        meshConfig3 -> storeIndices(0, 2, 3);

        return meshConfig3;
    }
}
#endif
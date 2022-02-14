#include "PlayState.h"

#include "../../Model/Model.cpp"

void PlayState::onCreate() {
    MeshVertices meshConfig;

    //Front
    meshConfig.addVertexRow(-0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    //Right
    meshConfig.addVertexRow(-0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    //Left
    meshConfig.addVertexRow(0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    //Back
    meshConfig.addVertexRow(0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    //Top
    meshConfig.addVertexRow(0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, 0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, 0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    //Bottom
    meshConfig.addVertexRow(0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(0.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(0.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, -0.25f);
    meshConfig.addTexCoordRow(1.0f, 0.0f);
    meshConfig.storeThisArray();

    meshConfig.addVertexRow(-0.25f, -0.25f, 0.25f);
    meshConfig.addTexCoordRow(1.0f, 1.0f);
    meshConfig.storeThisArray();

    meshConfig.storeIndices(0, 1, 3);
    meshConfig.storeIndices(3, 1, 2);
    meshConfig.storeIndices(4, 5, 7);
    meshConfig.storeIndices(7, 5, 6);
    meshConfig.storeIndices(8, 9, 11);
    meshConfig.storeIndices(11, 9, 10);
    meshConfig.storeIndices(12, 13, 15);
    meshConfig.storeIndices(15, 13, 14);
    meshConfig.storeIndices(16, 17, 19);
    meshConfig.storeIndices(19, 17, 18);
    meshConfig.storeIndices(20, 21, 23);
    meshConfig.storeIndices(23, 21, 22);

    MeshVertices meshConfig2;

    //Bottom
    meshConfig2.addVertexRow(-0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(0.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(-0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(0.0f, 1.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(1.0f, 1.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(1.0f, 0.0f);
    meshConfig2.storeThisArray();

    //Left
    meshConfig2.addVertexRow(-0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(1.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(-0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(0.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.0f, 0.5f, 0.0f);
    meshConfig2.addTexCoordRow(0.5f, 1.0f);
    meshConfig2.storeThisArray();

    //Back
    meshConfig2.addVertexRow(-0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(1.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(0.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.0f, 0.5f, 0.0f);
    meshConfig2.addTexCoordRow(0.5f, 1.0f);
    meshConfig2.storeThisArray();

    //Right
    meshConfig2.addVertexRow(0.25f, 0.0f, -0.25f);
    meshConfig2.addTexCoordRow(1.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(0.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.0f, 0.5f, 0.0f);
    meshConfig2.addTexCoordRow(0.5f, 1.0f);
    meshConfig2.storeThisArray();

    //Front
    meshConfig2.addVertexRow(0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(1.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(-0.25f, 0.0f, 0.25f);
    meshConfig2.addTexCoordRow(0.0f, 0.0f);
    meshConfig2.storeThisArray();

    meshConfig2.addVertexRow(0.0f, 0.5f, 0.0f);
    meshConfig2.addTexCoordRow(0.5f, 1.0f);
    meshConfig2.storeThisArray();


    meshConfig2.storeIndices(0, 1, 2);
    meshConfig2.storeIndices(0, 2, 3);
    meshConfig2.storeIndices(4, 6, 5);
    meshConfig2.storeIndices(7, 9, 8);
    meshConfig2.storeIndices(10, 12, 11);
    meshConfig2.storeIndices(13, 15, 14);

    square.create(meshConfig);
    square.setPosition(0, 0, -1);
    square.setTexture("Assets/images/feesh/FeeshPixel.png", REGULAR, REPEAT, LINEAR, 1);
    this -> add(square);

    funniObject.create(meshConfig2);
    funniObject.setPosition(-1.25, -0.25, -1);
    funniObject.setTexture("Assets/images/feesh/Feesh.png", REGULAR, REPEAT, LINEAR, 1);
    this -> add(funniObject);

    lightsource.setPosition(0, 0, 0);
    lightsource.setColor(Matrix::useVec3(1, 1, 1));
    this -> add(lightsource);
}

void PlayState::update(float elapsed) {
    daCamera -> setRotation(control.getMouseRot(Y) * 100, control.getMouseRot(X) * 100, 0.0f);

    if(control.GetKeyHolding(Keys::R) || control.GetKeyHolding(Keys::SPACE)) {
        square.setRotation(0, square.getRotation(Y) + (elapsed * 100), 0.0f);

        funniObject.setRotation(0, funniObject.getRotation(Y) - (elapsed * 100), 0.0f);
    }

    if(control.GetKeyHolding(Keys::S)) {
        daCamera -> moveBackwards(elapsed);
    }

    if(control.GetKeyHolding(Keys::A)) {
        daCamera -> moveLeft(elapsed);
    }

    if(control.GetKeyHolding(Keys::D)) {
        daCamera -> moveRight(elapsed);
    }

    if(control.GetKeyHolding(Keys::W)) {
        daCamera -> moveForward(elapsed);
    }

    //daCamera -> setAsFPS();
}

PlayState::~PlayState() {

}
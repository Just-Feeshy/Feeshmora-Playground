#include "PlayState.h"

#include "../../Model/Model.cpp"

void PlayState::onCreate() {
    
    
    MeshVertices meshConfig4;

    //Front
    meshConfig4.addVertexRow(-0.25f, 0.5f, -0.25f);
    meshConfig4.addTexCoordRow(0.0f, 1.0f);
    meshConfig4.storeThisArray();

    meshConfig4.addVertexRow(-0.25f, -0.25f, -0.25f);
    meshConfig4.addTexCoordRow(0.0f, 0.0f);
    meshConfig4.storeThisArray();

    meshConfig4.addVertexRow(-0.25f, -0.25f, 0.25f);
    meshConfig4.addTexCoordRow(1.0f, 0.0f);
    meshConfig4.storeThisArray();

    meshConfig4.addVertexRow(-0.25f, 0.5f, 0.25f);
    meshConfig4.addTexCoordRow(1.0f, 1.0f);
    meshConfig4.storeThisArray();

    meshConfig4.storeIndices(0, 1, 3);
    meshConfig4.storeIndices(3, 1, 2);

    square = new Model();
    
    square -> create(MeshObjects::Cube());
    square -> setPosition(0, 1, -1);
    square -> setTexture("Assets/images/feesh/FeeshPixel.png", REGULAR, REPEAT, LINEAR, 1, DIFFUSE);
    this -> add(square);

    funniObject = new Model();

    funniObject -> create(MeshObjects::Pyramid());
    funniObject -> setPosition(-1.25, 0.75, -1);
    funniObject -> setTexture("Assets/images/feesh/Feesh.png", REGULAR, REPEAT, LINEAR, 1, DIFFUSE);
    //funniObject -> setAlpha(0.5);
    this -> add(funniObject);

    badman = new Entity();
    
    badman -> create(&meshConfig4);
    badman -> setPosition(0.5, 0, 0);
badman -> setTexture("Assets/images/BadManEvil.png", REGULAR, REPEAT, LINEAR, 1, DIFFUSE);
    badman -> setTexture("Assets/images/BadManEvil.png", REGULAR, REPEAT, LINEAR, 1, SPECULAR);
    this -> add(badman);

    floor = new Model();

    floor -> create(MeshObjects::Floor());
    floor -> setPosition(-1.25, -0.25, -1);
    floor -> setTexture("Assets/textures/wood.png", REGULAR, REPEAT, LINEAR, 1, DIFFUSE);
    floor -> setTexture("Assets/textures/wood-disp.png", REGULAR, REPEAT, LINEAR, 1, SPECULAR);
    this -> add(floor);

    lightsource = new SpotLight();
    
    lightsource -> setPosition(0, 0.25, 0);
    lightsource -> setColor(Matrix::useVec3(1, 1, 1));
    lightsource -> setIntensity(1);
    lightsource -> setLinear(3.0);
    lightsource -> setConstant(0.7);
    lightsource -> castLight(false);
    this -> add(lightsource);

    lightsource2 = new PointLight();
    
    lightsource2 -> setPosition(0, 0.5, 0);
    lightsource2 -> setColor(Matrix::useVec3(1, 1, 1));
    lightsource2 -> setIntensity(5);
    this -> add(lightsource2);

    sun = new DirectionalLight();
    
    sun -> setIntensity(0.15);
    this -> add(sun);
}

void PlayState::update(float elapsed) {
    AdvancedStates::update(elapsed);
    
    daCamera -> setRotation(control.getMouseRot(Y) * 100, (control.getMouseRot(X) * 100), 0.0f);

    if(true) {
        square -> setRotation(0, square -> getRotation(Y) + (elapsed * 100), 0.0f);

        funniObject -> setRotation(0, funniObject -> getRotation(Y) - (elapsed * 100), 0.0f);

        lightsource -> setRotation(0, 180, 0);

        lightsource -> setPosition(daCamera -> getPosition(X), daCamera -> getPosition(Y), daCamera -> getPosition(Z));
    }

    if(PathFinder::getDistance(badman -> getPosition(), daCamera -> getPosition()) > 0.1) {
        badman -> setRotation(0, PathFinder::getAngleThroughPath(badman -> getPosition(), daCamera -> getPosition()).y, 0);

        badman -> moveForward(elapsed/2);
    }

    if(control.GetKeyHolding(Keys::S)) {
        daCamera -> moveBackwards(-elapsed);
    }

    if(control.GetKeyHolding(Keys::A)) {
        daCamera -> moveLeft(-elapsed);
    }

    if(control.GetKeyHolding(Keys::D)) {
        daCamera -> moveRight(-elapsed);
    }

    if(control.GetKeyHolding(Keys::W)) {
        daCamera -> moveForward(-elapsed);
    }

    if(control.GetKeyHolding(Keys::Q)) {
        daCamera ->setPosition(daCamera -> getPosition(X), daCamera -> getPosition(Y) + elapsed, daCamera -> getPosition(Z));
    }

    if(control.GetKeyHolding(Keys::E)) {
        daCamera -> setPosition(daCamera -> getPosition(X), daCamera -> getPosition(Y) - elapsed, daCamera -> getPosition(Z));
    }
}

PlayState::~PlayState() {
    if(square != nullptr) { 
        delete square;
    }

    if(funniObject != nullptr) {
        delete funniObject;
    }

    if(floor != nullptr) {
        delete floor;
    }

    if(badman != nullptr) {
        delete badman;
    }

    if(lightsource != nullptr) {
        delete lightsource;
    }

    if(lightsource2 != nullptr) {
        delete lightsource2;
    }

    if(sun != nullptr) {
        delete sun;
    }
}
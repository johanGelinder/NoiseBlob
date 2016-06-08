#pragma once

#include "ofMain.h"
#include "blob.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void initialize();
    void randomizeScene();
    
    //// ASSIGN MIN/MAX VALUES ////
    float SPHERE_RADIUS = 180;
    float MAX_SPEED_NOISE = 0.025;
    float MIN_FREQ_NOISE = 60;
    float MAX_FREQ_NOISE = 200;
    float GOLDEN_RATIO = (sqrt(5)+1)/2 ;
    float nv;
    int Nums = 40000; // Number of particles
    int move;
    ofVec3f noiseSpeed, noiseFreq, noise, p; // Initialize all the different 3D vectors
    vector<unique_ptr<Blob>> b; // Creating a vector of unique pointers
    
};

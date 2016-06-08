#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate( 30 ); // Lower the framerate to 30fps
    initialize(); // Create all the objects
    randomizeScene(); // Create a random scene
    ofBackground(0); // Black background
   // ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
   // move +=2;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0); // Translate to the middle of the screen
    //ofRotateY(ofMap(move, 0, ofGetWidth(), -40, 40));
    ofRotateX(45); // Rotate the sphere by 45 degrees
    noise += noiseSpeed; // Adding noiseSpeed to the noise vector
    
    for ( int i = 0; i < Nums; ++ i ) { // Looping through the particles
        //// SETTING THE X, Y, Z COORDINATES OF THE VECTOR P ////
        p.x = b[i]->x / noiseFreq.x;
        p.y = b[i]->y / noiseFreq.y;
        p.z = b[i]->z / noiseFreq.z;
        
        nv = ofNoise(p.x + noise.x, p.y + noise.y, p.z + noise.z); // Assign noise the the variable nv
        float le = ofMap( i, 0, Nums, 0, 255 ); // Map colour
        ofColor c1 = ofColor( 255, 255, 255 ); // First colour
        ofColor c2 = ofColor( 160, le, 240 ); // Second colour
        ofColor lerpColor = c1.lerp( c2 , 1 ); // Colour interpolation
        //ofSetColor(255+nv*80, 200*nv,100, 250); // wiiieerd colours
        ofSetColor( lerpColor ); // Setting the colour
        nv *= 25; // Multiplying to add more noise
        
        ofDrawCircle( b[i]->x+nv, b[i]->y+nv ,b[i]->z, 0.7 ); // Draw the particles with noise
    }
    ofPopMatrix();
}

void ofApp::initialize() {
    
    for ( int i = 0; i < Nums; i ++ ) { // Looping through all the particles
        
        float longitude = GOLDEN_RATIO * i; // Set the longitude to the golden ration multiplied by each particle
        longitude -= floor( longitude ); // Flooring it
        longitude *= TWO_PI; // Rotate 360 degrees ( Full Circle )
        float latitude = asin( -1.0 + 2.0 * i / Nums );
        
        //// FILL THE VECTOR AND ASSIGN THE POSITIONS ////
        b.emplace_back( new Blob( SPHERE_RADIUS * cos(latitude) * cos(longitude),
                                 SPHERE_RADIUS * cos(latitude) * sin(longitude),
                                 SPHERE_RADIUS * sin(latitude)));
    }
}

void ofApp::randomizeScene() {
    
    //// ASSIGNING RANDOM VALUES ////
    noiseSpeed.x = ofRandom( MAX_SPEED_NOISE );
    noiseSpeed.y = ofRandom( MAX_SPEED_NOISE );
    noiseSpeed.z = ofRandom( MAX_SPEED_NOISE );
    noiseFreq.x = ofRandom( MIN_FREQ_NOISE, MAX_FREQ_NOISE );
    noiseFreq.y = ofRandom( MIN_FREQ_NOISE, MAX_FREQ_NOISE );
    noiseFreq.z = ofRandom( MIN_FREQ_NOISE, MAX_FREQ_NOISE );
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    randomizeScene(); // Create a new random scene
   
}



#pragma once
#include "ofMain.h"

class Particles {
public:
    Particles(int maxParticles);
    void update();
    void draw();
    void addParticle(ofVec2f position,
                     ofVec2f velocity = ofVec2f(0, 0),
                     ofColor color = 0xffffff);
    void resetForce();
    void addForce(int count, ofVec2f force);
    void addDampingForce();
    void resetOffWalls();
    void updatePos();
    
    int maxParticles;
    float pointSize;
    
    int numParticles;
    deque<ofVec3f> positions;
    deque<ofVec3f> velocitys;
    deque<ofVec3f> forces;
    deque<ofColor> colors;
    float friction;
    
    
    ofVboMesh mesh;
    ofMesh myMesh;
    
    
};

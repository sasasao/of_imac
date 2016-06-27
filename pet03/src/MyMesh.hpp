#pragma once
#include "ofMain.h"

class MyMesh{
    
public:
    MyMesh();
    void update();
    void draw();
    
    ofMesh myMesh;
    int h;
    
};
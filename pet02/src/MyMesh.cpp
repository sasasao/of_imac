#include "MyMesh.hpp"



MyMesh::MyMesh(){
    myMesh = ofSpherePrimitive(200,72).getMesh();
    for (int i=0; i<myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0,1.0,1.0,1.0));
    }
}


void MyMesh::update(){
    for(int i=0; i<myMesh.getVertices().size(); i++){
        ofVec3f loc = myMesh.getVertices()[i] / 300.0;
        
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z,ofGetElapsedTimef()), 0, 1, 80, 240);
        ofVec3f newLoc = loc.normalize()*noise;
        myMesh.setVertex(i, newLoc);
        
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 0.5, 1.0);
        myMesh.setColor(i, ofFloatColor(c,c,c,1.0));
    }
}

void MyMesh::draw(){
    myMesh.draw();
}

#include "MyMesh.hpp"


MyMesh::MyMesh(float _zone_focus, float _zone_calm, float _zone_posture) {
    zone_focus = _zone_focus;
    zone_calm = _zone_calm;
    zone_posture = _zone_posture;
}

void MyMesh::draw(){
    
    
    /*for (int i=0; i<100; i++) {
        float pos = ofMap(ofRandom(i), 0,i, 0, ofGetWidth());
        float posY = ofMap(ofRandom(i), 0,i, 0, ofGetWidth());
        float newPos = pos + ofMap(ofRandom(i), 0,i, 0, ofGetWidth());
        float newPosY = pos + ofMap(ofRandom(i), 0,i, 0, ofGetWidth());
        ofTranslate(newPos, newPosY);
        //ofRotateY(ofGetElapsedTimef()*10.0);
        myMesh.draw();
        
    }*/
    
}

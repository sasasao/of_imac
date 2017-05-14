#include "ofApp.h"

#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    
    tileWidth = ofGetWidth() / tileCountX;
    tileHeight = ofGetHeight() / tileCountY;
}

void ofApp::update(){
    
}

void ofApp::draw(){
 
    ofSetColor(0,0,0);
    ofNoFill();
    ofSeedRandom(actRandomSeed);
//    ofRandom(actRandomSeed);
    
    ofTranslate((ofGetWidth() / tileCountX) /2, (ofGetHeight() / tileCountY) / 2);
    
    circleCount = mouseX/100 + 1;
    endSize = ofMap(mouseX, 0, ofGetWidth(), tileWidth/2.0, 0);
    endOffset = ofMap(mouseY, 0, ofGetHeight(), 0, (tileWidth - endSize) /2);
    
    for (int gridY = 0; gridY <= tileCountY; gridY++) {
        for (int gridX = 0; gridX <= tileCountX; gridX++) {
            ofPushMatrix();
            ofTranslate(tileWidth * gridX, tileHeight * gridY);
            ofScale(1, tileHeight / tileWidth);
            
//            int toggle = (int) ofRandom(0, 4);
            int toggle = ofRandom(0,4);
            if (toggle == 0) ofRotate(-HALF_PI);
            if (toggle == 1) ofRotate(0);
            if (toggle == 2) ofRotate(HALF_PI);
            if (toggle == 3) ofRotate(PI);
            
            for (int i = 0; i < circleCount; i++) {
                float diameter = ofMap(i, 0, circleCount-1, tileWidth, endSize);
                float offset = ofMap(i, 0, circleCount-1, 0, endOffset);
                ofDrawRectangle(offset, 0, diameter, diameter);
//                ofDrawEllipse(offset, 0, diameter, diameter);
            }
            ofPopMatrix();
        }
    }
    
}


void ofApp::mousePressed(int x, int y, int button){
    actRandomSeed = ofRandom(10000);
}




void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

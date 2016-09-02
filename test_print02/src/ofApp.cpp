#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundAuto(false);
    
    //ofSetWindowShape(5000,10000);
    for(int i=0; i<100; i++){
        posX[i]=ofRandom(ofGetWidth());
        posY[i]=ofRandom(ofGetHeight());
    }
    ofTrueTypeFont::setGlobalDpi(150);
    ofBeginSaveScreenAsPDF("text_print" + ofGetTimestampString() + " .ai");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    //ofEnableAlphaBlending();
    ofBackground(74,158,216);
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    float size1 = 30;
    float size2 = 15;
    float pos = 190;
    float posY = 330;
    
    /*ofPushMatrix();
    for (int t=0; t<size1; t+=size1){
        for (int h=0; h<size1; h+=size1) {
            for(float g=0; g<20; g+= 0.1){
                
                ofSetLineWidth(1);
                ofSetColor(255);
                ofNoFill();
                ofSetCircleResolution(3);
                ofRotate(500);
                
                ofDrawCircle(t*3, h*3, g*10+size1);
                
                ofSetLineWidth(15);
                ofDrawCircle(t*3+pos*2, h*3, size2);
                ofDrawCircle(t*3-pos, h*3-posY+g*20, size2);
                ofDrawCircle(t*3-pos, h*3+posY-g*20, size2);
                
            }
        }
    }
    ofPopMatrix();
    */
    ofSetColor(255, 0 , 0);
    ofSetLineWidth(10);
    
    for(int i=0; i<TWO_PI*2; i+=1){
        float x = sin(i)*100;
        float y = cos(i)*100;
        ofBeginShape();
        ofVertex(x,y);
        ofEndShape();
        
    }
    
    ofBeginShape();
    ofVertex(100,0);
    ofVertex(200,100);
    ofVertex(ofGetWidth(), ofGetHeight());
    ofEndShape();
    
    
    ofFill();
    ofSetColor(255, 0, 0);
    //ofRotate(10);
    //ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, 100, 100);
    
    
    if(loop){
        ofEndSaveScreenAsPDF();
        loop = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's')
        loop = true;
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
void ofApp::mousePressed(int x, int y, int button){

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

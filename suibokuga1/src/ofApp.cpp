#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    myImage.load("min4.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //画像データのビットマップ情報を配列に格納
    unsigned char * pixels = myImage.getPixels();
    
    int w = myImage.getWidth();
    int h = myImage.getHeight();
    
    for (int i = 0; i < w; i+=2){
        for (int j = 0; j < h; j+=2){
            int value = pixels[j*3 * w + i*3];
            ofSetColor(value/3);
            ofDrawCircle(i, j, 2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    img.save("min44.jpg");
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

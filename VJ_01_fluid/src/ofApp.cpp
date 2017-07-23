#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
    ofSetBackgroundAuto(true);

    x = mouseX;
    y = mouseY;
    
    snd.load("Sorry.mp3");
    snd.setVolume(0.05f);
    lineModule.load("01.png");
    snd.play();
    snd.setLoop(true);
    
    nBandsToGet = 1024;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(2.0);
    ofBeginShape();
    
    ofTranslate(0, -ofGetHeight()/2);
    
    for (int i = 0; i < nBandsToGet; i++) {
        float x = ofMap(i, 0, fft[i], 0, ofGetWidth());
        float y = ofMap(fft[i], 0, 1, ofGetHeight(), 0);
        
//        lineModule.draw(i ,y, 10,y);
        for (int n = 0; n < ofGetWidth(); n+=50) {
            lineModule.draw(i*50 ,y, 60,60);
        }
        lineModule.draw(ofGetWidth()/2 ,y, 60,60);
        ofVertex(i, y+ofGetHeight()/2);
    }
    
    ofEndShape();
    
//    ofSetLineWidth(ofGetWidth() / float(nBandsToGet) / 2.0 - 0.5);
//    for (int i = 0; i < buffer.size(); i++) {
//        float hue = ofMap(i, 0, buffer.size(), 0, 160);
//        ofColor col;
//        col.setHsb(hue, 255, 255);
//        ofSetColor(col);
//        
//        
//        float rx = ofMap(i, 0, buffer.size(), 0, 360);
//        float lx = ofMap(i, 0, buffer.size(), ofGetWidth(), 0);
//        float y = ofMap(fftSmoothed[i], 0, 1, ofGetHeight()/2, 0) ;
//        ofDrawLine(rx, ofGetHeight()/2, rx, y);
//        ofDrawLine(lx, ofGetHeight()/2, lx, y);
//    
//
//        float d = ofDist(x, y, mouseX, mouseY);
////            float angle = atan2(mouseY - y, mouseX - x);
//            float angle = rx;
//            
//            ofPushMatrix();
//            ofTranslate(0, y);
////            ofTranslate(0, ofGetHeight()/2);
////            ofRotate(angle + PI *2);
//            lineModule.draw(lx ,0, mouseSize, y);
//            ofPopMatrix();
//            
//            x = x + cos(angle) * stepSize;
//            y = y + sin(angle) * stepSize;
//    }
    
}



//--------------------------------------------------------------
void ofApp::mousePressed(){
    x = mouseX;
    y = mouseY;
}


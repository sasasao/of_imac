#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    output.noFill();
    output.setLineWidth(1);
    ofSetBackgroundColor(255);
    logView = ofPoint(20, ofGetHeight() - 50);
    
    //ofxUI
    gui0 = new ofxUISuperCanvas("deckGenarator");
    gui0->addSpacer();
    gui0->addLabel("A4 PAPER GUIDE");
    gui0->addToggle("A4 PAPER GUIDE", &bA4, 44, 44);
    gui0->addSpacer();
    gui0->addLabel("SAVE");
    gui0->addButton("SAVE", &capture, 44, 44);
    gui0->addSpacer();
    gui0->autoSizeToFitWidgets();
    
    //xmlsettings
    settings.loadFile("settings.xml");
    param01 = settings.getValue("settings:ui1", 0.0);
    param02 = settings.getValue("settings:ui2", 0.0);
    param03 = settings.getValue("settings:ui3", 0.0);
    param04 = settings.getValue("settings:ui4", 0.0);
    param05 = settings.getValue("settings:ui5", 0.0);
    param06 = settings.getValue("settings:ui6", 0.0);
    param07 = settings.getValue("settings:ui7", 0.0);
    param08 = settings.getValue("settings:ui8", 0.0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //A4 paper guide
    for (int i = 2; i < 5; i++) if (param05 > A4Height * (i - 1) && param05 <= A4Height * i) pNum = i;
    
    //logs
    if (logAlpha > 0) logAlpha-=1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // capture output data
    if (capture) {
        fileName = ofToString(ofGetYear()) + "_" + ofToString(ofGetMonth()) + "_" + ofToString(ofGetDay()) + "_" + ofToString(ofGetHours()) + "_" + ofToString(ofGetMinutes()) + "_" + ofToString(ofGetSeconds()) + ".ai";
        output.beginEPS(fileName);
    }

    
    ofSetColor(0, 0, 0);
    ofNoFill();
    output.bezier(100,150,200,250,
                  300,350,400,450);
    
    
    //A4 paper guide
    if (bA4) A4Paper(pNum);
    if (capture){
        capture = false;
        output.endEPS();
        logAlpha = 255;
    }
    
    //graphic event when saved
    ofFill();
    ofSetColor(255, 255, 0, logAlpha / 1.5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //logs
    ofSetColor(0, 122, 0, logAlpha);
    ofDrawBitmapString("Data has been saved as " + fileName, logView.x, logView.y);
}

void ofApp::exit()
{
    //xmlsettings
    settings.setValue("settings:ui1", param01);
    settings.setValue("settings:ui2", param02);
    settings.setValue("settings:ui3", param03);
    settings.setValue("settings:ui4", param04);
    settings.setValue("settings:ui5", param05);
    settings.setValue("settings:ui6", param06);
    settings.setValue("settings:ui7", param07);
    settings.setValue("settings:ui8", param08);
    settings.saveFile("settings.xml");
    
    //UI
    delete gui0;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

/*
void ofApp::trackPos(ofPoint & tp){
}

void ofApp::lengthInfo(ofPoint &p1, ofPoint &p2, float d){
}
*/

void ofApp::A4Paper(int n){
    output.setColor(0, 0, 200);
    for (int p = 0; p < n; p++) output.rect(ofGetWidth() / 2 - A4Width / 2, ofGetHeight() / 2 - A4Height * (float(n) / 2 - p),A4Width, A4Height);
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

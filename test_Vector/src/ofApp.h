#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxUI.h"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void A4Paper(int n);
    
    
    //UI
    ofxUISuperCanvas *gui0;
    void guiEvent(ofxUIEventArgs &e);
    void exit();
    
    //xmlsettings
    ofxXmlSettings settings;
    
    //Vector graphics
    ofxVectorGraphics output;
    
    bool capture = false;
    
    int   param01, param02, param03, param04, param05, param06, param07, param08,
    logAlpha = 0, pNum;
    ofPoint logView;
    
    const float
    A4Width       = 297.0,
    A4Height      = 210.0;
    string fileName;
    bool bA4;
};

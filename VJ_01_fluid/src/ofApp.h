#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed();
    

    
    ofSoundPlayer  snd;
    float * fft;
    int nBandsToGet;
    
    ofImage lineModule;
    Boolean recordPDF;
    float x = 0, y = 0;
    float stepSize = 5.0;
    float mouseSize = 25;
    
};

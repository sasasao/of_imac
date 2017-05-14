#pragma once

#include "ofMain.h"

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
		
    int s = 100;
    
    float tileCountX = 10;
    float tileCountY = 10;
    float tileWidth, tileHeight;
    
    int count = 0;
    int colorStep = 15;
    int circleCount;
    float endSize, endOffset;
    
    int actRandomSeed = 0;

};

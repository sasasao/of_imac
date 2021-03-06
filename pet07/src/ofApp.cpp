#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    light.enable();
    light.setPosition(-100, 100, -1000);
    cam.setDistance(1000);
    
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    pixels = myImage.getPixels();
    
    particleNum = 5;
    particles = new Particles(particleNum);
    
    ofVec3f position = ofVec3f(ofRandom(width), ofRandom(height));
    particles->addParticle(position);
    
    
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, width, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
    myImage.update();
    
    scaleX.addListener(this, &ofApp::scaleXChanged);
    scaleY.addListener(this, &ofApp::scaleYChanged);
    
    gui.setup();
    gui.add(speed.setup("speed", 0.1, 0.0, 0.5));
    gui.add(friction.setup("friction", 0.01, 0.0, 0.04));
    gui.add(scaleX.setup("scale x", 5.0, 1.0, 10.0));
    gui.add(scaleY.setup("scale y", 5.0, 1.0, 10.0));
}

//--------------------------------------------------------------
void ofApp::scaleXChanged(float & scaleX){
    updateNoise();
}

//--------------------------------------------------------------
void ofApp::scaleYChanged(float & scaleY){
    updateNoise();
}

void ofApp::updateNoise(){
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, width, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    particles->friction = friction;
    particles->resetForce();
    for (int i = 0; i < particleNum; i++) {
        int n = int(particles->positions[i].y) * width + int(particles->positions[i].x);
        if(n < width * height){
            int val = pixels[n];
            int angle = ofMap(val, 0, 255, 0, PI*2.0);
            ofVec3f force;
            force.x = cos(angle) * speed;
            force.y = sin(angle) * speed;
            particles->addForce(i, force);
        }
    }
    particles->addDampingForce();
    particles->updatePos();
    particles->resetOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255);
    
    ofPushMatrix();
    ofRotateY(ofGetElapsedTimef()*10.0);
    for (int i = 0; i < particleNum; i++) {
        particles->draw();
    }
    ofPopMatrix();
    cam.end();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    gui.draw();
}

//--------------------------------------------------------------
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
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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

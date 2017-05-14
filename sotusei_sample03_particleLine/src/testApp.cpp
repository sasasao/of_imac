#include "testApp.hpp"

char sz[] = "[Rd9?-2XaUP0QY[hO%9QTYQ`-W`QZhcccYQY[`b";


float tuioXScaler = 1;
float tuioYScaler = 1;

//--------------------------------------------------------------
void testApp::setup() {
    for(int i=0; i<strlen(sz); i++) sz[i] += 20;
    
    // setup fluid stuff
    fluidSolver.setup(100, 100);
    fluidDrawer.setup(&fluidSolver);
    
    fluidCellsX			= 150;
    
    drawFluid			= false;
    drawParticles		= true;
    
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetColor(0, 0, 0, 0.1);
    ofSetVerticalSync(false);
    ofSetBackgroundAuto(true);
   
    
#ifdef USE_GUI
    gui.addSlider("fluidCellsX", fluidCellsX, 20, 400);
    gui.addButton("resizeFluid", resizeFluid);
    gui.addSlider("colorMult", colorMult, 0, 100);
    gui.addSlider("velocityMult", velocityMult, 0, 100);
    gui.addSlider("fs.viscocity", fluidSolver.viscocity, 0.0, 0.01);
    gui.addSlider("fs.colorDiffusion", fluidSolver.colorDiffusion, 0.0, 0.0003);
    gui.addSlider("fs.fadeSpeed", fluidSolver.fadeSpeed, 0.0, 0.1);
    gui.addSlider("fs.solverIterations", fluidSolver.solverIterations, 1, 50);
    gui.addSlider("fs.deltaT", fluidSolver.deltaT, 0.1, 5);
    gui.addComboBox("fd.drawMode", (int&)fluidDrawer.drawMode, msa::fluid::getDrawModeTitles());
//    gui.addToggle("fs.doRGB", fluidSolver.doRGB);
//    gui.addToggle("fs.doVorticityConfinement", fluidSolver.doVorticityConfinement);
//    gui.addToggle("drawFluid", drawFluid);
//    gui.addToggle("drawParticles", drawParticles);
//    gui.addToggle("fs.wrapX", fluidSolver.wrap_x);
//    gui.addToggle("fs.wrapY", fluidSolver.wrap_y);
//    gui.addSlider("tuioXScaler", tuioXScaler, 0, 2);
//    gui.addSlider("tuioYScaler", tuioYScaler, 0, 2);
    
    gui.currentPage().setXMLName("ofxMSAFluidSettings.xml");
    gui.loadFromXML();
    gui.setDefaultKeys(true);
    gui.setAutoSave(true);
    gui.show();
#endif
    
    windowResized(ofGetWidth(), ofGetHeight());		// force this at start (cos I don't think it is called)
    pMouse = msa::getWindowCenter();
    resizeFluid			= true;
    
//    ofEnableAlphaBlending();
    
}


void testApp::fadeToColor(float r, float g, float b, float speed) {
    glColor4f(r, g, b, speed);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}


// add force and dye to fluid, and create particles
void testApp::addToFluid(ofVec2f pos, ofVec2f vel, bool addColor, bool addForce) {
    float speed = vel.x * vel.x  + vel.y * vel.y * msa::getWindowAspectRatio() * msa::getWindowAspectRatio();    // balance the x and y components of speed with the screen aspect ratio
    if(speed > 0) {
        pos.x = ofClamp(pos.x, 0.0f, 1.0f);
        pos.y = ofClamp(pos.y, 0.0f, 1.0f);
        
        int index = fluidSolver.getIndexForPos(pos);
        
        if(addColor) {
            //			Color drawColor(CM_HSV, (getElapsedFrames() % 360) / 360.0f, 1, 1);
            ofColor drawColor;
            drawColor.setHsb((ofGetFrameNum() % 255), 255, 255);
            
            fluidSolver.addColorAtIndex(index, drawColor * colorMult);
            
            if(drawParticles)
                particleSystem.addParticles(pos * ofVec2f(ofGetWindowSize()), 10);
        }
        
        if(addForce)
            fluidSolver.addForceAtIndex(index, vel * velocityMult);
        
    }
}


void testApp::update(){
    if(resizeFluid) 	{
        fluidSolver.setSize(fluidCellsX, fluidCellsX / msa::getWindowAspectRatio());
        fluidDrawer.setup(&fluidSolver);
        resizeFluid = false;
    }
    
#ifdef USE_TUIO
    tuioClient.getMessage();
    
    // do finger stuff
    list<ofxTuioCursor*>cursorList = tuioClient.getTuioCursors();
    for(list<ofxTuioCursor*>::iterator it=cursorList.begin(); it != cursorList.end(); it++) {
        ofxTuioCursor *tcur = (*it);
        float vx = tcur->getXSpeed() * tuioCursorSpeedMult;
        float vy = tcur->getYSpeed() * tuioCursorSpeedMult;
        if(vx == 0 && vy == 0) {
            vx = ofRandom(-tuioStationaryForce, tuioStationaryForce);
            vy = ofRandom(-tuioStationaryForce, tuioStationaryForce);
        }
        addToFluid(ofVec2f(tcur->getX() * tuioXScaler, tcur->getY() * tuioYScaler), ofVec2f(vx, vy), true, true);
    }
#endif
    
    fluidSolver.update();
    t += 0.1;
}

void testApp::draw(){
    if(drawParticles)
        particleSystem.updateAndDraw(fluidSolver, ofGetWindowSize(), drawFluid);

    
    float r = 50;
    float x = t * 20;
    float y = sin(t) * r;
        
    for (int i=0; i<ofGetHeight(); i+=200) {
    
    ofDrawEllipse(x, y +i, 10, 10);
    eventPos = ofVec2f(x ,y +i);
    mouseNorm = ofVec2f(eventPos) / ofGetWindowSize();
    mouseVel = ofVec2f(10,0) / ofGetWindowSize();
    addToFluid(mouseNorm, mouseVel, true, true);
    pMouse = eventPos;
        
        if(x > ofGetWidth()){
            t = 0;
        }
    }
    
//#ifdef USE_GUI
//        gui.draw();
//#endif
}


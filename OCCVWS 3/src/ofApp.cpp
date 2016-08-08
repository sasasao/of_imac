#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFullscreen(true);
    ofSetWindowShape(1118, 3000);
    ofSetFrameRate(60);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetBackgroundAuto(false);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    light.enable();
    light.setPosition(-100, 100, 500);
    light.setAmbientColor(ofFloatColor(0.5));

    
    
    ofTrueTypeFont::setGlobalDpi(100);
    //font.loadFont("SourceHanCodeJP-Normal.otf",10,true,true);
    //font.loadFont("A-OTF-FolkPro-Regular.otf",10,true,true);
    font.loadFont("Bauhaus-Light.otf",15,true,true);
    
    
    //dataフォルダに配置したcsvファイルの名前
    string filePath = "003_ST.csv";
    string filePath1 = "002_ST.csv";
    loadCsvToMemes(filePath);
    loadCsvToMemes1(filePath1);
    
    
    sle = memes[index].sleepy;
    next_sle = memes[index+1].sleepy;
    foc = memes[index].focus;
    next_foc = memes[index+1].focus;
    eye = memes[index].eyeMoveRout;
    next_eye = memes[index+1].eyeMoveRout;
    cad = memes[index].cadence;
    next_cad = memes[index+1].cadence;
    bli = memes[index].blink;
    next_bli = memes[index+1].blink;
    
    sle1 = memes1[index1].sleepy1;
    next_sle1 = memes1[index1+1].sleepy1;
    foc1 = memes1[index1].focus1;
    next_foc1 = memes1[index1+1].focus1;
    eye1 = memes1[index1].eyeMoveRout1;
    next_eye1 = memes1[index1+1].eyeMoveRout1;
    cad1 = memes1[index1].cadence1;
    next_cad1 = memes1[index1+1].cadence1;
    bli1 = memes1[index1].blink1;
    next_bli1 = memes1[index1+1].blink1;
    
    ofBackground(255);
    

    
    
    
    
    
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    float values_sle[memes.size()];
    float values_foc[memes.size()];
    float values_eye[memes.size()];
    float values_cad[memes.size()];
    float values_bli[memes.size()];
    
    float values_sle1[memes1.size()];
    float values_foc1[memes1.size()];
    float values_eye1[memes1.size()];
    float values_cad1[memes1.size()];
    float values_bli1[memes1.size()];
    
    
    morph_sle = ofLerp(sle, next_sle, percent);
    morph_foc = ofLerp(foc, next_foc, percent);
    morph_eye = ofLerp(eye, next_eye, percent);
    morph_cad = ofLerp(cad, next_cad, percent);
    morph_bli = ofLerp(bli, next_bli, percent);
    
    morph_sle1 = ofLerp(sle1, next_sle1, percent);
    morph_foc1 = ofLerp(foc1, next_foc1, percent);
    morph_eye1 = ofLerp(eye1, next_eye1, percent);
    morph_cad1 = ofLerp(cad1, next_cad1, percent);
    morph_bli1 = ofLerp(bli1, next_bli1, percent);
    
    
    /*min_color = 0;
    color_sle = ofMap(morph_sle, min_value_sle, max_value_sle, min_color, 255);
    color_foc = ofMap(morph_foc, min_value_foc, max_value_foc, min_color, 255);
    color_eye = ofMap(morph_eye, min_value_eye, max_value_eye, min_color, 255);
    color_cad = ofMap(morph_cad, min_value_cad, max_value_cad, min_color, 255);
    color_bli = ofMap(morph_bli, min_value_bli, max_value_bli, min_color, 255);
    color_sle1 = ofMap(morph_sle1, min_value_sle1, max_value_sle1, min_color, 255);
    color_foc1 = ofMap(morph_foc1, min_value_foc1, max_value_foc1, min_color, 255);
    color_eye1 = ofMap(morph_eye1, min_value_eye1, max_value_eye1, min_color, 255);
    color_cad1 = ofMap(morph_cad1, min_value_cad1, max_value_cad1, min_color, 255);
    color_bli1 = ofMap(morph_bli1, min_value_bli1, max_value_bli1, min_color, 255);
    */
    
    min_colorB = 200;
    color_sleB = ofMap(morph_sle, min_value_sle, max_value_sle, min_colorB, 255);
    color_focB = ofMap(morph_foc, min_value_foc, max_value_foc, min_colorB, 255);
    color_eyeB = ofMap(morph_eye, min_value_eye, max_value_eye, min_colorB, 255);
    color_cadB = ofMap(morph_cad, min_value_cad, max_value_cad, min_colorB, 255);
    color_bliB = ofMap(morph_bli, min_value_bli, max_value_bli, min_colorB, 255);
    color_sle1B = ofMap(morph_sle1, min_value_sle1, max_value_sle1, min_colorB, 255);
    color_foc1B = ofMap(morph_foc1, min_value_foc1, max_value_foc1, min_colorB, 255);
    color_eye1B = ofMap(morph_eye1, min_value_eye1, max_value_eye1, min_colorB, 255);
    color_cad1B = ofMap(morph_cad1, min_value_cad1, max_value_cad1, min_colorB, 255);
    color_bli1B = ofMap(morph_bli1, min_value_bli1, max_value_bli1, min_colorB, 255);
    
    
    
    for (int i = 0; i < memes.size(); i++){
        Meme meme = memes[i];
        values_sle[i] = meme.sleepy;
        values_foc[i] = meme.focus;
        values_eye[i] = meme.eyeMoveRout;
        values_cad[i] = meme.cadence;
        values_bli[i] = meme.blink;
        
        Meme1 meme1 = memes1[i];
        values_sle1[i] = meme1.sleepy1;
        values_foc1[i] = meme1.focus1;
        values_eye1[i] = meme1.eyeMoveRout1;
        values_cad1[i] = meme1.cadence1;
        values_bli1[i] = meme1.blink1;
        
        
        
        ofSetLineWidth(2);
        ofNoFill();
        
        
        
        percent += 0.5;
    }
    
    
    //--------
    ofSetLineWidth(100);
    vertex_x = 6;
    
    ofSetColor(color_focB, 150,100, 100);
    ofBeginShape();
    ofVertex(morph_sle *vertex_x, h);
    ofVertex(morph_eye/10 *vertex_x, h);
    ofVertex(morph_foc *vertex_x, h);
    ofVertex(morph_cad *vertex_x, h);
    ofVertex(morph_bli *vertex_x, h);
    ofEndShape();
    
    ofSetColor(color_foc1B, 200,200, 100);
    ofBeginShape();
    ofVertex(-morph_sle1 *vertex_x + ofGetWidth(), h);
    ofVertex(-morph_eye1/10 *vertex_x + ofGetWidth(), h);
    ofVertex(-morph_foc1 *vertex_x + ofGetWidth(), h);
    ofVertex(-morph_cad1 *vertex_x + ofGetWidth(), h);
    ofVertex(-morph_bli1 *vertex_x + ofGetWidth(), h);
    ofEndShape();
     
     
    //--------
    eli_x = 10;
    eli_size = 10;
    eli_alpha = 100;
    ofSetLineWidth(1);
    ofNoFill();
    
    /*
    ofDrawEllipse(morph_sle *eli_x, h, eli_size, eli_size);
    ofDrawEllipse(morph_eye/10 *eli_x, h, eli_size, eli_size);
    ofDrawEllipse(morph_bli *eli_x, h, eli_size, eli_size);
    ofDrawEllipse(morph_foc *eli_x, h, eli_size, eli_size);
     
    ofSetColor(255, color_foc1,0, eli_alpha);
    ofDrawEllipse(-morph_sle1    *eli_x +ofGetWidth(), h, eli_size, eli_size);
    ofDrawEllipse(-morph_eye1/10 *eli_x +ofGetWidth(), h, eli_size, eli_size);
    ofDrawEllipse(-morph_bli1    *eli_x +ofGetWidth(), h, eli_size, eli_size);
    ofDrawEllipse(-morph_foc1    *eli_x +ofGetWidth(), h, eli_size, eli_size);*/
    
    //ofSetColor(color_focB, color_cadB, color_eyeB, 100);
    ofSetColor(color_foc, 200, 200);
    ofDrawEllipse(morph_sle    * eli_x + ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(morph_eye/10 * eli_x + ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(morph_bli    * eli_x + ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(morph_foc    * eli_x + ofGetWidth()/2, h, eli_size, eli_size);
    
    //ofSetColor(color_foc1B, color_cad1B, color_eye1B, 100);
    ofSetColor(color_foc1, 200, 200);
    ofDrawEllipse(-morph_sle1     * eli_x +ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(-morph_eye1/10  * eli_x +ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(-morph_bli1     * eli_x +ofGetWidth()/2, h, eli_size, eli_size);
    ofDrawEllipse(-morph_foc1     * eli_x +ofGetWidth()/2, h, eli_size, eli_size);
    
     
    
    /*//--------
    int box_size = 20;
    int box_x = 10;
    int box_alpha = 100;
    
    ofFill();
    
    ofSetColor(150, color_sle, 200, box_alpha);
    ofPushMatrix();
    ofTranslate(morph_sle *box_x, h);
    ofRotate(morph_sle *ofGetFrameRate());
    ofDrawBox(box_size);
    ofPopMatrix();
    
    ofSetColor(250, color_foc, 200, box_alpha);
    ofPushMatrix();
    ofTranslate(morph_foc *box_x, h);
    ofRotate(morph_foc *ofGetFrameRate());
    ofDrawBox(box_size);
    ofPopMatrix();
    
    ofSetColor(150, color_bli, 50, box_alpha);
    ofPushMatrix();
    ofTranslate(morph_bli *box_x, h);
    ofRotate(morph_bli *ofGetFrameRate());
    ofDrawBox(box_size);
    ofPopMatrix();

    ofSetColor(250, color_eye, 50, box_alpha);
    ofPushMatrix();
    ofTranslate(morph_eye/10 *box_x, h);
    ofRotate(morph_eye *ofGetFrameRate());
    ofDrawBox(box_size);
    ofPopMatrix();
    */
    

    
    if(percent >= 1.0){
        index += 1;
        index1 += 1;
        if(index == memes.size() - 1 && index1 == memes1.size() - 1){
            //OF_EXIT_APP(0);  //noLoop()に値する関数
        }else{
            sle = memes[index].sleepy;
            next_sle = memes[index+1].sleepy;
            foc = memes[index].focus;
            next_foc = memes[index+1].focus;
            eye = memes[index].eyeMoveRout;
            next_eye = memes[index+1].eyeMoveRout;
            cad = memes[index].cadence;
            next_cad = memes[index+1].cadence;
            bli = memes[index].blink;
            next_bli = memes[index+1].blink;
            
            sle1 = memes1[index1].sleepy1;
            next_sle1 = memes1[index1+1].sleepy1;
            foc1 = memes1[index1].focus1;
            next_foc1 = memes1[index1+1].focus1;
            eye1 = memes1[index1].eyeMoveRout1;
            next_eye1 = memes1[index1+1].eyeMoveRout1;
            cad1 = memes1[index1].cadence1;
            next_cad1 = memes1[index1+1].cadence1;
            bli1 = memes1[index1].blink1;
            next_bli1 = memes1[index1+1].blink1;
            
            h+= 1;
        }
        percent = 0;
    }
    
        ofFill();
    //ofSetColor(86,175,185);
    ofSetColor(0);
    for (int i = 0; i < 10; i++){
        float fw = font.stringWidth(""+ofToString(0));
        float x = ofGetWidth()/2-fw/2;
        font.drawString(""+ofToString(i), x, 20 + ((ofGetHeight()-20) /24)*i);
    }
    for (int i = 10; i < 25; i++){
        float fw = font.stringWidth(""+ofToString(10));
        float x = ofGetWidth()/2-fw/2;
        font.drawString(""+ofToString(i), x, 20+((ofGetHeight()-20)/24)*i);
    }


    
    

            
            
            
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

//--------------------------------------------------------------
void ofApp::loadCsvToMemes(string filePath){
    ofFile file(filePath);
    
    if(!file.exists()){
        ofLogError("The file " + filePath + " is missing");
    }
    
    ofBuffer buffer(file);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            Meme meme;
            meme.eyeMoveRout = ofToFloat(data[3]);
            meme.cadence = ofToFloat(data[7]);
            meme.blink = ofToFloat(data[43]);
            meme.sleepy = ofToFloat(data[54]);
            meme.focus = ofToFloat(data[55]);
            memes.push_back(meme);
            
            if(it == buffer.getLines().begin()){
                max_value_sle = min_value_sle = meme.sleepy;
                max_value_foc = min_value_foc = meme.focus;
                max_value_eye = min_value_eye = meme.eyeMoveRout;
                max_value_cad = min_value_cad = meme.cadence;
                max_value_bli = min_value_bli = meme.blink;
            }else{
                max_value_sle = (meme.sleepy      > max_value_sle) ? meme.sleepy      : max_value_sle;
                min_value_sle = (meme.sleepy      < min_value_sle) ? meme.sleepy      : min_value_sle;
                
                max_value_foc = (meme.focus       > max_value_foc) ? meme.focus       : max_value_foc;
                min_value_foc = (meme.focus       < min_value_foc) ? meme.focus       : min_value_foc;
                
                max_value_eye = (meme.eyeMoveRout > max_value_eye) ? meme.eyeMoveRout : max_value_eye;
                min_value_eye = (meme.eyeMoveRout < min_value_eye) ? meme.eyeMoveRout : min_value_eye;
                
                max_value_cad = (meme.cadence     > max_value_cad) ? meme.cadence     : max_value_cad;
                min_value_cad = (meme.cadence     < min_value_cad) ? meme.cadence     : min_value_cad;
                
                max_value_bli = (meme.blink       > max_value_bli) ? meme.blink       : max_value_bli;
                min_value_bli = (meme.blink       < min_value_bli) ? meme.blink       : min_value_bli;
            }
        }
    }
}


void ofApp::loadCsvToMemes1(string filePath1){
    ofFile file(filePath1);
    
    if(!file.exists()){
        ofLogError("The file " + filePath1 + " is missing");
    }
    
    ofBuffer buffer(file);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            Meme1 meme1;
            meme1.eyeMoveRout1 = ofToFloat(data[3]);
            meme1.cadence1 = ofToFloat(data[7]);
            meme1.blink1 = ofToFloat(data[43]);
            meme1.sleepy1 = ofToFloat(data[54]);
            meme1.focus1 = ofToFloat(data[55]);
            memes1.push_back(meme1);
            
            if(it == buffer.getLines().begin()){
                max_value_sle1 = min_value_sle1 = meme1.sleepy1;
                max_value_foc1 = min_value_foc1 = meme1.focus1;
                max_value_eye1 = min_value_eye1 = meme1.eyeMoveRout1;
                max_value_cad1 = min_value_cad1 = meme1.cadence1;
                max_value_bli1 = min_value_bli1 = meme1.blink1;
            }else{
                max_value_sle1 = (meme1.sleepy1      > max_value_sle1) ? meme1.sleepy1      : max_value_sle1;
                min_value_sle1 = (meme1.sleepy1      < min_value_sle1) ? meme1.sleepy1      : min_value_sle1;
                
                max_value_foc1 = (meme1.focus1       > max_value_foc1) ? meme1.focus1       : max_value_foc1;
                min_value_foc1 = (meme1.focus1       < min_value_foc1) ? meme1.focus1       : min_value_foc1;
                
                max_value_eye1 = (meme1.eyeMoveRout1 > max_value_eye1) ? meme1.eyeMoveRout1 : max_value_eye1;
                min_value_eye1 = (meme1.eyeMoveRout1 < min_value_eye1) ? meme1.eyeMoveRout1 : min_value_eye1;
                
                max_value_cad1 = (meme1.cadence1     > max_value_cad1) ? meme1.cadence1     : max_value_cad1;
                min_value_cad1 = (meme1.cadence1     < min_value_cad1) ? meme1.cadence1     : min_value_cad1;
                
                max_value_bli1 = (meme1.blink1       > max_value_bli1) ? meme1.blink1       : max_value_bli1;
                min_value_bli1 = (meme1.blink1       < min_value_bli1) ? meme1.blink1       : min_value_bli1;
            }
        }
    }
}



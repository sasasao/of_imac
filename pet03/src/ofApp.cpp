#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //dataフォルダに配置したcsvファイルの名前
    string filePath = "tamabi01.csv";
    loadCsvToMemes(filePath);
    
    //画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest();
    
    //対象からの距離の初期値を指定
    cam.setDistance(300);
    
    //ライトを配置
    light.enable();
    light.setPosition(-100, 100, 500);
    
    //球からメッシュを生成
    myMesh = ofSpherePrimitive(100, 50).getMesh();
    meshB = ofSpherePrimitive(200, 50).getMesh();
    //メッシュの色を設定
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    for (int i = 0; i < meshB.getVertices().size(); i++) {
        meshB.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    //頂点の数だけ繰り返し
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        
                //頂点の位置を取得
        ofVec3f loc = myMesh.getVertices()[i] / max_posture;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, min_focus, max_focus);
        float pos_noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 0, ofGetHeight());
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        myMesh.setVertex(i, newLoc);
        //頂点の色を設定
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.0, 2.0);
        myMesh.setColor(i, ofFloatColor(c, c, 200, 1.0));
    }
    for (int i = 0; i < meshB.getVertices().size(); i++) {
        
        //頂点の位置を取得
        ofVec3f loc = meshB.getVertices()[i] / max_calm;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, min_calm, max_calm);
        float pos_noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 0, ofGetHeight());
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        meshB.setVertex(i, newLoc);
        //頂点の色を設定
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.0, 2.0);
        meshB.setColor(i, ofFloatColor(c, c, 200, 1.0));
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    //メッシュを描画
    cam.begin();
    
    ofPushMatrix();
    ofTranslate(-100, 0);
    ofRotate(ofGetElapsedTimef());
    myMesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(200, 0);
    meshB.draw();
    ofPopMatrix();
   
    cam.end();
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
            meme.user_id = data[0];
            meme.zone_date = data[1];
            meme.zone_focus = ofToFloat(data[3]);
            meme.zone_calm = ofToFloat(data[4]);
            meme.zone_posture = ofToFloat(data[5]);
            memes.push_back(meme);
            
            if(it == buffer.getLines().begin()){
                max_focus = min_focus = meme.zone_focus;
                max_calm = min_calm = meme.zone_calm;
                max_posture  = min_posture = meme.zone_posture;
            }
            else{
                //データをひとつずつ比較しながら最小値最大値を調べる
                max_focus = (meme.zone_focus > max_focus) ? meme.zone_focus : max_focus;
                min_focus = (meme.zone_focus < min_focus) ? meme.zone_focus : min_focus;
                max_calm = (meme.zone_calm > max_calm) ? meme.zone_calm : max_calm;
                min_calm = (meme.zone_calm < min_calm) ? meme.zone_calm : min_calm;
                max_posture = (meme.zone_posture > max_posture) ? meme.zone_posture : max_posture;
                min_posture = (meme.zone_posture < min_posture) ? meme.zone_posture : min_posture;
                
            }
            
        }
    }
}




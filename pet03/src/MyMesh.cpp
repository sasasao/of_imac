#include "MyMesh.hpp"

MyMesh::MyMesh(){
        //球からメッシュを生成
    myMesh = ofSpherePrimitive(100, 72).getMesh();
    //メッシュの色を設定
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
     h = 0;
}

void MyMesh::update(){
    
    
    
   
}

void MyMesh::draw(){
    //頂点の数だけ繰り返し
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        //頂点の位置を取得
        ofVec3f loc = myMesh.getVertices()[i] / 300.0;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 80, 240);
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        myMesh.setVertex(i, newLoc);
        //頂点の色を設定
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.5, 1.0);
        myMesh.setColor(i, ofFloatColor(c, c, c, 1.0));
    }
    
    
    ofPushMatrix();
    ofRotateY(ofGetElapsedTimef()*10.0);
    myMesh.draw();
    ofPopMatrix();
    
    //cout << h ;
}
#pragma once
#include "ofMain.h"
struct Meme {
    //memeから取得したデータ各種を格納するクラス
    string user_id;
    string zone_date;
    float zone_focus;
    float zone_calm;
    float zone_posture;
};


class Particles {
public:
    Particles(int maxParticles);
    void setup();
    void update();
    void draw();
    void addParticle(ofVec2f position,
                     ofVec2f velocity = ofVec2f(0, 0),
                     ofColor color = 0xffffff);
    void resetForce();
    void addForce(int count, ofVec2f force);
    void addDampingForce();
    void resetOffWalls();
    void updatePos();
    void loadCsvToMemes(string filePath);
    
    //Memeのデータを格納するmemes配列
    vector<Meme> memes;
    
    //各データの最大最小を格納する変数
    float max_focus, min_focus;
    float max_calm, min_calm;
    float max_posture, min_posture;
    
    ofMesh mesh;
    ofVec2f pos;
    
    int maxParticles;
    float pointSize;
    
    int numParticles;
    deque<ofVec2f> positions;
    deque<ofVec2f> velocitys;
    deque<ofVec2f> forces;
    deque<ofColor> colors;
    float friction;
    
};


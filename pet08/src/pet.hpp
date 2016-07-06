#pragma once
#include "ofMain.h"

struct First {
    float cadence;
};

struct Second {
    string user_id;
    string zone_date;
    float zone_focus;
    float zone_calm;
    float zon_posture;
};

class Pets {
public:
    void setup();
    void draw();
    
    //MEME
    vector<Second> seconds;
    float max_focus, min_focus;
    float max_calm, min_calm;
    float max_posture, min_posture;
    
    vector<First> firsts;
    

};

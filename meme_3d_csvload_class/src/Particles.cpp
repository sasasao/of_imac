#include "Particles.hpp"

Particles::Particles(int _maxParticles){
    string filePath = "tamabi02.csv";
    string filePath02 = "002_ST.csv";
    loadCsvToMemes(filePath);
    loadCsvToMemes02(filePath02);
    
    maxParticles = _maxParticles;
    numParticles = 0;
    friction = 0.01;
    
    line_w = 100;
    line_h = 100;
    wire = 20;

    mesh = ofSpherePrimitive(200, wire).getMesh();
    outside = ofSpherePrimitive(200, wire).getMesh();
    mesh_line = ofPlanePrimitive(5, 5, line_w, line_h).getMesh();
    
    glPointSize(3.0);
    mesh_line.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    for (int i = 0; i < outside.getVertices().size(); i++) {
        outside.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    for (int i = 0; i < mesh_line.getVertices().size(); i++) {
        mesh_line.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
}

void Particles::resetForce(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec2f(0, 0);
    }
}

void Particles::addForce(int count, ofVec2f force){
    forces[count] += force;
}

void Particles::addDampingForce(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] -= velocitys[i] * friction;
    }
}

void Particles::resetOffWalls(){
    float meshSize = 0;
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    for(int i = 0; i < positions.size(); i++){
        /*if (positions[i].x > maxx){
            positions[i].x = minx;
        }
        if (positions[i].y > maxy){
            positions[i].y = miny;
        }
        if (positions[i].x < minx){
            positions[i].x = maxx;
        }
        if (positions[i].y < miny){
            positions[i].y = maxy;
        }
        if (positions[i].x < 0 || positions[i].x > ofGetWidth()) {
            velocitys[i].x *= -1;
        }
        if (positions[i].y < 0 || positions[i].y > ofGetHeight()) {
            velocitys[i].y *= -1;
        }*/
    }
}

void Particles::updatePos(){
    for(int i = 0; i < positions.size(); i++){
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}

void Particles::update(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec2f(0, 0);
        forces[i] -= velocitys[i] * friction;
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}


void Particles::draw(){
    
    //頂点の数だけ繰り返し
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        int m = ofMap(i, 0, mesh.getVertices().size(), 0, memes.size());
        int f = ofMap(i, 0, mesh.getVertices().size(), 0, firsts.size());
        Meme meme = memes[m];
        First first = firsts[f];
        
        
        morph_focus = ofLerp(focus, next_focus, percent);
        morph_calm = ofLerp(calm, next_calm, percent);
        morph_posture = ofLerp(posture, next_posture, percent);
        
        
        float posture_loc = ofMap(morph_posture, min_posture, max_posture, 50, 400);
        //頂点の位置を取得
        ofVec3f loc = mesh.getVertices()[i] / posture_loc;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 80,240);
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        mesh.setVertex(i, newLoc);
        mesh_line.setVertex(i, newLoc*1.2);
        outside.setVertex(i, newLoc*1.2);
        
        float R = ofMap(meme.zone_focus, min_focus, max_focus, 0, 1.0);
        float G = ofMap(meme.zone_calm, min_calm, max_calm, 0, 1.0);
        float B = ofMap(meme.zone_posture, min_posture, max_posture, 0, 1.0);
        
        mesh.setColor(i, ofFloatColor(R,G,B,1));
        outside.setColor(i, ofFloatColor(1.0,1.0,1.0,0.1));
        mesh_line.setColor(i, ofFloatColor(1.0,1.0,1.0,1));
    }
    
    for (int i = 0; i < positions.size(); i++) {
        int f = ofMap(i, 0, positions.size(), 0, firsts.size());
        First first = firsts[f];
        ofRotateY(ofGetElapsedTimef()*10.0);
        ofTranslate(positions[i].x *first.cadence,
                    positions[i].y *first.cadence);
    }
    
    ofSetLineWidth(0.1);
    mesh.draw();
    mesh_line.draw();
    outside.drawWireframe();
    
    percent += 0.01;
    if(percent >= 1.0){
        index += 1;
        
        if(index == memes.size() - 1){
            
        }else {
            focus = memes[index].zone_focus;
            calm = memes[index].zone_calm;
            posture = memes[index].zone_posture;
            next_focus = memes[index+1].zone_focus;
            next_calm = memes[index+1].zone_calm;
            next_posture = memes[index+1].zone_posture;
        }
        percent = 0;
    }
    
}

void Particles::addParticle(ofVec2f _position, ofVec2f _velocity, ofColor _color){
    positions.push_back(_position);
    velocitys.push_back(_velocity);
    colors.push_back(_color);
    forces.push_back(ofVec2f(0, 0));
    numParticles++;
    
    if (positions.size() > maxParticles) {
        positions.pop_front();
        colors.pop_front();
        velocitys.pop_front();
        forces.pop_front();
        numParticles--;
    }
}

//--------------------------------------------------------------
void Particles::loadCsvToMemes(string filePath){
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
//--------------------------------------------------------------
void Particles::loadCsvToMemes02(string filePath02){
    ofFile file02(filePath02);
    
    if(!file02.exists()){
        ofLogError("The file " + filePath02 + " is missing");
    }
    ofBuffer buffer(file02);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            First first;
            first.cadence = ofToFloat(data[10]);
            firsts.push_back(first);
            
            if(it == buffer.getLines().begin()){
                max_cadence = min_cadence = first.cadence;
            }
            else{
                //データをひとつずつ比較しながら最小値最大値を調べる
                max_cadence = (first.cadence > max_cadence) ? first.cadence : max_cadence;
                
            }
            
        }
    }
}


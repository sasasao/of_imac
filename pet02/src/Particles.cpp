#include "Particles.hpp"

Particles::Particles(int _maxParticles){
    maxParticles = _maxParticles;
    numParticles = 0;
    friction = 0.5;
    
    
    myMesh = ofSpherePrimitive(200,72).getMesh();
    for (int i=0; i<myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0,1.0,1.0,1.0));
    }

    mesh.setMode(OF_PRIMITIVE_POINTS);
    myMesh.setMode(OF_PRIMITIVE_POINTS);
    
}


void Particles::resetForce(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec3f(0, 0, 0);
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
    float minx = 0;
    float miny = 0;
    float minz = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    float maxz = ofGetHeight();
    
    for(int i = 0; i < positions.size(); i++){
        if (positions[i].x > maxx){
            positions[i].x = minx;
        }
        if (positions[i].y > maxy){
            positions[i].y = miny;
        }
        if (positions[i].z > maxz){
            positions[i].z = minz;
        }
        
        if (positions[i].x < minx){
            positions[i].x = maxx;
        }
        if (positions[i].y < miny){
            positions[i].y = maxy;
        }
        if (positions[i].z < minz){
            positions[i].z = maxz;
        }

    }
}

void Particles::updatePos(){
    for(int i = 0; i < positions.size(); i++){
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}

void Particles::update(){
    for(int i=0; i<myMesh.getVertices().size(); i++){
        ofVec3f loc = myMesh.getVertices()[i] / 300.0;
        
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z,ofGetElapsedTimef()), 0, 1, 80, 240);
        ofVec3f newLoc = loc.normalize()*noise;
        myMesh.setVertex(i, newLoc);
        
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 0.5, 1.0);
        myMesh.setColor(i, ofFloatColor(c,c,c,1.0));
    }


    
    
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec3f(0, 0, 0);
        forces[i] -= velocitys[i] * friction;
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}

void Particles::draw(){
    myMesh.clear();
    mesh.clear();
    for (int i = 0; i < positions.size(); i++) {
        mesh.addVertex(ofVec3f(positions[i].x, positions[i].y));
        mesh.addColor(ofFloatColor(1.0,1.0,1.0));
        myMesh.addVertex(ofVec3f(positions[i].x, positions[i].y, positions[i].z));
        myMesh.addColor(ofFloatColor(1.0,1.0,1.0));
    }
    mesh.draw();
    myMesh.draw();
}

void Particles::addParticle(ofVec2f _position, ofVec2f _velocity, ofColor _color){
    positions.push_back(_position);
    velocitys.push_back(_velocity);
    colors.push_back(_color);
    forces.push_back(ofVec3f(0, 0, 0));
    numParticles++;
    
    if (positions.size() > maxParticles) {
        positions.pop_front();
        colors.pop_front();
        velocitys.pop_front();
        forces.pop_front();
        numParticles--;
    }
}
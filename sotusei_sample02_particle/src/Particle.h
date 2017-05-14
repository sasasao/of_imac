#pragma once

#include "Particle.h"
#include "MSACore.h"
#include "MSAFluidSolver.h"

class Particle : public ofBaseApp{

	public:
		void init(float x, float y);
    void update( const msa::fluid::Solver &solver, const ofVec2f &windowSize, const ofVec2f &invWindowSize );
		void updateVertexArrays( bool drawingFluid, const ofVec2f &invWindowSize, int i, float* posBuffer, float* colBuffer);
		
    ofVec2f pos, vel;
    float radius;
    float alpha;
    float mass;
};

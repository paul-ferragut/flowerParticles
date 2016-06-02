#include "particleFlower.h"

//------------------------------------------------------------------
particleFlower::particleFlower(){
	attractPoints = NULL;
}
//------------------------------------------------------------------
particleFlower::~particleFlower(){
   // attractPoints = NULL;
}


//------------------------------------------------------------------
void particleFlower::setAttractPoints( vector <ofPoint> * attract ){
	attractPoints = attract;
}

//------------------------------------------------------------------

void particleFlower::setup(ofPoint origin, ofVec2f direction, int subDivision){
	
    
    uniqueVal = ofRandom(-10000, 10000);
    pos = origin;
    
    float normalizedLevel = ofMap(subDivision, 0, 60, 1.0, 0.01, true);
    //TO DO DIRECTION, WEAKER ACCORDING TO SUBDivison
    
    vel.x = ofRandom(-0.002, 0.002)* normalizedLevel;
	vel.y = ofRandom(-0.002, 0.002)* normalizedLevel;
	
	frc   = ofPoint(0,0,0);
	
	dir = direction;
	

	scale = normalizedLevel;
	
	//if( mode == PARTICLE_MODE_NOISE ){
	//	drag  = ofRandom(0.97, 0.99);
	//	vel.y = fabs(vel.y) * 3.0; //make the particles all be going down
	//}else{
		drag  = ofRandom(0.95, 0.998);	
	//}
    
    durationEnd=ofRandom(1000,2000)* (normalizedLevel);
    duration=0;
	ended = false;
    
}

//------------------------------------------------------------------
int particleFlower::update(){

    
    
    
    duration++;
    if(duration<durationEnd){
    
	//1 - APPLY THE FORCES BASED ON WHICH MODE WE ARE IN 
	/*
	if( mode == PARTICLE_MODE_ATTRACT ){
		ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
		frc = attractPt-pos; // we get the attraction force/vector by looking at the mouse pos relative to our pos
		frc.normalize(); //by normalizing we disregard how close the particle is to the attraction point 
		
		vel *= drag; //apply drag
		vel += frc * 0.6; //apply force
	}
	else if( mode == PARTICLE_MODE_REPEL ){*/
		ofPoint attractPt(dir);
		frc = attractPt-pos; 
		
		//let get the distance and only repel points close to the mouse
		float dist = frc.length();
		frc.normalize(); 
		
		vel *= drag; 
		if( dist < 150 ){
			vel += -frc * 0.006; //notice the frc is negative 
		}else{
			//if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy. 			
			frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
			frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
			vel += frc * 0.004;
		}
	/*
    }
	else if( mode == PARTICLE_MODE_NOISE ){
		//lets simulate falling snow 
		//the fake wind is meant to add a shift to the particles based on where in x they are
		//we add pos.y as an arg so to prevent obvious vertical banding around x values - try removing the pos.y * 0.006 to see the banding
		float fakeWindX = ofSignedNoise(pos.x * 0.003, pos.y * 0.006, ofGetElapsedTimef() * 0.6);
		
		frc.x = fakeWindX * 0.25 + ofSignedNoise(uniqueVal, pos.y * 0.04) * 0.6;
		frc.y = ofSignedNoise(uniqueVal, pos.x * 0.006, ofGetElapsedTimef()*0.2) * 0.09 + 0.18;

		vel *= drag; 
		vel += frc * 0.4;
		
		//we do this so as to skip the bounds check for the bottom and make the particles go back to the top of the screen
		if( pos.y + vel.y > ofGetHeight() ){
			pos.y -= ofGetHeight();
		}
	}
     */

	
	
	//2 - UPDATE OUR POSITION
	
	pos += vel; 
	
        return STATE_UPDATE;
	}
	else if (duration == durationEnd) {
		return STATE_ENDED;
	}else if (duration > durationEnd) {
		return STATE_INACTIVE;
    }
        
	
	//3 - (optional) LIMIT THE PARTICLES TO STAY ON SCREEN 
	//we could also pass in bounds to check - or alternatively do this at the ofApp level
    /*
	if( pos.x > ofGetWidth() ){
		pos.x = ofGetWidth();
		vel.x *= -1.0;
	}else if( pos.x < 0 ){
		pos.x = 0;
		vel.x *= -1.0;
	}
	if( pos.y > ofGetHeight() ){
		pos.y = ofGetHeight();
		vel.y *= -1.0;
	}
	else if( pos.y < 0 ){
		pos.y = 0;
		vel.y *= -1.0;
	}	
     */
		
}

//------------------------------------------------------------------
ofVec2f particleFlower::getPos(){
    return pos;
}

//------------------------------------------------------------------
void particleFlower::draw(){
    
    
    ofSetColor(150,150,150);
    /*
	if( mode == PARTICLE_MODE_ATTRACT ){
		ofSetColor(255, 63, 180);
	}
	else if( mode == PARTICLE_MODE_REPEL ){
		ofSetColor(208, 255, 63);
	}
	else if( mode == PARTICLE_MODE_NOISE ){
		ofSetColor(99, 63, 255);
	}
	else if( mode == PARTICLE_MODE_NEAREST_POINTS ){
		ofSetColor(103, 160, 237);
	}*/
			
	ofDrawCircle(pos.x, pos.y, scale * 4.0);
}


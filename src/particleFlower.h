#pragma once
#include "ofMain.h"


class particleFlower{

	public:
		particleFlower();
        particleFlower~();
		void setAttractPoints( vector <ofPoint> * attract );

        void setup(ofPoint origin, ofVec2f direction, int subDivision);
		
        ofVec2f getPos();
        bool update();
		void draw();		
		
		ofPoint pos;
		ofPoint vel;
		ofPoint frc;
    
      //  ofPoint endPoint;
    
    float duration:
    float durationEnd;
    
        bool
    
    
		float drag; 
		float uniqueVal;
		float scale;
		
		vector <ofPoint> * attractPoints;
};
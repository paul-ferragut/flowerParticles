#pragma once
#include "ofMain.h"

#define STATE_UPDATE 0
#define STATE_ENDED 1
#define STATE_INACTIVE 2

class particleFlower{

	public:
		particleFlower();
		~particleFlower();
   
		void setAttractPoints( vector <ofPoint> * attract );

        void setup(ofPoint origin, ofVec2f direction, int subDivision);
		
        ofVec2f getPos();
        int update();
		void draw();		
		
		ofPoint pos;
		ofPoint vel;
		ofPoint frc;

		ofPoint dir;
    
      //  ofPoint endPoint;
    
		int duration;
    int durationEnd;
    
	bool ended;
    
    
		float drag; 
		float uniqueVal;
		float scale;
		
		vector <ofPoint> * attractPoints;
};
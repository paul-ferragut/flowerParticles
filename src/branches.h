#pragma once
#include "particleFlower.h"


#define STATE_UPDATE 0
#define STATE_ENDED 1
#define STATE_INACTIVE 2

struct branch {

	vector<particleFlower>p;
	int currentLevel;
	int maxBranches;
	ofVec2f directionPt;

};
class branches{

	public:
		branches();
		~branches();
   


        void setup();
		void update();
		void draw(ofVec2f pos,float width, ofColor colStart,ofColor colEnd);		

		vector<branch>b;
		int wP;
		int hP;
		
};
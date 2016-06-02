#pragma once

#include "ofMain.h"
#include "particleFlower.h"

#define STATE_UPDATE 0
#define STATE_ENDED 1
#define STATE_INACTIVE 2

struct branch{

    vector<particleFlower>p;
	int currentLevel;
	int maxBranches;
	ofVec2f directionPt;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    vector<branch>b;
		
};

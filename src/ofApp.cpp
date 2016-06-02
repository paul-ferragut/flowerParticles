#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    gui.setup();
    gui.add(attraction.setup("attract",0.5,0.0,5.0));
	
	vector<particleFlower>tPV;

	branch tB;
	tB.currentLevel = 0;
	tB.maxBranches = 50;
	tB.directionPt.set(0,0);	
	
	particleFlower tP;
	tP.setup(ofVec2f(ofGetWidth()/2,ofGetHeight()/2), tB.directionPt,0);

	tB.p.push_back(tP);
	b.push_back(tB);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	//ofSetBackgroundAuto(false);
	for (int i = 0;i < b.size();i++) {
		for (int j = 0;j < b[i].p.size();j++) {
			int createNew = 0;
			createNew=b[i].p[j].update();
			if (createNew==STATE_ENDED) {
				if (b[i].currentLevel < b[i].maxBranches) {
					b[i].currentLevel++;
				
					int newBranch = ofRandom(1, 4);

					for (int k = 0;k < newBranch;k++) {
						particleFlower tP;
						tP.setup(b[i].p[j].pos, b[i].directionPt, b[i].currentLevel);
						///cout << "b[i].p[j].pos" << b[i].p[j].pos << endl;
						b[i].p.push_back(tP);
					}
				}
			}
		}
	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofEnableAlphaBlending();
	//ofSetColor(0, 0, 0, 100);
	for (int i = 0;i < b.size();i++) {
		for (int j = 0;j < b[i].p.size();j++) {
			b[i].p[j].draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

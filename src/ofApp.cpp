#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    gui.setup();
    gui.add(attraction.setup("attract",0.5,0.0,5.0));
	
	/*
	vector<particleFlower>tPV;
	wP= 1024;
	hP= 768;
	int branchNum = ofRandom(45,55);

	for (int i = 0;i < branchNum;i++) {
	float angle = ofDegToRad(ofRandom(0,360));
	ofVec2f attractP((wP / 2) + (cos(angle) * (hP / 2)), (hP / 2) + (sin(angle) * (hP / 2)));

	branch tB;
	tB.currentLevel = 0;
	tB.maxBranches = ofRandom(40,55);
	tB.directionPt.set(attractP);
	
	particleFlower tP;
	tP.setup(ofVec2f(wP /2, hP /2), tB.directionPt,0);

	tB.p.push_back(tP);
	b.push_back(tB);

	}
	*/
	branch1.setup();
	ofBackground(0, 0, 0);
	
}

//--------------------------------------------------------------
void ofApp::update(){ofSetFrameRate(240);
branch1.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofEnableAlphaBlending();
	//ofSetColor(0, 0, 0, 100);

	/*
	for (int i = 0;i < b.size();i++) {
		for (int j = 0;j < b[i].p.size();j++) {
			b[i].p[j].draw(ofColor(0,255,255),ofColor(0,100,255));
		}
	}
	*/

	//ofDrawCircle(attractP, 20);

	branch1.draw(ofVec2f(mouseX,mouseY),1400,ofColor(0, 255, 255), ofColor(0, 100, 255));
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

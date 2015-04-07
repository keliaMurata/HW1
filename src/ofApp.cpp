/*
	Kelia Murata
	Seaweed Project
	A Polyline quiz: creates a curved polyline that is shaped, colored, and has a 
	swaying movement to mimic sea weed underwater.
	Version 2.0, retry
	Incomplete. 

*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//declare points
	basePoint = ofPoint(ofGetWindowWidth() /2, ofGetWindowHeight());
	midPoint = ofPoint(ofGetWindowWidth() /2 - 100, ofGetWindowHeight() /2 - 150);
	endPoint = ofPoint(ofGetWindowWidth() /2 + 40, 90);
	finalPoint = ofPoint(ofGetWindowWidth() / 2, 10);

	//create your polyline from your seaweed body 
	seaweed.curveTo(basePoint);//doubled for anchor 
	seaweed.curveTo(basePoint);
	seaweed.curveTo(midPoint);
	seaweed.curveTo(endPoint);
	seaweed.curveTo(finalPoint);
	seaweed.curveTo(finalPoint);

}

//--------------------------------------------------------------
void ofApp::update()
{
	//bounds
	if(midPoint.x > 200) //mid left bound 
	{

	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(100);
	ofSetLineWidth(2.0);
	ofSetColor(25, 220, 25);
	seaweed.draw(); 
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

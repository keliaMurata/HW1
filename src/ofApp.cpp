/*
	Kelia Murata
	Seaweed Project
	A Polyline quiz: creates a curved polyline that is shaped, colored, and has a 
	swaying movement to mimic sea weed underwater.
	Version 2.0, retry

*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	width = ofGetWindowWidth();
	height = ofGetWindowHeight();
	
	//declare points
	basePoint = ofPoint(width/2, height);
	staticPoint = ofPoint(width/2, (height/4)*3);
	midPoint = ofPoint(width/2 + 50, height/3);
	endPoint = ofPoint(width/ 2, 10);

	//setting movement velocity
	midMomentum = .125; 
	endMomentum = .25;

}

//--------------------------------------------------------------
void ofApp::update()
{
	//updating mid and end point locations for movement 
	midPoint.x = midPoint.x + midMomentum;
	endPoint.x = endPoint.x + endMomentum;

	//creating polyline stem of seaweed 
	seaweed.curveTo(basePoint);//doubled for anchor 
	seaweed.curveTo(basePoint);
	seaweed.curveTo(staticPoint);
	seaweed.curveTo(midPoint);
	seaweed.curveTo(endPoint);
	seaweed.curveTo(endPoint);
	seaweed.simplify();

	//bounds for moving point
	if(endPoint.x >= (width/2) + width/4) //end point right bound 
	{
		endMomentum*=-1; 
	}
	if(endPoint.x <= (width/2) - width/4) //end point left bound
	{
		endMomentum*=-1;
	}
	if(midPoint.x >= (width/2) + width/8) //mid point right bound 
	{
		midMomentum*=-1; 
	}
	if(midPoint.x <= (width/2) - width/8) //mid point left bound
	{
		midMomentum*=-1;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(175); //backgroundColor
	ofSetLineWidth(2.0);
	ofSetColor(175, 250, 70); //seaweed steam color
	seaweed.draw(); 
	ofColor leafColor = ofColor(115, 190, 10); //leaf color
	 
	//creating perpendicular leaf lines and fading leaf color 
	float seaweedLength = seaweed.size();
    for (int i = 0; i < 100; i += 1) 
	{
        leafColor.setBrightness(i*2 + 50); //iterates through to add brightness 
		ofSetColor(leafColor);
		ofVec3f leafPoints = seaweed.getPointAtPercent(i/100.0); //vector of points throughout leaf
        float leafPointIndex = i/100.0 * (seaweedLength - 1); //an indext for all the points 
		ofVec3f normal = seaweed.getNormalAtIndexInterpolated(leafPointIndex) //gets the normal for all leaf points 
			* (200 - (i*2));
        ofLine(leafPoints - normal/2, leafPoints + normal/2); //creates perpendicular line to all points of leaf
    }   

	seaweed.clear(); //clear the line so it doesn't loop back to itself 
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

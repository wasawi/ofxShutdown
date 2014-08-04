#include "ofxShutdown.h"

//--------------------------------------------------------------
ofxShutdown:: ofxShutdown(){
	bWaitingToShutdown	= false;
	bRestarting			= false;

	shutdownParams		= "-h now";
	isAdmin				= false;
	password			= "";
	delay				= 3;
	bDrawMessage		= true;
	bexitAfterCommand	= false;
	
	elapsedTime,
	startTime,
	countdown = 0;
//	ofAddListener(this->RESTART, this, &ofxShutdown::restartEvent);

}
ofxShutdown:: ~ofxShutdown(){
	ofRemoveListener(ofEvents().update, this, &ofxShutdown::update);
	ofRemoveListener(ofEvents().draw, this, &ofxShutdown::draw);
}

//--------------------------------------------------------------
void ofxShutdown::shutdownExecute(){
	
	startTime			= ofGetElapsedTimef();
	bWaitingToShutdown	= true;
		
	ofLogVerbose("Milis to wait before restart") << delay;
	
	//events
	ofAddListener(ofEvents().update, this, &ofxShutdown::update);
	if (bDrawMessage) ofAddListener(ofEvents().draw, this, &ofxShutdown::draw,OF_EVENT_ORDER_AFTER_APP);

}

//--------------------------------------------------------------
void ofxShutdown::update(ofEventArgs &e){
	
	if (bWaitingToShutdown){
		elapsedTime = ofGetElapsedTimef() - startTime;
		countdown = delay - elapsedTime;
		
		if (countdown < 0 && !bRestarting){
			ofLogNotice("Shutting down computer!");
			shutDown();
			bRestarting = true;
		}
	
	}
}

//--------------------------------------------------------------
void ofxShutdown::draw(ofEventArgs &e){
	if (bWaitingToShutdown && bDrawMessage){
		string msg = "waiting to shutdown "+ofToString(countdown)+" seconds";
		ofDrawBitmapStringHighlight(msg,
						   ofGetWidth()/2 - 100,
						   ofGetHeight()/2);
	}
}

//--------------------------------------------------------------
void ofxShutdown::shutDown(){

	if (isAdmin) {
		// if user is admin
		ofSystem("shutdown "+shutdownParams);
		ofLogNotice(" ofxShutdown::shutDown()")<<"shutdown";
	}else{
		// if user is not admin, set admin passw.
		ofSystem("echo "+password+" | sudo -S shutdown "+ shutdownParams+" &");
		ofLogNotice(" ofxShutdown::shutDown()")<<"sudo -S shutdown "+ shutdownParams+" &";
	}
	
	if (bexitAfterCommand){
		ofKillApp("iWall");
	}
}

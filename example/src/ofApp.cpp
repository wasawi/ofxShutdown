#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString("press 's' to shutdown",
					   ofGetWidth()/2  - 100,
					   ofGetHeight()/2 - 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key=='s'){
		
		// wait 3 seconds before sending the shutdown command
		shutdown.setDelay(3);
		// shutdown command: shutdown in 1 minute (to let OF close well)
		shutdown.setParams("-h +1");
		// set admin password if user is not admin
//		shutdown.setUserIsAdmin(false, "yourPassword");
		// close OF before shutting dowmn
		shutdown.exitOFAfterShutdownCommand(true);
		// execute
		shutdown.shutdownExecute();
		

		/*
		// More examples:
		 
		// Shutdown immediately:
		computer.setParams("-h now");
		 
		// Restart immediately:
		computer.setParams("-r now");
		 
		// Shutdown at 9 pm:
		computer.setParams("-h 21:00");
		 
		// Shutdown in 5 minutes:
		computer.setParams("-h +5");

		// if user is not admin. specify user's passwordd.
		computer.setUserIsAdmin( false, "myUserPassword");
		
		 */
	}
	
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

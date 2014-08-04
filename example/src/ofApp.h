#pragma once

#include "ofMain.h"
#include "ofxShutdown.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
	ofxShutdown		shutdown;
};


/*
 This addon uses a countdown to shutdown your computer.
 
 If the user running the application is not an  admin you will receive this message:
 
 "[USER]is not in the sudoers file.  This incident will be reported."
 
 To fix it, log in as admin and run in terminal the following:
 
 sudo nano  /private/etc/sudoers
 
 then enter a new line:
 
 [the username you want to give access] ALL=(ALL) ALL
 
 Example:
 myUser ALL=(ALL) ALL
 
 Then close nano saving changes:
 crtl+x [enter]
 y [enter]
 
 then use:
 shutdown();
 */
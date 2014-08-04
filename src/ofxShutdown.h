/***********************************************************************
 
 Copyright (c) 2009, Jordi Puig, www.wasawi.com
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 ***********************************************************************/


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

#pragma once

#include "ofMain.h"

class ofxShutdown{
public:

	ofxShutdown();
	~ofxShutdown();

	// SETTERS
	void setParams(string _shutdownParams)				{shutdownParams	= _shutdownParams;}
	void setUserIsAdmin(bool _isAdmin, string _password){isAdmin	= _isAdmin;
														password	= _password;}
	void setDelay(float _delaySeconds)					{delay		= _delaySeconds;}
	void setDrawMessage(bool _drawMessage)				{bDrawMessage= _drawMessage;}
	void exitOFAfterShutdownCommand(bool _exit)			{bexitAfterCommand= _exit;}
	
	// call this to initiate shutdown countdown
	void shutdownExecute();
	
private:

	void update(ofEventArgs &e);
	void draw(ofEventArgs &e);

	bool bRestarting;
	bool bWaitingToShutdown;
	float countdown;	// time left
	float elapsedTime;
	float startTime;	// when did the stopwatch start
	
	// params
	string shutdownParams;
	bool isAdmin;
	string password;
	float delay;		// fixed time before restart
	bool bDrawMessage;
	bool bexitAfterCommand;
	
	
	
	void shutDown();
	
	
	void ofKillApp(string appname){
		
		/*
		 http://www.linux.org/threads/kill-commands-and-signals.4423/
		 
		 SIGHUP (1) - Hangup detected on controlling terminal or death of controlling process. Use SIGHUP to reload configuration files and open/close log files.
		 SIGKILL (9) - Kill signal. Use SIGKILL as a last resort to kill process. This will not save data or cleaning kill the process.
		 SIGTERM (15) - Termination signal. This is the default and safest way to kill process.
		 */
		
		ofLogNotice("ofKillApp()")<<"killing "+ appname;
		ofSystem("ps aux | grep "+appname+" | awk {'print $2'} | xargs KILL -15");
		
	}
};
















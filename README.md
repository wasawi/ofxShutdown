ofxShutdown
================

This addon uses a countdown to shutdown your computer.

Only tested in Mac. 
Please let me know if any issues.
Thanks!
 
 
Known issues
------------

If the user running the application is not an  admin you will receive this message:
 
*"[USER]is not in the sudoers file.  This incident will be reported."*
 
To fix it, log in as admin and run in terminal the following:
 
`sudo nano  /private/etc/sudoers`
 
then enter a new line:

`[the username you want to give access] ALL=(ALL) ALL`
 
Example:`myUser ALL=(ALL) ALL`
 
Then close nano saving changes:
 crtl+x [enter]
 y [enter]
 
then run: `shutdown();`

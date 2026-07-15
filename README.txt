Introduction:

This program allows the user to enter a message into the serial monitor of the Arduino IDE which then displays the message onto the MAX7219, sliding from left to right. 

This folder contains the Excel file "messages Characters.xlsm" and the Arduino files "messages.ino", along with the header file "LedControl.zip", necessary for the program to run correctly.



"messages Characters.xlsm":

The Excel file "messages Characters.xlsm" provides a space for manual creation of characters and symbols to be entered into the program by highlighting cells. These highlighted cells result in the respective bytes of the characters/symbols to be generated, allowing the characters/symbols to be copied from the Excel sheet into the Arduino code (the switch-case within the createString function containing the list of recognised characters/symbols) within the Arduino file "messages.ino".



"messages.ino":

This program begin by prompting the using to input a message into the serial monitor. Afterwards, the message is repeatedly displayed onto the MAX7219 until another message rewrites the previous and is then displayed. 



Setup:

The following libraries must be included into the Arduino IDE:
	1) LedControl.h
	2) Vector.h

For configuration of the MAX7219:
	digital pin 12 is connected to the DataIn 
	digital pin 11 is connected to LOAD(CS)
	digital pin 10 is connected to the CLK 

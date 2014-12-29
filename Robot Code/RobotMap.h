#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//Talons
static const int FRONT_LEFT_WHEEL   = 1;
static const int REAR_LEFT_WHEEL    = 3;
static const int FRONT_RIGHT_WHEEL  = 2;
static const int REAR_RIGHT_WHEEL   = 4;

//Gyro
static const int GYRO = 1;

//Limit Switch
static const int LOCKING_MECHANISM_LS  = 3;

//Relays
//static const int COMPRESSOR = 1;
static const int CAMERA_LED = 5;

//Solonoids
static const int GREEN_DROP = 5; // 1 before
static const int GREEN_FILL = 6; // 2 before
static const int RED_LOCK   = 4; // 3 before
static const int RED_LAUNCH = 3; // 4 
static const int BLOCKER_DOWN = 6;
static const int BLOCKER_UP = 5;


//Compressor
static const int COMPRESSOR_IN  = 2; //(Digital Input), 5 before
static const int COMPRESSOR_OUT = 1; //(RELAY)

// Controllers
static const int CONTROLLER = 1;
static const int JOYSTICK = 2;

// Axis Mapping
static const int LEFT_ANALOG_X  = 1;
static const int LEFT_ANALOG_Y  = 2; // was 5 before [reversed]
static const int TRIGGERS 		= 3; // Left > 0 ; Right < 0 [reversed]
static const int RIGHT_ANALOG_X = 4;
static const int RIGHT_ANALOG_Y = 5; // was 2 before [reversed]
static const int DPAD_X		    = 6;
static const int DPAD_Y		    = 7; // **doesn't seem work**

//	 Button Mapping
static const int A				 	= 1;
static const int B 				 	= 2;
static const int X 				 	= 3;
static const int Y 				 	= 4;
static const int LEFT_BUMPER  	    = 5;
static const int RIGHT_BUMPER 		= 6;
static const int BACK 			    = 7;
static const int HOME			    = 8;
static const int LEFT_ANALOG_PRESS  = 9;
static const int RIGHT_ANALOG_PRESS = 10;

#endif

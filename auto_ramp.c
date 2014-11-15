#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ultrason,       sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motora,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorb,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorfrontleft, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorbackleft, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorfrontright, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorbackright, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servograb,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servoauto,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//													 Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"	 //Include file to "handle" the Bluetooth messages.
#define encoder_step_per_inch    125

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																		initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//	 1. Move motors and servos to a preset position.
//	 2. Some sensor types take a short while to reach stable values during which time it is best that
//			robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//			"bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD


void robot_move(float inches, int power_level);
void allstop();
void turnright(float encodeval);
void turnleft(float encodeval2);
=======
void mov1();

void robot_move(float inches, int power_level);
void allstop();
void turnright();
void turnleft();
void turnrighthalf();
void turnlefthalf();
>>>>>>> cascade/master
void grabrundump();
void slowlydump(int angle, int speed);
void speedchoke(int dist);
void speedchoke_back(int dist);
void forward(int speed);
<<<<<<< HEAD

=======
void turnrightquarter();
>>>>>>> cascade/master

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
	servo[servoauto] = 50;
	servo[servograb] = 30;

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				 Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//	 1. Have the robot follow a line on the game field until it reaches one of the puck storage
//			areas.
//	 2. Load pucks into the robot from the storage bin.
//	 3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
	////																									 ////
	////		Add your robot specific autonomous code here.	 ////
	////																									 ////
	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
<<<<<<< HEAD

=======
	//PlaySound(soundBlip);
>>>>>>> cascade/master

	speedchoke_back(60);
	robot_move(-35,50);
	grabrundump();
	robot_move(-12,50);
	wait10Msec(100);
<<<<<<< HEAD
	turnright(965.6);
	robot_move(92, 50);
	turnright(2465);
	turnright(2465);
=======
	turnrightquarter();
	robot_move(92, 50);
	turnright();
	turnright();
>>>>>>> cascade/master
	servo[servograb]=30;
	robot_move(-5,50);
}



void robot_move (float inches, int power_level) {
  long encoder_target;             // determine how far robot moves

    nMotorEncoder[motorbackright] = 0;  // reset encoder before each move
  	nMotorEncoder[motorbackleft]  = 0;
  	encoder_target = encoder_step_per_inch * (inches) *1.09;     // target encoder, >0, forward <0 backward


  	if (inches > 0) {                        // forward move

  	 while (nMotorEncoder[motorbackleft] <= (encoder_target)){
      motor[motorfrontright] = power_level;
  	  motor[motorbackright] = power_level;
  	  motor[motorfrontleft] = power_level;
  	  motor[motorbackleft] = power_level;
  	  }
   }

  else if (inches < 0) {                   // backward move
  		while (nMotorEncoder[motorbackleft] >= (encoder_target)) {
  		motor[motorfrontRight] = -power_level;
  	  motor[motorbackRight] = -power_level;
  	  motor[motorfrontLeft] = -power_level;
  	  motor[motorbackLeft] =  -power_level;
  	  }
    }
                                            // immediate stop!
  	motor[motorfrontRight] = 0;
  	motor[motorfrontLeft]  = 0;
  	motor[motorbackRight]  = 0;
  	motor[motorbackLeft]   = 0;

  }

void speedchoke( int dist) {  // dist: inches; pace: encoding advance /0.1sec
	int power = 15;		       // init power level
	int speed = 0;		       // encoder actual advance / 0.1sec
	int encoder_previous = 0;      // encoder reading at end of last 0.1 sec interval;
	int encoder_current = 0;       // encoder reading at end of current 0.1 sec interval
	int target;		       // total encoder travel in this run
	int pacehigh = 0;	       // pace threshold high
	int pacelow = 0;	       // pace threshold low

	target = dist*136;	       // convert dist inches to encoder value
	pacehigh = 50;  // set threshold at 1/8 above and below
	pacelow = 40;


	nMotorEncoder[motorbackleft] = 0;  // initialize encoder reading
	nMotorEncoder[motorbackright] = 0;

	forward(power);			   // start motor at minimal power

	while(nMotorEncoder[motorbackleft] < target){
		wait10Msec(10);
		encoder_current = nMotorEncoder[motorbackleft];
		speed = encoder_current - encoder_previous;
		encoder_previous = encoder_current;
		if(speed > pacehigh)
		{
			power = power  - 1;
			forward(power);
		}
		else if(speed < pacelow)
		{
			power = power + 1;
			forward(power);
		}
	}
	allstop();
	nMotorEncoder[motorbackleft] = 0;
}

void speedchoke_back( int dist) {  // dist: inches; backward
	int power = 15;		       // init power level
	int speed = 0;		       // encoder actual advance / 0.1sec
	int encoder_previous = 0;      // encoder reading at end of last 0.1 sec interval;
	int encoder_current = 0;       // encoder reading at end of current 0.1 sec interval
	int target;		       // total encoder travel in this run
	int pacehigh = 0;	       // pace threshold high
	int pacelow = 0;	       // pace threshold low

	target = -dist*136;	       // convert dist inches to encoder value
	pacehigh = -50;  // set threshold at 1/8 above and below
	pacelow = -40;


	nMotorEncoder[motorbackleft] = 0;  // initialize encoder reading
	nMotorEncoder[motorbackright] = 0;

	forward(-power);			   // start motor at minimal power, backward

	while(nMotorEncoder[motorbackleft] > target){ // backward
		wait10Msec(10);
		encoder_current = nMotorEncoder[motorbackleft];
		speed = encoder_current - encoder_previous;
		encoder_previous = encoder_current;
		if(speed < pacehigh)
		{
			power = power  - 1;
			forward(-power);
		}
		else if(speed > pacelow)
		{
			power = power + 1;
			forward(-power);
		}
	}
	allstop();
	nMotorEncoder[motorbackleft] = 0;
}


<<<<<<< HEAD

void allstop(){
=======
void mov1(){
	nMotorEncoder[motorbackleft]=0;
	while (nMotorEncoder[motorbackleft]<2800){
		motor[motorfrontleft]=-50;
		motor[motorfrontright]=-50;
		motor[motorbackleft]=-50;
		motor[motorbackright]=-50;
	}
	PlaySound(soundBlip);
	while (nMotorEncoder[motorbackleft]<2979){
		motor[motorfrontleft]=-20;
		motor[motorfrontright]=-20;
		motor[motorbackleft]=-20;
		motor[motorbackright]=-20;
	}
	PlaySound(soundBlip);
	allstop();

}
void allstop(){
	//PlaySound(soundBlip);
>>>>>>> cascade/master
	motor[motorfrontleft]=0;
	motor[motorfrontright]=0;
	motor[motorbackleft]=0;
	motor[motorbackright]=0;
}

void forward(int speed){
	motor[motorfrontleft] = speed;
	motor[motorbackleft] = speed;
	motor[motorfrontright] = speed;
	motor[motorbackright] = speed;
}

<<<<<<< HEAD
void turnright(float encodeval){ 
	float dist;
	dist=encodeval;//2465 for 90 degrees, 965.6 for turnrightquarter,1156 for turnrighthalf
=======
void turnright(){ //angle in degrees
	float dist;
	//dist=PI*18.0*sqrt(2.0)*(angle/360.0);
	//dist=dist/(3.0*PI);
	//dist=dist*360.0*4.0+100.0;
	dist=3400;
	dist=((3400)*(.725));
	nMotorEncoder[motorbackleft]=0;
	while (nMotorEncoder[motorbackleft]<dist){
		motor[motorfrontleft]=50;
		motor[motorfrontright]=-50;
		motor[motorbackleft]=50;
		motor[motorbackright]=-50;
	}
	allstop();
}

void turnrightquarter(){ //angle in degrees
	float dist;
	//dist=PI*18.0*sqrt(2.0)*(angle/360.0);
	//dist=dist/(3.0*PI);
	//dist=dist*360.0*4.0+100.0;
	dist=3400;
	dist=((1700)*(.8)*(.71));
	nMotorEncoder[motorbackleft]=0;
	while (nMotorEncoder[motorbackleft]<dist){
		motor[motorfrontleft]=50;
		motor[motorfrontright]=-50;
		motor[motorbackleft]=50;
		motor[motorbackright]=-50;
	}
	allstop();
}

void turnrighthalf(){ //angle in degrees
	float dist;
	//dist=PI*18.0*sqrt(2.0)*(angle/360.0);
	//dist=dist/(3.0*PI);
	//dist=dist*360.0*4.0+100.0;
	dist=3400;
	dist=((1700)*(.68));
>>>>>>> cascade/master
	nMotorEncoder[motorbackleft]=0;
	while (nMotorEncoder[motorbackleft]<dist){
		motor[motorfrontleft]=50;
		motor[motorfrontright]=-50;
		motor[motorbackleft]=50;
		motor[motorbackright]=-50;
	}
	allstop();
}

<<<<<<< HEAD
void turnleft(float encodeval2){ 
	float dist;
	dist=encodeval2; //2278 for 90 degrees,1079.5 for turnlefthalf,
=======
void turnleft(){ //angle in degrees
	float dist;
	//dist=PI*18.0*sqrt(2.0)*(angle/360.0);
	//dist=dist/(3.0*PI);
	//dist=dist*360.0*4.0+100.0;
	dist=3400;
	dist=((3400)*(.67));
>>>>>>> cascade/master
	nMotorEncoder[motorbackright]=0;
	while (nMotorEncoder[motorbackright]<dist){
		motor[motorfrontleft]=-50;
		motor[motorfrontright]=50;
		motor[motorbackleft]=-50;
		motor[motorbackright]=50;
	}
	allstop();
}


<<<<<<< HEAD
=======
void turnlefthalf(){ //angle in degrees
	float dist;
	//dist=PI*18.0*sqrt(2.0)*(angle/360.0);
	//dist=dist/(3.0*PI);
	//dist=dist*360.0*4.0+100.0;
	dist=3400;
	dist=((1700)*(.635));
	nMotorEncoder[motorbackright]=0;
	while (nMotorEncoder[motorbackright]<dist){
		motor[motorfrontleft]=-50;
		motor[motorfrontright]=50;
		motor[motorbackleft]=-50;
		motor[motorbackright]=50;
	}
	allstop();
}
>>>>>>> cascade/master


void slowlydump(int angle, int speed){

	ClearTimer(T1);
	int set;
	while (ServoValue[servoauto] < angle && time1[T1] < 4000  ){

		set = ServoValue[servoauto] + speed;
		servo[servoauto] = set;
		wait10Msec(5);
	}
	ClearTimer(T1);
	while (time1[T1] < 4000){
		set = ServoValue[servoauto] - speed;
		servo[servoauto] = set;
		wait10Msec(5);
	}
}
void grabrundump(){
	servo[servograb] = 255;
	wait10Msec(100);
	forward(50);
	wait10Msec(100);
	allstop();
	wait10Msec(200);
	slowlydump(250, 2);

}

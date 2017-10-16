#pragma config(Sensor, in4,    armPotentiometer, sensorPotentiometer)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)

// sample code //
// contains two functions //


void pickUpBottle()
{

	//open claw
	motor[port5] = 75;
  wait1Msec(500);
  motor[port5] = 0;

	//check arm position, lower into position as needed
	while(SensorValue[armPotentiometer] < 340 || SensorValue[armPotentiometer] >380)
	{
	  while(SensorValue[armPotentiometer] > 380)
		{
			motor[port4] = -20;
		}
		motor[port4] = 0;

		wait1Msec(1000);

		// raise if needed
		while(SensorValue[armPotentiometer] < 340)
		{
			motor[port4] = +30;
		}
		motor[port4] = 0;

	}
	wait1Msec(1000);

	motor[port5] = -127;   //grab the bottle
  wait1Msec(500);
  motor[port5] = 0;

	while(SensorValue[armPotentiometer] < 875)
	{
   	motor[port4] = 127;
  }
   motor[port4] = 0;  //consider using 20 to keep arm up during course


}

void lowerBottle()
{
   while(SensorValue[armPotentiometer] < 900)
   {
     	motor[port4] = 31;
   }

   motor[port4] = 0;

   {
     motor[port6] = -127;     //drop bottle
     wait1Msec(500);
     motor[port6] = 0;
   }

}

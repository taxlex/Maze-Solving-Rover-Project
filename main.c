#include "motor.h"

int main()
  {
	motor_init();  //sets outputs for motors
	
	init_QTR_driver();

	while(1)
	  {
		unsigned char val = get_QTR_value();
		unsigned char sensor_3 = (val & 0x08);
		unsigned char sensor_4 = (val & 0x10);
		unsigned char sensor_5 = (val & 0x20);
		unsigned char sensor_6 = (val & 0x40);
		unsigned char sensor_7 = (val & 0x80);
		
		//if sensor 4 is over black and sensor 3 is over white the rover moves forward
		if(sensor_4 == 0x10 && sensor_3 == 0x00)
		  {   
			move_pulse();
		  }

		//if the three leftmost sensors are over white the rover will move forward and then turn 90 degrees counter-clockwise
		else if(sensor_5 == 0x00 && sensor_6 == 0x00 && sensor_7 == 0x00)
		  {
			left_turn();
		  }

		//if all sensors are over black the rover will move forward and then turn 90 degrees clockwise
		else if(val == 0xFF)
		  {
			right_turn1();
				//if all the sensors are still over black the rover will move forward again and then turn 90 degrees clockwise (using different values)
				if(get_QTR_value() == 0xFF)
				  {      
					right_turn2();
				  }
		  }

		//if sensor 4 is over white then the rover is facing too far to the right and it will brake the left motor to readjust itself
		else if(sensor_4 == 0x00)
		  { 
			readjust_to_left();
		  }

		//if sensor 3 is over black then the rover is facing too far to the left and it will brake the right motor to readjust itself
		else if(sensor_3 == 0x08)
		  {  
			readjust_to_right();
		  }

		//if none of the other conditions are being met, the rover will brake
		else
		  {            
			brakee();
		  }
	  }
  }

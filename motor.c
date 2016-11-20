#include "motor.h"

void motor_init()
  {
	motor_DDR = motor_outputs;
  }

void move_pulse()
  {
	motor_port = forward;
	_delay_ms (move_time);
	motor_port = brake;
	_delay_ms (brake_time);
  }

void left_turn()
  {
	motor_port = forward;
	_delay_ms (forwardL);
	motor_port = spin_left;
	_delay_ms (turn_timeL);
  }

void right_turn1()
  {
	motor_port = forward;
	_delay_ms (forwardR1);
	motor_port = spin_right;
	_delay_ms (turn_timeR1);
  }

void right_turn2()
  {
	motor_port = forward;
	_delay_ms (forwardR2);
	motor_port = spin_right;
	_delay_ms (turn_timeR2);
  }

void readjust_to_left()
  {
	motor_port = brake_left__forward_right;
	_delay_ms (adjust_timeL);
  }

void readjust_to_right()
  {
	motor_port = brake_right__forward_left;
	_delay_ms (adjust_timeR);
  }

void brakee() 
  {
	motor_port = brake;
	_delay_ms (brake_timeE);
  }
	

	

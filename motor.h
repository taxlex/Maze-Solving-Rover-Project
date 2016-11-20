#include <avr/io.h>
#include "qtr_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define motor_port PORTC
#define motor_DDR DDRC
#define motor_outputs 0x0F
#define forward 0x0A
#define brake 0x0F
#define spin_left 0x06
#define spin_right 0x09
#define brake_left__forward_right 0x06
#define brake_right__forward_left 0x09
#define move_time 20
#define brake_time 30
#define forwardL 100
#define turn_timeL 950
#define forwardR1 200
#define turn_timeR1 1000
#define forwardR2 150
#define turn_timeR2 950
#define adjust_timeL 25
#define adjust_timeR 25
#define brake_timeE 1000

void motor_init();
void move_pulse(); 
void left_turn();
void right_turn1();
void right_turn2();
void readjust_to_left();
void readjust_to_right();
void brakee();


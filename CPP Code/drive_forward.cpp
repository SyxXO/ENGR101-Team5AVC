#include <stdio.h>
#include "E101.h"

void set_motor_left(int speed){
	set_motor(1, speed);
}
	
void set_motor_right(int speed){
	set_motor(2, -speed);
	}

int main(){
	init();
set_motor_left(255);
set_motor_right(255);
sleep1(2,0);
set_motor_left(0);
set_motor_right(0);
return 0;
}

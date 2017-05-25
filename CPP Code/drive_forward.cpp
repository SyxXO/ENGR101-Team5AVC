#include <stdio.h>
#include "E101.h"
int main(){
	set_motor(1,255);
	set_motor(2, -255);
	sleep1(3,0);
	set_motor(1,0);
	set_motor(2,0);
return 0;
}

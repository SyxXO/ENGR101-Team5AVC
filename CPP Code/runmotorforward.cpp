#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
init();
int speed = 255;
set_motor(1,speed);
set_motor(2,-speed);
sleep1(5,0);
set_motor(1,0);
set_motor(2,0);
return 0;
}

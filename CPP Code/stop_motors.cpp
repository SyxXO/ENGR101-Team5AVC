#include <stdio.h>
#include "E101.h"
 
int main(){
	init();
	
  set_motor(1,0);
  sleep1(1,0);
  set_motor(2,0);
  stop(0);
}

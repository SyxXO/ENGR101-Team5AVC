#include <stdio.h>
#include "E101.h"

int main(){
	init();
	int adc;
	while(true){
		adc = read_analog(0);
		printf("%d\n",adc);
		sleep1(1,0);
	}
	return 0;
}

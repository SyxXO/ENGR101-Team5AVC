#include <stdio.h>
#include "E101.h"

int kp = 0.5;
int kd = 0.2;
int currError = 0;
int prevError = 0;
int dError = 0;
int pd = 0;

int get_error(){
	take_picture();
	int sum = 0;
	int pix[320];
	int max=0, min=0;
	// Gets pixels at height 120 and stores in an array
	for(int a=0;a<320;a++){
		pix[a] = get_pixel(a,120,3);
	}
	// Calculates threashold value
	for(int a=0;a<320;a++){
		if(pix[a]>max){max=pix[a];}
		else if(pix[a]<min){min=pix[a];}
	}
	double threshold = (max+min)/2;
	// Calculates error sum
	for(int a=0;a<320;a++){
		if(pix[a]>threshold){sum = sum + (a-160);}
	}
	return (sum*kp);
}

void open_gate(){ //opens the wifi gate
        char ip[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
        char please[24] = {'P','l','e','a','s','e'};
        char password[30];
        connect_to_server(ip,1024);
        send_to_server(please);
        receive_from_server(password);
        send_to_server(password);
}
int main(){
	while(true){
		if(read_analog(0)>215){
			open_gate();
			sleep1(1,500000);
			if(read_analog(0)<=215){
				break;
			} else {printf("Gate didn't open");}
		}
	}
	while(true){
		currError = get_error();
		dError = (currError-prevError)*kd;
		prevError = currError;
		pd = currError+dError;
		
	}
}

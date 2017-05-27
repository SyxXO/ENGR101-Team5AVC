#include <stdio.h>
#include "E101.h"

// Fields
float kP = 0.5;      // kP value defined by user
int currError = 0;   // Current error value calculated by get_error()
int whitePix = 0;    // Current white pixels detected by camera
int minWhite = 10;   // Minimum white pixels required to detects a line

// Opens the WiFi gate
void open_gate(){
        char ip[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
        char please[24] = {'P','l','e','a','s','e'};
        char password[30];
        connect_to_server(ip,1024);
        send_to_server(please);
        receive_from_server(password);
        send_to_server(password);
}

// Counts white pixels and retuns error value
int get_error(){
	take_picture();
	int sum = 0;
	whitePix = 0;
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
		if(pix[a]>threshold){sum = sum + (a-160);whitePix = whitePix +1;}
	}
	return ((sum*kP)/(160*1*kP))*255;
}
// Turns the motors with respect to the current currError value
// Drives backwards if the line wasn't detected
void drive(){
	if(whitePix>minWhite){
		if(currError<0){
			set_motor(1,currError);
			set_motor(2,-1*currError);
		}else if(currError>0){
			set_motor(1,currError);
			set_motor(2,-1*currError);
		}else if((currError=0)){
			set_motor(1,127);
			set_motor(2,-1*127);
		}
	}else{
		set_motor(1,-127);
		set_motor(2,100);
	}
	sleep1(0,300000);
	set_motor(1,0);
	set_motor(2,0);
}

// Navigates quadrants one and two
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
		drive();
		sleep1(0,100000);
	}
}

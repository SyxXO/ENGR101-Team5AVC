#include <stdio.h>
#include "E101.h"

int lineDirection(int ht){
	//Variables
	double sf = 1;    //Scale factor for error value
	int cnt = 0;     //Counter for pixel rgb loop
	int error = 0;    //Sum for white line locator
	int max = 0;    //Max rgb value
	int min = 0;    //Min rgb value
	int tol = 0;    //Tolerance for b/w values
	char pix[32];   //Array for pixel rgb values
	char w[32];     //Array to store white(255) or black(0)
	//Gets pixel rgb values and stores them in array pix[]+
	take_picture();
	while(cnt<32){
		pix[cnt] = get_pixel(ht,(cnt+1)*10,3);
		cnt++;
	}
	//Finds the min and max to calculate tolerance value
	for(int a = 0;a<32;a++){
		//printf("Stepped into pixel to white conversion loop");
		if(pix[a]>max){
			max = pix[a];
		} else if(pix[a]<min){
			min = pix[a];
		}
	}
	tol = (max+min)/2;
	//Determines if black(0) or white(255) for pixels in pix[]
	for(int a = 0;a<32;a++){
		if(pix[a]>tol){
			w[a] = 1;
			printf("White Pixel\n");
		}else if(pix[a]<tol){
			w[a] = 0;
			printf("Black Pixel\n");
		}
	}
	for(int a =0;a<32;a++){
		printf("%d = %d\n",a,w[a]);
	}
	
	//Caclulates the error value for white line location
	cnt = 0;
	for(int a = -16;a<16;a++){
		error = error + (w[cnt]*a);
		cnt++;	
	}
	//Debug
	
	printf("%d",error);
	return sf*error;
}

void set_motor_left(int speed){
	set_motor(1, speed);
}
	
void set_motor_right(int speed){
	set_motor(2, -speed);
}

  		 
//make robot go to forward
int drive_forward(){
	printf("Forward");
   	set_motor_left(255);
   	set_motor_right(255);
   	sleep1(0,500000);
   	return 0;}
   	 
//make robot go to left
int turn_left(int error){
	printf("Left");
   	set_motor_left(255);
   	//set_motor_right(sf * position);
   	sleep1(0,500000);
   	return 0;}
   		 
   		 
//make robot got to right
int turn_right(int error){
	printf("right");
   	//set_motor_left(sf * position);
   	set_motor_right(255);
   	sleep1(0,500000);
   	return 0;}



//movemont of robot
   	 int main(){
   		 init();
		 int error;
		 //while(true){
			error = lineDirection(120);
			display_picture(5,0);
			//if(error>10){turn_left(error);}
   		 	//if(error<-10){turn_right(error);}
   		 	//if(-10<error&&error<10){drive_forward();} 
   		 	
		// }
   		 
   		 return 0;}
 

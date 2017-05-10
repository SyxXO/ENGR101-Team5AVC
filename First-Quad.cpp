#include <stdio.h>
#include "E101.h"
//Line direction needs to sample every tenth pixel instead to spped up the calculation
int lineDirection(int ht){
	//Variables
	char sf = 1;    //Scale factor for error value
	int cnt = 0;     //Counter for pixel rgb loop
	signed int sum = 0;    //Sum for white line locator
	int max = 0;    //Max rgb value
	int min = 0;    //Min rgb value
	int tol = 0;    //Tolerance for b/w values
	char pix[320];   //Array for pixel rgb values
	char w[320];     //Array to store white(255) or black(0)
	//Gets pixel rgb values and stores them in array pix[]
	take_picture();
	while(cnt<320){
		pix[cnt] = get_pixel(ht,cnt+1,3);
		//printf("Got pixel %d\n",cnt);
		cnt++;
	}
	//Need to find the correct way to use a for loop for values in an array
	//Finds the min and max to calculate tolerance value
	for(int a = 0;a<320;a++){
		//printf("Stepped into pixel to white conversion loop");
		if(pix[a]>max){
			max = pix[a];
		} else if(pix[a]<min){
			min = pix[a];
		}
	}
	tol = (max+min)/2;
	//Determines if black(0) or white(255) for pixels in pix[]
	for(int a = 0;a<320;a++){
		if(pix[a]>tol){
			w[a] = 1;
			//Debug
			//set_pixel(ht,a,255,255,255);
			//printf("White Pixel");
		}else if(pix[a]<tol){
			w[a] = 0;
			//Debug
			//set_pixel(ht,a,1,1,1);
			//printf("Black Pixel");
		}
	}
	//Caclulates the error value for white line location
	for(signed int a = -160;a<160;a++){
		sum = sum + (w[a]*a);	
	}
	//Debug
	//display_picture(10,0);
	return sf*sum;
}

void test_camera(int ht){
	int lnPos;
	lnPos = lineDirection(ht);
	printf("Position %d\n",lnPos);
}

//movemont of robot
   	 int main(){
   		 init();
		 int error;
		 while(true){
			error = lineDirection(120);
			if(error>0){turn_left(error);}
   		 	if(error<0){turn_right(error);}
   		 	if(error=0){drive_forward;} 
		 }
   		 
   		 return 0;}
   		 
    //make robot go to forward
   	 int drive_forward(){
   		 set_motor(1,255);
   		 set_motor(2,-255);
   		 sleep1(0,500000);
   		 return 0;}
   	 
    //make robot go to left
   	 int turn_left(int sum){
   		 if(-2025>sum>-765){
   		 set_motor(1,120);
   		 set_motor(2,-255);
   		 sleep1(0,500000);
   		 return 0;}}
   		 
   		 
    //make robot got to right
   	 int turn_right(int sum){
   		 if(2025>sum>765){
   		 set_motor(1,-255);
   		 set_motor(2,120);
   		 sleep1(0,500000);
   		 return 0;}}

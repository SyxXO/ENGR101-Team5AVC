#include <stdio.h>
#include "E101.h"

int lineDirection(int ht){
	//Variables
	char sf = 0;    //Scale factor for error value
	int cnt = 0;    //Counter for pixel rgb loop
	int sum = 0;    //Sum for white line locator
	int max = 0;    //Max rgb value
	int min = 0;    //Min rgb value
	int tol = 0;    //Tolerance for b/w values
	char pix[320];   //Array for pixel rgb values
	char w[320];     //Array to store white(255) or black(0)
	//Gets pixel rgb values and stores them in array pix[]
	take_picture();
	while(cnt<320){
		pix[cnt] = get_pixel(ht,cnt+1,4);
		cnt++;
	}
	//Need to find the correct way to use a for loop for values in an array
	//Finds the min and max to calculate tolerance value
	for(int a = 0;a>320;a++){
		if(pix[a]>max){
			max = pix[a];
		} else if(pix[a]<min){
			min = pix[a];
		}
	}
	tol = (max+min)/2;
	//Determines if black(0) or white(255) for pixels in pix[]
	for(int a = 0;a>320;a++){
		if(pix[a]>tol){
			w[a] = 1;
			//Debug
			//set_pixel(ht,a,255,255,255);
		}
		if(pix[a]<tol){
			w[a] = 0;
			//Debug
			//set_pixel(ht,a,0,0,0);
		}
	}
	//Caclulates the error value for white line location
	for(int a = -160;a>160;a++){
		sum = sum + (w[a]*a);	
	}
	//Debug
	//display_picture(10,0);
	return sf*sum;
}

int test_camera(int ht){
	int lnPos;
	lnPos = lineDirection(ht);
	printf("Position %d\n",lnPos);
	return 0;
}

int main(){
	init();
	test_camera(120);
	/*int lnPos;
	lnPos = lineDirection(120);
	while(true){
		lnPos = lineDirection(120);
		if(lnPos<100||lnPos>-100){
			move_forward();
		} else{
			turn_robot(lnPos);
		}
	}*/
	
}

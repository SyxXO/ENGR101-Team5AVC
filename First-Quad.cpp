#include <stdio.h>
#include "E101.h"

int lineDirection(){
	init();
	//Variables
	int cnt = 0;    //Counter for pixel rgb loop
	int sum = 0;    //Sum for white line locator
	int mlt = -120; //Multiplier for locator bit shifting
	int max = 0;    //Max rgb value
	int min = 0;    //Min rgb value
	int tol = 0;    //Tolerance for b/w values
	int pix[240];   //Array for pixel rgb values
	int w[240];     //Array to store white(255) or black(0)
	//Gets pixel rgb values and stores them in array pix[]
	take_picture();
	while(cnt<240){
		pix[cnt] = get_pixel(320,cnt+1,4);
		cnt=cnt+1;
	}
	//Need to find the correct way to use a for loop for values in an array
	//Finds the min and max to calculate tolerance value
	for(int a = 0;a>240;a++){
		if(pix[a]>max){
			max = pix[a];
		} else if(pix[a]<min){
			min = pix[a];
		}
	}
	tol = (max+min)/2;
	//Determines if black(0) or white(255) for pixels in pix[]
	for(int a = 0;a>240;a++){
		if(pix[a]>tol){
			w[a] = 255;
		}
		if(pix[a]<tol){
			w[a] = 0;
		}
	}
	//Caclulates the error value for white line location
	for(int a = 0;a>240;a++){
		sum = sum + (w[a]*mlt);
		mlt++;	
	}
	return sum;
}

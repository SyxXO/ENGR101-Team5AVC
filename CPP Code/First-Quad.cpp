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
		//printf("%d = %d\n",a,w[a]);
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

int drive_forward(){ //make robot go to forward
	printf("Forward");
   	set_motor_left(80);
   	set_motor_right(80);
   	sleep1(0,500000);
   	set_motor_left(0);
   	set_motor_right(0);
   	return 0;}
   	 
int turn_left(int error){ //make robot go to left
	printf("Left");
   	set_motor_left(-error);
   	set_motor_right(50);
   	sleep1(0,500000);
   	return 0;}
   		 
int turn_right(int error){ //make robot got to right
	printf("right");
   	set_motor_left(50);
   	set_motor_right(error);
   	sleep1(0,500000);
   	return 0;}

int drive_backward(){ //make robot drive backwards
	printf("backward");
	set_motor_left(-50);//needs to make robot turn at an angle to avoid it looping movement//
	set_motor_right(-80);
	sleep1(0,500000);
   	return 0;}

 int drive_stop(){ //make robot stop
	 printf("stop");
	 set_motor_left(0);
	 set_motor_right(0);
	 sleep1(0,500000);
	 return 0;}

void wifi_gate(){ //opens the wifi gate
        char ip[15];
        char please[24];
        please[0] = 'P';
        please[1] = 'l';
        please[2] = 'e';
        please[3] = 'a';
        please[4] = 's';
        please[5] = 'e';
        ip[0] = '1';
        ip[1] = '3';
        ip[2] = '0';
        ip[3] = '.';
        ip[4] = '1';
        ip[5] = '9';
        ip[6] = '5';
        ip[7] = '.';
        ip[8] = '6';
        ip[9] = '.';
        ip[10] = '1';
        ip[11] = '9';
        ip[12] = '6';
        char password[30];
        connect_to_server(ip,1024);
        send_to_server(please);
        receive_from_server(password);
        send_to_server(password);
}
	
bool front_wall(){ //detects if there is an obsticle infront of the robot
		return (read_analog(0)>215);
}

bool left_wall(){ //detects if there is an obsticle to the left of the robot
		return (read_analog(1)>127);
}

bool right_wall(){ //detects if there is an obsticle to the right of the robot
		return (read_analog(2)>127);
}

int main(){
   	init();
   	//int quadCnt=1;
   	int error;
   	while(true){
		if(front_wall()){
			printf("Detected gate in the way");
			wifi_gate();
			printf("Opened gate");
		} else{
			error = lineDirection(120);
			if(error<-50){
				turn_left(error);
			} else if(error>50){
				turn_right(error);
			} else if(error=0){
				drive_backward();
			} else if(error<50&&error>-50){
				drive_forward();
			}
		}
	}
   		 
   		 return 0;}
 

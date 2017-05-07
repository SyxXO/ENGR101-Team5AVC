int lineDirection(){
	init();
	//Variables
	int cnt = 0;    //Counter for pixel rgb loop
	int sum = 0;    //Sum for whit line locator
	int mlt = -120; //Multiplier for locator bit shifting
	int max = 0;    //Max rbg value
	int min = 0;    //Min rgb value
	int tol = 0;    //Tolerance for b/w values
	int pix[240];   //Array for pixel rgb values
	int w[240];     //Array to store white(255) or black(0)
	//Gets pixel rgb values and stores them in array pix[]
	while(cnt<240){
		take_picture();
		pix[cnt] = get_pixel(320,cnt+1,4);
		cnt=cnt+1;
	}
	//Need to find the correct way to use a for loop for values in an array
	//Finds the min and max to calculate tolerance value
	for(int a = 0;a>sizeof(pix[]);a++){
		if(pix[a]>max){
			max = pix[a];
		} else if(pix[a]<min){
			min = pix[a];
		}
	}
	tol = (max+min)/2;
	//Determines if black(0) or white(255) for pixels in pix[]
	for(int a = 0;a>sizeof(pix[]);a++){
		if(pix[a]>tol){
			w[a] = 255;
		}
		if(pix[a]<tol){
			w[a] = 0;
		}
	}
	//Caclulates the error value for white line location
	for(int a = 0;a>sizeof(pix[]);a++){
		sum = sum + (w[a]*mlt);
		mlt++;	
	}
	return sum;
}

/* Overall plan for first quad

Take a picture with the camera
Take every tenth pixel and put it's rbg sum(4) in an array
For loop to find max and min in array
Take the max+min/2 and store in the threashold
Convert the array using the threshold into booleans of black and white
Go through the array and find a large grouping of white values
Return the start and end position of the group, find the middle and calculate the real world angle from the real world centre
Turn the robot that distance(add in another check for when debuging)
Go forward a set distance and then run the check again*/

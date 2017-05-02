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

#include <stdio.h>
#include "E101.h"

Char maze_solve(Boolean left, Boolean right, Boolean forward){
  if (left){
    return 'f';
  }
  else if (right){
    return 'f';
  }
  else if (forward){
    return 'l';
  }
  else if (left && right){
    return 'f';
  }
  else if (left && forward){
    return 'r';
  }
  else if (right && forward){
    return 'l';
  }
 
}

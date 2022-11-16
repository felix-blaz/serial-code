#include "header.h"
//cellCount
void cellCount(int** currentWorld, int* countS, int* countI, int* countE, int* countR, int* countD )
{
//these values will be incremented when ever it cell is present
*countS = 0;
*countI = 0;
*countD = 0;
*countR = 0;
*countE = 0;

for (int i = 0; i < Total_Rows; i++){
  for (int j = 0; j < Total_Cols; j++){

    if (currentWorld[i][j] == S){
      (*countS)++;
    }
    else if (currentWorld[i][j] == I){
      (*countI)++;
    }
    else if (currentWorld[i][j] == E){
      (*countE)++;
    }
    else if (currentWorld[i][j] == D){
      (*countD)++;
    }
    else
      {
	(*countR)++;
      }
    //copying the current world to the future world

  }
 }	
}

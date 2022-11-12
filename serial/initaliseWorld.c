#include "header.h"

int getRandom(int max_val)
{
    return rand() % max_val;
}

//initalise
void initaliseWorld(int** currentWorld, int** futureWorld){
	//phase 1 initalise World with just S cells
    for(int i = 0;  i < Total_Rows; i++)
    {
		for(int j = 0; j < Total_Cols; j++)
		{
			currentWorld[i][j] = S;
         }
    }
//make one cell infected in a random position
int r1 = getRandom(Total_Rows);
int c1 = getRandom(Total_Cols);
currentWorld[r1][c1] = I;

//copy the currentWorld to the futureWorld
    for(int i = 0; i < Total_Rows; i++)
    {
	    for(int j = 0; j < Total_Cols; j++)
        {
            futureWorld[i][j] = currentWorld[i][j];
        }
    }

}

#include <stdio.h>
#include <stdlib.h>
#define S 1
#define E 2
#define I 3
#define R 4
#define D 0

#define Total_Rows 10
#define Total_Cols 10

#define GENERATIONS 5

//all probabilities 
#define ProbA 0.125
#define ProbB 0.25
#define ProbC 0.375
#define ProbD 0.5
#define ProbE 0.675
#define ProbF 0.75
#define ProbG 0.875
#define ProbH 1
#define ProbI 0.9


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
	    printf("%d", currentWorld[i][j]);
        }
	    printf("%n");
    }

}



//neighbourSearch

void neighbourSearch(int** currentWorld, int** futureWorld)
{
	for(int i =0; i < Total_Rows; i++)
	{
	    for(int j = 0; j < Total_Cols; j++)
        {
	int numI = 0;
	if(currentWorld[i][j] == S)
	{
		//explain
		int left_neigh = j - 1;
		int right_neigh = j + 1;
		int upwords_neigh = i - 1;
		int down_neigh = i + 1;

		if (left_neigh < 0)
		{
			left_neigh = Total_Cols - 1;
		}
		if (right_neigh > Total_Cols - 1)
		{
			right_neigh = 0;
		}

		if (upwords_neigh < 0)
		{
			upwords_neigh = Total_Rows - 1;
		}

		if (down_neigh > Total_Rows - 1)
		{
			down_neigh = 0;
		}


					//Explain	
					// left cell
		if (currentWorld[i][left_neigh] == I)
	      	{	
		  numI++;
      		}
					// top left cell
				if (currentWorld[upwords_neigh][left_neigh] == I)
				  {
					numI++;
				  }
					// bottom left cell
				if (currentWorld[down_neigh][left_neigh] == I)
				{
					numI++;
				}
					// right cell
				if (currentWorld[i][right_neigh] == I)
				{
					numI++;
				}
					// top right cell
				if (currentWorld[upwords_neigh][right_neigh] == I)
				{
					numI++;
				}
					// bottom right cell
				if (currentWorld[down_neigh][right_neigh] == I)
				{
					numI++;
				}
					// top cell
				if (currentWorld[upwords_neigh][j] == I)
				{
					numI++;
				}
					// bottom cell
				if (currentWorld[down_neigh][j] == I)
				{
					numI++;
				}

					//EXPLAIN
				if (numI == 1 && getRandom(1001) <= ProbA * 1000)
				{
					futureWorld[i][j] = E;
				}
				
				if (numI == 2 && getRandom(1001) <= ProbB * 1000) 
				 {
					futureWorld[i][j] = E;
				 }
				
				if (numI == 3 && getRandom(1001) <= ProbC * 1000)
				  {
					futureWorld[i][j] = E;
				  }

				if (numI == 4 && getRandom(1001) <= ProbD * 1000)
				  {
					futureWorld[i][j] = E;
				  }

				if (numI == 5 && getRandom(1001) <= ProbE * 1000)
				  {
					futureWorld[i][j] = E;
				  }

                if (numI == 6 && getRandom(1001) <= ProbF * 1000)
            	{
					futureWorld[i][j] = E;
	      	}

				if (numI == 7 && getRandom(1001) <= ProbG * 1000)
				  {
					futureWorld[i][j] = E;
			 	}

				if (numI == 8 && getRandom(1001) <= ProbH * 1000) 
				  {
					futureWorld[i][j] = E;
				}
    }
	//expain
    else if (currentWorld[i][j] == E)
    {
        if (getRandom(1001) < ProbI * 1000) {
		     futureWorld[i][j] = I;
	    }
    }
	
    else if (currentWorld[i][j] == I)
	{
		if (getRandom(1001) < ProbA * 1000) {
			    futureWorld[i][j] = D;
		}
	else
		{
			futureWorld[i][j] = R;
		}
	}
	
    else if (currentWorld[i][j] == R)
       	{
	       	futureWorld[i][j] = S;
       	}
        }
    }
}


void cellCount(int** currentWorld, int* countS, int* countI, int* countE,
	int* countR, int* countD )
{
	//these values will be incremented when ever it cell is present
	*countS = 0;
	*countI = 0;
	*countD = 0;
	*countR = 0;
	*countE = 0;

	for (int i = 0; i < Total_Rows; i++)
	{
		for (int j = 0; j < Total_Cols; j++)
		{

			if (currentWorld[i][j] == S)
			{
				(*countS)++;
			}
			else if (currentWorld[i][j] == I)
			{
				(*countI)++;
			}
			else if (currentWorld[i][j] == E)
			{
				(*countE)++;
			}
			else if (currentWorld[i][j] == D)
			{
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



   // create a two-dimensional matrix dynamically
int** createTwoDimenArray(const int rows, const int cols)
{
    // create two-d pointers
    int** arr2D = (int**)malloc(rows * sizeof(int*));

   	 // create the memory
    int* memory = (int*)malloc(rows * cols * sizeof(int));

   	 // adjust pointers with memory
    for (int i = 0; i < rows; i++)
    {
        arr2D[i] = &memory[i * cols];
    }
    return arr2D;
}



int main(int argc, char const *argv[])
{

 
}

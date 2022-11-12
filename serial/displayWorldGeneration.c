#include "header.h"
//displaying each generation world
void displayWorldGeneration(int** currentWorld, int gen)
{
	char fileName[50] = "generation";
	char genNumberString[50];
	sprintf(genNumberString, "%d", gen);
	strcat(fileName, genNumberString);
	strcat(fileName, ".txt");

	FILE* fout = fopen(fileName, "w");
	for (int i = 0; i < Total_Rows; i++)
	{
		for (int j = 0; j < Total_Cols; j++)
		{
			fprintf(fout, "%d ", currentWorld[i][j]);
		}
		fprintf(fout, "\n");
	}
		//closing the file
	fclose(fout);
}

// creating a two-dimensional matrix dynamically
int** createTwoDimenArray(const int rows, const int cols)
{
    // creating two-d pointers
    int** arr2D = (int**)malloc(rows * sizeof(int*));

   	 // creating the memory
    int* memory = (int*)malloc(rows * cols * sizeof(int));

   	 // adjust pointers with memory
    for (int i = 0; i < rows; i++)
    {
        arr2D[i] = &memory[i * cols];
    }
    return arr2D;
}

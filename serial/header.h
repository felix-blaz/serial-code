
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cell states
#define S 1
#define E 2
#define I 3
#define R 4
#define D 0

//array size
#define Total_Rows 10 //world height
#define Total_Cols 10 //world length

//number of generations
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


//first generation
void initaliseWorld(int** currentWorld, int** futureWorld); //initaliseWorld.c

//showing each generation world in a seperate file
void displayWorldGeneration(int** currentWorld, int gen); //displayWorldGeneration.c

//counts the total number of cells from each generations
void cellCount(int** currentWorld, int* countS, int* countI, int* countE, int* countR, int* countD); //cellCount.c

//implements all the rules and looks at neighbours
void neighbourSearch(int** currentWorld, int** futureWorld); //neighbourSearch.c

int getRandom(int max_val);

int** createTwoDimenArray(const int rows, const int cols);

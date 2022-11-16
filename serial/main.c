#include "header.h"


int main(int argc, char const *argv[])
{

  int** currentWorld = createTwoDimenArray(Total_Rows, Total_Cols);
  int** futureWorld = createTwoDimenArray(Total_Rows, Total_Cols);
  
  //starting up the world
  initaliseWorld (currentWorld, futureWorld);
  
  printf("Simulating...\n");
  FILE* fout = fopen("data/output.txt", "w");
  
  
  int gen = 0;
  //this will execute the total number of each type of cell in each gen to a file
  while (gen < GENERATIONS){
    // printf("Executing the generation %d\n",  gen);
    
    
    neighbourSearch (currentWorld, futureWorld);
    int countS = 0;
    int countE = 0;
    int countI = 0;
    int countR = 0;
    int countD = 0;
    cellCount(futureWorld, &countS, &countI, &countE, &countR, &countD);
    
    
    fprintf(fout, "Generation: %d and Suseptable: %d and Exposed: %d and Infected: %d and Recovered: %d and Dead: %d\n",
	    gen, countS, countE, countI, countR, countD);
    
    
    displayWorldGeneration (futureWorld, gen + 1);
    
    for (int i = 0; i < Total_Rows; i++){
      for (int j = 0; j < Total_Cols; j++){
	currentWorld[i][j] = futureWorld[i][j];
      }
      
    }
    gen++;
  }
  
  fclose(fout);
  
  printf("Finished Simulation\n");
  
  free(currentWorld[0]);
  free(currentWorld);
  
  free(futureWorld[0]);
  free(futureWorld);
  
  return 0;
}







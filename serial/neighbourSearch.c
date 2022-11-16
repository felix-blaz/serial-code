#include "header.h"
void neighbourSearch(int** currentWorld, int** futureWorld)
{
  for(int i =0; i < Total_Rows; i++)
    {
      for(int j = 0; j < Total_Cols; j++)
        {
	  int numI = 0;
	  if(currentWorld[i][j] == S)
	    {
	      /*
		
		if(currentWorld[(i-1+totalRows)%totalRows][(j-1+totalCols)%totalCols]=I){numN++;}
		if(currentWorld[(i-1+totalRows)%totalRows][j]=I){numN++;}
		if(currentWorld[(i-1+totalRows)%totalRows][(j+1+totalCols)%totalCols]=I){numN++;}
		if(currentWorld[i][(j-1+totalCols)%totalCols]=I){numN++;}
		if(currentWorld[i][(j+1+totalCols)%totalCols]=I){numN++;}
		if(currentWorld[(i+1+totalRows)%totalRows][j-1+totalCols]=I){numN++;}
		if(currentWorld[(i+1+totalRows)%totalRows][j]=I){numN++;}
		if(currentWorld[i+1][((j+1+totalCols)%totalCols)+j-1]=I){numN++;}
		
	      */
	      //giving each combination a name
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



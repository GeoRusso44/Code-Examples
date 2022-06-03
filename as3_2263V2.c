#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int maxWeightM(int val1, int val2){
	if(val1 > val2){
		return val1;
	}else{
		return val2;
	}
	
}

void swapArray(int matrix1[],int matrix2[],int length){
	int temp = 0;
	
	for( int i =0; i< length; i++){
		temp = matrix1[i];
		matrix1[i] = matrix2[i];
		matrix2[i] = temp; 
	}
	
}
int main(int argc, char *argv[])
{
	
	if ( argc != 4 ) /* argc should be 4 due to the two files, the length, and the name of the prog */
    {
		EXIT_FAILURE;
	}
	int pathLength = atoi(argv[1]);
	
	//Args 2 is the matrix
    FILE *f_matrix = fopen(argv[2], "r");
	//Args 3 is the words
	FILE *f_words = fopen(argv[3], "r");
	// Some var
	int iErr = -1;
    int n = 0;
	
	//starts to read in the words and if its not 1 its bad input
    iErr = fscanf(f_words, "%d", &n);
    
	if (iErr != 1)
    {
        return EXIT_FAILURE;
    }
	
    char vertex_names[n][50];
    char *pointer_array[n];


    for (int i = 0; i < n; i++)
    {
        pointer_array[i] = &vertex_names[i][0];
    }

    //Scan the words;
   
   for (int i = 0; i < n; i++)
    {	
       //iErr = fscanf(f_words, " %s", pointer_array[i]);
      iErr = fscanf(f_words, " %[^\n]%*c", pointer_array[i]);
	  
	  if (iErr != 1)
    {
        return EXIT_FAILURE;
    }
		//printf("%s",pointer_array[i]);
    }
    fclose(f_words);

    //Scan the adjacency matrix:
    int matrix_n;
    iErr = fscanf(f_matrix, "%d", &matrix_n);
    if (iErr != 1 || matrix_n != n)
    {
        return EXIT_FAILURE;
    }

    int adjacencyMatrix[n * n];

    for (int i = 0; i < n * n; i++)
    {
        iErr = fscanf(f_matrix, "%d", &adjacencyMatrix[i]);

        if (iErr != 1)
        {
            return EXIT_FAILURE;
        }
		//printf("%d",adjacencyMatrix[i]);
    }
    fclose(f_matrix);

	int weightMatrixA[n*n];
	for(int i = 0; i< n*n;i++){
		weightMatrixA[i] = adjacencyMatrix[i];
	}
	
	int weightMatrixB[n*n];
	
	for(int i = 0; i< n*n;i++){
		weightMatrixB[i] = adjacencyMatrix[i];
	}
	
	int weightDistance[n*n];
	
	
	for(int i = 0; i< n*n;i++){
		weightDistance[i] = adjacencyMatrix[i];
	}
	int finalMatrixP[n*n];
		 for (int i = 0; i < n * n; i++)
    {
		finalMatrixP[i] = 0;
    }
	int minWeight =  INT_MAX;
	int distance = 0;
	//the algorthim of DOOOOOOOOMMMMMM
	for(int m = 1; m < pathLength;m++){
		for(int j = 0; j< n; j++){
			for(int k = 0; k< n;k++){
				if(j != k){
					minWeight =  INT_MAX;
					for (int g = 0; g< n;g++){
						if(g!= j && g!=k){
							distance = maxWeightM(adjacencyMatrix[j*n+g],weightMatrixA[g*n+k]);	
							if(distance < minWeight){
							minWeight = distance;
							}
						}
						
					}
					if (minWeight < weightDistance[j*n+k]){
					weightDistance[j*n+k] = minWeight;
					}
					weightMatrixB[j*n+k] = minWeight;	
				}
			}
			
		}
		int val = n*n;

		swapArray(weightMatrixA,weightMatrixB,val);
	}
	
	
	printf("\n");
	for(int j = 0; j < n;j++){
		for(int k = 0; k < n;k++){
			if(j!=k){
				if(weightDistance[j*n +k] == adjacencyMatrix[j*n+k]){
					finalMatrixP[j*n+k] = adjacencyMatrix[j*n+k];
				}
			}
		}
	
	}

	//End of the program
	
    //Write to .dot file
    FILE *fp = fopen("finalOutput.dot", "w+");
    iErr = fputs("graph{\n\toverlap=scale",fp);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(finalMatrixP[i*n+j] == finalMatrixP[j*n+i] && finalMatrixP[i*n+j] != 0){
                iErr = fputs("\n\t\"",fp);
                iErr = fputs(pointer_array[i],fp);
                iErr = fputs("\"--\"",fp);
                iErr = fputs(pointer_array[j],fp);
                iErr = fputs("\"",fp);

                finalMatrixP[j*n+i] = -1;
            }
            

        }


    }

    iErr = fputs("\n}",fp);
     fclose(fp);

    return EXIT_SUCCESS;
}








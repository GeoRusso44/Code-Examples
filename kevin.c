#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main (int argc,char** argv){
    int n;
    int q;
    int err;
    int minWeight;
    int dist;
    if (argc!=4){
        printf("Incorrect format. Please enter a q value, the matrix data file, and the concept data file.\n");
        return EXIT_FAILURE;
    }
    char *qPointer = argv[1];
    q = atoi(qPointer);
    FILE *weightMatrix = fopen(argv[2],"r");
    FILE *labels = fopen(argv[3],"r");
    if (weightMatrix == NULL || labels == NULL){
        printf("Error reading file.\n");
        return EXIT_FAILURE;
    }
    FILE *PFNET = fopen("pfnet.dot","w+");
    err = fscanf(weightMatrix,"%d\n",&n);
    if (err!=1){
        printf("Error reading file.\n");
        return EXIT_FAILURE;
    }
    int wMatrix [n][n];
    int readValue;
    //Initializing wMatrix
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (fscanf(weightMatrix,"%d",&readValue) != 1){
                printf("Error reading file.\n");
                return EXIT_FAILURE;
            }
            wMatrix[i][j] = readValue;
        }
    }
    //Initializing labels array
    char chars[n*50];
    char *charPointer[n];
    for (int i = 0; i<n; i++){
        charPointer[i] = chars + (i*50);
    }
    fgets(charPointer[0],50,labels);
    for(int i = 0; i < n; i++){
        fgets(charPointer[i],50,labels);
    }
    int wAMatrix[n][n];
    int wBMatrix[n][n];
    int dqMatrix[n][n];
    int pMatrix[n][n];
//Initializing graphs wAMatrix, dqMatrix and pMatrix
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            pMatrix [i][j] = 0;
            wAMatrix [i][j] = wMatrix[i][j];
            dqMatrix [i][j] = wMatrix[i][j];
        }
    }
//Pathfinder algorithm
    for (int m = 1; m<q; m++){
        for (int j = 0; j<n; j++){
            for (int k = 0; k<n; k++){
                if (k==j){
                    continue;
                } 
                minWeight = INT_MAX;
                for (int g = 0; g<n; g++){
                    if (g==j || g==k){
                        continue;
                    }
                    dist = MAX(wMatrix[j][g],wAMatrix[g][k]);
                    if (dist < minWeight){
                        minWeight = dist;
                    }
                }
                if (minWeight<dqMatrix[j][k]){
                    dqMatrix[j][k]= minWeight;
                }
                wBMatrix[j][k] = minWeight;
            }
        }
        //Swapping wAMatrix and wBMatrix
        int temp[n][n];
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                temp[i][j] = wAMatrix[i][j];
                wAMatrix[i][j] = wBMatrix[i][j];
                wBMatrix[i][j] = temp[i][j];
            }
        }
    }
    for (int j = 0; j<n;j++){
        for (int k = 0; k<n; k++){
            if (k==j){
                continue;
            }
            if (dqMatrix[j][k] == wMatrix[j][k]){
                pMatrix[j][k] = wMatrix[j][k];
            }
        }
    }
    fprintf(PFNET,"graph {\r\n overlap = scale \r\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (j<i){
                continue;
            }
            if (pMatrix[i][j]>0){
                fprintf(PFNET,"\"%s\" -- \"%s\"\n",charPointer[i],charPointer[j]);
            }
        }
    }
    fprintf(PFNET,"}");
    fclose(weightMatrix);
    fclose(labels);
    fclose(PFNET);
    return EXIT_SUCCESS;
}
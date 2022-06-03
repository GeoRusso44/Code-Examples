#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void diameter(int n, int m, int array[]){
int adjacencyMatric[m][m];	
int counter = 0;

// these are the var for floyeds alg
int i = 0;
int k = 0;
int j = 0;
int lCount = 0;
int iCount = 0;
// there is only n armount of edges so the loop goes untill the amout are filled
	while(counter != n){
		iCount = 0;
		for (i = 0; i < n; i++){
			if(array[i] == iCount){
			lCount = 0;	
				for (k = 1; k < n; k = k +2){
					
					if(array[k] == lCount){
					adjacencyMatric[i][k] = 1;
					}else{
					adjacencyMatric[i][k] = 0;	
					}
				
				lCount++;
				}
				
			}
			
		
		}
		
		
	}
	
}



int main(){
int numberEdge = 0;
int vertex = 0;
int vertexDouble;

//scan in the data
printf("Enter the amount of vertices \n");
scanf("%d", &vertex);
printf("Enter the amount of edges \n");
scanf("%d", &numberEdge);

vertexDouble = (numberEdge * 2) - 1;

int edge[vertexDouble];
int path[0];
int i = 0;
printf("Enter the pairs \n");

for(i = 0;i < vertexDouble;){
	scanf("%d", &edge[i]);
	i = i + 1;
	scanf("%d", &edge[i]);
	i = i + 1;	
}
void diameter(numberEdge, vertex, edge);
return EXIT_SUCCESS;
}
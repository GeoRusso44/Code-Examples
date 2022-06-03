#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//parse through the graph
int readGraph(int n, int m, int graph[]){
	  //initialize vars
  int i = 0;
  int x = 0;
  int currentV = 0;
  int nextV = 0;
  int path = 0;
  int hPath = 0;
  int counterPath = 0;
  int n2;
  char output[100];
  n2 = (n * 2) - 1;
printf("enter the path \n");	
	scanf("%d", &currentV);
	output[x] = currentV;
	x = x + 1;
	int found = 0;
	
	
	while(found != 1){
		scanf("%d", &nextV);
			output[x] = nextV;
			 x = x + 1;
		for(i = 0; i < n2;){
			if(currentV == graph[i]){
			 	if(nextV == graph[i+1]){
					currentV = graph[i+1];
					counterPath++;
				}
			}
			i = i + 2;
		}
		if(currentV == m -1){
			if(counterPath == m){
				hPath = 1;
			}
			found = 1;
			path = 1;
		}
	}
	 printf("The numbers %s.", output);
	if(path == 1){
		printf("are a path. \n");
		if(hPath == 1){
		printf("They are also a Hamiltonian path. ");
		
		}else{
		printf("They are also not a Hamiltonian path. ");
		
		}
	}else {
		printf("are not a path. \n");
	}
		
		return 1;
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
readGraph(numberEdge, vertex, edge);

return EXIT_SUCCESS;
}
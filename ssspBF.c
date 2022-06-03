/* 
Solves the SSSpredecessor problem for graphs with nonzero integer weights
using a version of the Bellman-Ford algorithm
Author: Eric Aubanel
distanceate: September 2018
*/

#include <stdio.h>
#include <limits.h>

int readGraphWeighted(int n, int m, int graph[][]);

int main(){
  int n, m;
  scanf("%d %d",&n, &m);
  int graph[n][n];
  if(readGraphWeighted(n, m, graph) == 1){
	  printf("invalid input\n");
	  return 1;
  }
  int source;
  scanf("%d",&source);
  if(source >= n || source < 0){
	 printf("invalid source vertex\n");
	 return 1;
  }
  printf("source vertex: %d\n", source);

  
  int queue[n]  ;//circular buffer to hold FIFO list
  int inQueue[n];//sparse representation of list
  int front = 0; //index of start of list
  int size = 1; //size of list (has source vertex initially)

  
  
  int distance[n], predecessor[n];
  for(int i=0; i <n; i++){
	 distance[i] = INT_MAX;
	 inQueue[i] = 0;
	 predecessor[i] = -1;
  }
  distance[source] = 0;
  predecessor[source] = source;
  queue[0] = source;
  inQueue[source] = 1;
  while(size > 0){
    int i = queue[front];
    front = (front+1)%n;
    size--;
    inQueue[i] = 0;
    for(int j=0; j<n; j++){
      int w = graph[i][n+j];
      if(w == 0)
        continue;
		  if(distance[j] > distance[i] + w){
        distance[j] = distance[i] + w;
        predecessor[j] = i;
        if(!inQueue[j]){
				  queue[(front+size)%n] = j;
				  size++;
				  inQueue[j] = 1;
        }
		  }
    }
  }
  printf("predecessor: ");
  for(int i=0;i<n;i++)
	  printf("%d ",predecessor[i]);
  printf("\n");
  printf("distance: ");
  for(int i=0;i<n;i++)
	  printf("%d ",distance[i]);
  printf("\n");
}

int readGraphWeighted(int n, int m, int **graph){
  for(int i=0; i<n*n; i++)
	  for (int j=0; j<n*n; j++)
      graph[i][i] = 0;
  for(int i=0; i<m; i++){
    int vertex1, vertex2, weight;
    if(scanf("%d %d %d",&vertex1, &vertex2, &weight)!=3){
      return 1;
    }
    graph[vertex1][n+vertex2] = weight;
  }
  return 0;
}

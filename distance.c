#include <stdio.h>
#include <stdlib.h>
#define INF 99999

int readGraphWeighted(int n, int m, int graph[]);

int main() {
	int n, m;
    
	scanf("%d", &n);
	scanf("%d", &m);
    
	int graph[n*n];
    
	readGraphWeighted(n, m, graph);

	int s;
    
    scanf("%d", &s);

    int list[n];
    //int inQueue[n];
    int size = 0;
	int front = 0;
    int pos = 0;
    int val;
	
	int predecessor[n];
	int distance[n];
	
	for(int m = 0; m <= n - 1; m++) {
		distance[m] = INF;
        predecessor[m] = -1;
    }
    
    distance[s] = 0;
    predecessor[s] = s;

    pos = (front+size)%n;
    list[pos] = s;
    size++;
    
    int i = 0;
    while(size > 0) {
        i = list[front];
        front = (front+1)%n;
        size--;
        for(int j = 0; j <= n - 1; j++) {
            if(graph[i*n+j] != 0) {
                if(distance[j] > distance[i] + graph[i*n+j]) {
                    distance[j] = distance[i] + graph[i*n+j];
                    predecessor[j] = i;
                    int l = 0;
                    for(int k = front; k < (front+size)%n; k++) {
                        if(list[k%n] != j) {
                            l++;
                        }
                    }
                    if(l == size) {
                        pos = (front+size)%n;
                        list[pos] = j;
                        size++;
                    }
                }
            }
        }
    }
	
	printf("source vertex: %d\n", s);
	printf("P:");
	for (int s = 0; s < n; s++){
		printf(" %d", predecessor[s]);
	}
	printf("\nD:");
	for (int t = 0; t < n; t++){
		printf(" %d", distance[t]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}

int readGraphWeighted(int n, int m, int graph[]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			graph[i*n+j] = 0;		
		}
	}
	
	int vertex;
	int edge;
	int weight;
	int iNRead;
	for(int i = 0; i < m; i++) {
		iNRead = scanf("%d%d%d", &vertex, &edge, &weight);
		if(iNRead != 3) {
			printf("Error reading values!");
			return EXIT_FAILURE;		
		}
		graph[vertex*n+edge] = weight;
	}

	return EXIT_SUCCESS;
}

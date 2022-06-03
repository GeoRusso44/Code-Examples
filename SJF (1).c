#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Building the node for queue here
typedef struct node {
    char* name;
	int temp; 
	char process;
	int arrival;
	int duration;
    struct node* next;
	int order;
} node_t;	

	// just for testing
void Print(node_t *head){
	node_t *current = head;
	while(current != NULL){
		 printf("%s ",current->name);
		 printf("%c ",current->process);
		 printf("%d ",current->arrival);
		 printf("%d ",current->duration);
		 printf("%d ",current->temp);
		 current = current->next;
		 printf("\n");
	}
}
//scans the linked list for the lowest duration compared to the current time
node_t* Lowest(node_t *head, int time){
	node_t *current = head;
	node_t *smallestNode = NULL;
	while(current != NULL){
		if(time >= current->arrival && current->duration > 0){
			if(smallestNode == NULL||smallestNode->duration > current->duration){
				smallestNode = current;
			}
		}
		current = current->next;
	}
	return smallestNode;
}
//adds nodes to the linked list
void Insert(node_t **head, char *name, char process,int arrival, int duration, int order){
	node_t *new_node = malloc(sizeof(node_t));
	new_node->name = malloc(strlen(name)*sizeof(char));	
	new_node-> name = strcpy(new_node->name,name);
	new_node-> process = process;
	new_node-> order = order;
	new_node-> arrival = arrival;
	new_node-> duration = duration;
	node_t *current;
	
	if(*head == NULL){
		*head = new_node;
		return;
	}
	current = *head;
	while(current->next !=NULL){
		current = current->next;
	}
	current->next = new_node;
	return;
}
//sets the time when a user finsihes their process 
void SetExit(node_t *smallest, int time){
	int time2 = time + 1;
	
	smallest -> temp = time2 ;
	
}
//This prints the summary at the bottom of the output
void PrintSummary(node_t *head){
	node_t *current = head;
	while(current != NULL){
		printf("%s\t ",current->name);
		printf("%d ",current->temp);
		current = current->next;
		printf("\n");
	}
}
//this removes and duplicate processes from the linked list if they have two processes, it leaves the one with the highest exit time
void Purge(node_t *head){


}

int main(){
	node_t *list = NULL;
	node_t *smallest = NULL;
	int time = 0;
	char header[50];
	char header2[50];
	char header3[50];
	char header4[50];
	char name[50];
	char process;
	int arrival;
	int duration;
	int size = 0;
	int order = 0;
	scanf("%s %s %s %s", header, header2, header3, header4);

	while(scanf("%s %c %d %d",name, &process, &arrival, &duration) != EOF){
		size++;	
		order++;
		Insert (&list, name, process, arrival, duration, order); 
			
	}
	int x = 20;
	printf("Time \t Job \n");
	while( size != 0){
		
		smallest = Lowest(list, time);
		
		if(smallest == NULL){

		}else{
		printf("%d \t", time);
		printf("%c \n" , smallest->process);
		smallest->duration--;
		if(smallest->duration == 0){
		SetExit(smallest, time);
		size--;
		}
		}
		time++;	
	}
	printf("%d \t", time);
	printf("IDLE \nSummary \n");
	PrintSummary(list);
}

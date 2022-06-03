

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
} node_t;	

	void Print(node_t *head){
		printf("*****************************************************************************\n");
		node_t *current = head;
			while(current != NULL){
				
			 printf("%s ",current->name);
			 printf("%c ",current->process);
			 printf("%d ",current->arrival);
			 printf("%d ",current->duration);
			 current = current->next;
			 printf("\n");
		}
		printf("*****************************************************************************\n");
	}

	void Insert(node_t **head, char *name, char process,int arrival, int duration ){
		int added = 0;
		node_t *new_node;
		node_t *temp;
		node_t *previous = NULL;
		node_t *current = *head;
		new_node = malloc(sizeof(node_t));
		new_node->name = malloc(strlen(name)*sizeof(char));
		
		new_node-> name = strcpy(new_node->name,name);
		new_node-> process = process;
		new_node-> arrival = arrival;
		new_node-> duration = duration;	
		
		 if(*head == NULL){
			 *head = new_node;
		 }else if((*head)->next == NULL){
					if(current->duration > new_node->duration){
						temp = current;
						*head = new_node;
						new_node->next = temp;
					}else{
						current->next = new_node;
			 }
		 }else{
			while (current->next != NULL){
				if(new_node->duration <= current->duration){
					temp = current;
					if(previous !=NULL){
					previous->next = new_node;
					}else{
						*head = new_node;
					}
					new_node->next = temp;
					added = 10;
					break;
				}
			previous = current;
			current = current->next;
			}
			if(!added){
			current->next = new_node;
			}
			//current->next = new_node;
		
	    }
		
		}
	
	node_t* ReadNode(node_t **head){
		node_t *useNode = NULL;
		
		useNode = *head;
		*head = (*head)->next;
		
		return useNode;
	}
	node_t *temp;
	node_t *newList = NULL;
	
	void Sort(node_t *head, int size){
		int sizeDup = 0;
		while(size !=0){
			temp = ReadNode(&head);
			Insert(&newList,temp->name,temp->process,temp->arrival,temp->duration);
			size --;
			sizeDup++;
		}while(sizeDup !=0){
			temp = ReadNode(&newList);
			Insert(&head,temp->name,temp->process,temp->arrival,temp->duration);
			sizeDup--;
		}
	}
	void Arrival(node_t **head, char *name, char process,int arrival, int duration ){
		int added = 0;
		node_t *new_node;
		node_t *temp;
		node_t *previous = NULL;
		node_t *current = *head;
		new_node = malloc(sizeof(node_t));
		new_node->name = malloc(strlen(name)*sizeof(char));
		
		new_node-> name = strcpy(new_node->name,name);
		new_node-> process = process;
		new_node-> arrival = arrival;
		new_node-> duration = duration;	
		
		 if(*head == NULL){
			 *head = new_node;
		 }else if((*head)->next == NULL){
					if(current->arrival > new_node->arrival){
						temp = current;
						*head = new_node;
						new_node->next = temp;
					}else{
						current->next = new_node;
			 }
		 }else{
			while (current->next != NULL){
				if(new_node->arrival <= current->arrival){
					temp = current;
					if(previous !=NULL){
					previous->next = new_node;
					}else{
						*head = new_node;
					}
					new_node->next = temp;
					added = 10;
					break;
				}
			previous = current;
			current = current->next;
			}
			if(!added){
			current->next = new_node;
			}
			//current->next = new_node;
		
	    }
		
		}
int main(){
// This is my data
		node_t *list = NULL;
		node_t *listTemp = NULL;
		node_t *read;
		node_t *tempRead = NULL;
		node_t *summary = NULL;
		
		int boolean = 0;
		int boocount = 0;
		
		char* name;
		char process;
		
		int arrival;
		int duration;
		int size = 0;
		
		char header[50];
		char header2[50];
		char header3[50];
		char header4[50];
		
		
	scanf("%s %s %s %s", header, header2, header3, header4);
	
	
	while(scanf ("%s %c %d %d",name, &process, &arrival, &duration) != EOF){
		//printf("%s %c %d %d \n", name, process, arrival, duration);
	size++;	
	Insert (&list, name, process, arrival, duration);  
	
}
//This is the printing of the nodes and data


int counter = 2;
int sizeOther = size;
int tempSize = size;

printf( "This would resault in: \n");
printf( "\t Time \t Job \n");
while(list != NULL){
		
	while(boolean == 0){
		read = ReadNode(&list);
			if(counter < read->arrival){
				boocount++;
				Insert(&listTemp,read->name,read->process,read->arrival,read->duration);
			}else{
				boolean = 1;
			}
	}
	boolean = 0;
	
	printf("\t %d \t %c \n", counter, read->process);
	
				while(boocount > 0){
							tempRead = ReadNode(&listTemp);
							Insert(&list,tempRead->name,tempRead->process,tempRead->arrival,tempRead->duration);		
							boocount--;
							break;
					}
		read->duration--;
		if(read->duration != 0){
			
		Insert(&list,read->name,read->process,read->arrival,read->duration);
		
		}else{
		read->arrival = counter + 1;
		Insert(&summary,read->name,read->process,read->arrival,read->duration);
		size--;
		}
	
	counter++;
	//Sort(list, size);
	tempSize = size;
		int sizeDup = 0;
		while(size !=0){
			read = ReadNode(&list);
			Insert(&listTemp,read->name,read->process,read->arrival,read->duration);
			size --;
			sizeDup++;
		}while(sizeDup !=0){
			read = ReadNode(&listTemp);
			Insert(&list,read->name,read->process,read->arrival,read->duration);
			sizeDup--;
		}
		size = tempSize;
	if(list == NULL){
	printf("\t %d \t IDLE \n", counter );
	}
		
}
printf( "Summary \n");
while(summary != NULL){
read = ReadNode(&summary);
printf("\t %s \t %d \n", read->name, read-> arrival);
}

  return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
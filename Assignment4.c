
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h> 
#include <string.h>

//Building the node for queue here
	typedef struct node {
		
		int name;
		int duration;

		struct node* next;
	} node_t;	

	void Print(node_t *head){
		printf("*****************************************************************************\n");
		node_t *current = head;
			while(current != NULL){
				
			 printf("%d ",current->name);
			 printf("%d ",current->duration);
			 current = current->next;
			 printf("\n");
		}
		printf("*****************************************************************************\n");
	}

	void Insert(node_t **head, int name, int duration ){
		int added = 0;
		node_t *new_node;
		node_t *temp;
		node_t *previous = NULL;
		node_t *current = *head;
		new_node = malloc(sizeof(node_t));
		new_node->name = malloc(strlen(name)*sizeof(char));
		
		new_node-> name = name;
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
			Insert(&newList,temp->name,temp->duration);
			size --;
			sizeDup++;
		}while(sizeDup !=0){
			temp = ReadNode(&newList);
			Insert(&head,temp->name,temp->duration);
			sizeDup--;
		}
	}
	
	void Arrival(node_t **head, int name, int duration ){
		int added = 0;
		node_t *new_node;
		node_t *temp;
		node_t *previous = NULL;
		node_t *current = *head;
		new_node = malloc(sizeof(node_t));
		new_node->name = malloc(strlen(name)*sizeof(char));
		
		new_node-> name = name;
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
		
	void Help(){
		while(ture){
			//helps the 4 people 
	}	
		
int main( int chairs, int taTime, int sdtTime ){

	//data
	int room = 0;
	int sdtNumber = 1;
	int frequency = 0;
	//rand() use to set sdtTime to a random number between 0 and 12

	//Creating threads
	pthread_t theTA1;
	pthread_t theTA2;
	pthread_t theTA3;	
	pthread_t theTA4;
	
	pthread_create(&theTA1, NULL, &Help, NULL);	
	pthread_create(&theTA2, NULL, &Help, NULL);	
	pthread_create(&theTA3, NULL, &Help, NULL);	
	pthread_create(&theTA4, NULL, &Help, NULL);	

	//while the TA still has time then take students from the list and help them
	frequency = rand() % sdtTime;
	
	while(taTime != 0){
		frequency = rand() % sdtTime;
		while(frequency != 0){
			taTime--;
		}
		if(chairs >= room){
			//Enter the lounge
			timeHelp = rand() 3 % 30;
			
			printf("Student %d is waiting for a TA\n",sdtNumber);
			
			Insert(&list, sdtNumber, timeHelp);
			sdtNumber++;
			room++;
		}else {
			//kick them out
			
			printf("Student %d is not taking a chance in the lab with their assignment. \n",sdtNumber);
			sdtNumber++
		}
		if(){
		//checks if any of the TAs are awake
			
		}
		taTime--;
	}
	

	pthread_join(theTA1, NULL);
	pthread_join(theTA2, NULL);
	pthread_join(theTA3, NULL);	
	pthread_join(theTA4, NULL);	
		
	return 0;

}	
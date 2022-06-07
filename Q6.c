//bubble sort
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

int array[] = {1,56,12,3,17,15,90,24,24,52};
int loop = 0;
int i = 0;
int j = 0;
int temp = 0;
printf("The array before is: ");
for(loop; loop <10; loop++){
	
	printf("%d ,", array[loop]);
}

for(i; i <9; i++){
	
	for(j; j< 9; j++){
	
		if(array[j] > array[j+1]){
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			}
	}

	}
	loop = 0;
	printf("The array is now: ");
	for(loop; loop <10; loop++){
		
		printf("%d ,", array[loop]);
	}	
}
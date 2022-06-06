#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
int array[] = {1,2,3,4,5,6,7,8,10};

int i = 0;
int sum = 0;

for(i;i <= 8; i++){

	
	sum = array[i] + sum;
	//printf("%d\n", sum);
}

int totalSum = ((10 * (10+1))/2);
int newSum = totalSum -sum;
printf("%d\n", sum);
printf("%d\n", totalSum);
printf("%d \n", newSum);
 
}
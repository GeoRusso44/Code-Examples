//Q #1) How can you reverse a string?
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

char string[50];
char newString[50];

scanf("%s", string);
	int j = 0;
	int i =0;

	while(string[i] != NULL){

	}
	i = i -1;
	while(string[j] != NULL){
	newString[i] = string[j];
	i=i-1;
	j=j+1;

	}
	printf("%s \n", string);
	printf("%s \n", newString);
}


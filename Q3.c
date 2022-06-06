//Q  How to compute the first character of a string that is not repeated?
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
char string[50];

scanf("%s", string);
char currentChar = string[0];
int i = 0;
while(string[i] != NULL){
	if(string[i] != currentChar){
	printf("%c", string[i]);
	break;
	}
 i++;
}
}
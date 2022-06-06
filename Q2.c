//Q #1) How to calculate the number of vowels and consonants in a string?
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
 // Adds string into program
 char string[50];
 scanf("%s",string);
 int i = 0;
 int vowel = 0;
 int consonant = 0;
 while(string[i] != NULL){
	if(string[i] == 'a'|| string[i] == 'e' || string[i] =='i' || string[i] =='o' 
		||string[i] == 'u' ||string[i] == 'A' ||string[i] == 'E' ||string[i] == 'I' ||string[i] == 'O' ||string[i] == 'U' ){
		vowel = vowel + 1;
	}else{
		consonant = consonant + 1;
	}
	i = i + 1;
 }
	 printf("%d \n",vowel);
	 printf("%d \n",consonant);
	 i++;
 }
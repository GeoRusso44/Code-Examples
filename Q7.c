//FizzBuzz
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

int num;
scanf("%d", &num);
int i = 0;
for(i; i <= num; i++){
	if(i % 3 == 0 && i % 5 == 0){
		printf("%d FizzBuzz \n", i);
	}else if(i % 3 == 0){
		printf("%d Fizz \n", i);
	}else if(i % 5 == 0){
		printf("%d Buzz \n", i);
	}else{
		printf("%d \n", i);
	}
}

}
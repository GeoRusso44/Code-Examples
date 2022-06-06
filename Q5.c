//Determine the factors of a number.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
int num;

scanf("%d", &num);

int i = 1;

for(i; i <= num; i++){
	//printf("%d\n",i);
	if( num % i == 0){
		printf("%d\n", i);
	}
}

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main(){
	 
	int i, n;
	int k =0;
	time_t t;
	n = 100000000;
 
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	
	/* Print 5 random numbers from 0 to 49 */
	for( i = 0 ; i < n ; i++ ) {
	k = rand() % 50 * rand() % 50;
	}
	return(0);	 

 }
 
 
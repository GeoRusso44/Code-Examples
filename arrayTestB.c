#include <stdio.h>
#include <stdlib.h>

void aveSum(double * a, int n, double*avg, double * sum);

int main(){
		//varibles
		int size = 0;
		double sum;
		double total;
		sum = 0.0;
		double *sumLoc = &sum;
		double *totalLoc = &total;
		
		 
//scans for user input
printf("Enter the size of the array \n");
scanf("%d" , &size);

double * arrayValue = (malloc(size * sizeof(double)));
printf("Enter the values of the array \n");
		for(int i = 0; i < size;i++){
			scanf("%lf" , &(*(arrayValue + i)));
		}

aveSum(arrayValue, size, totalLoc, sumLoc);

printf("The average sum is %lf", total);
free(arrayValue);
}

void aveSum(double *a, int n, double*avg, double * sum){
	for(int i = 0; i <n; i++){
		(*sum) = (*sum) + *(a + i);
	}
	(*avg) = (*sum) / n;
}

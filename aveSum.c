#include <stdio.h>
#include <stdlib.h>
void aveSum(double a[], int n, double*avg, double *sum);

int main(){

		//varibles
		int size;
		double *sumTotal ;
		double *avgTotal ;
		*sumTotal = 0.0;
		*avgTotal = 0.0;
//scans for user input
printf("Enter the size of the array \n");
scanf("%d" , &size);

double arrayValue[size];

		for(int i = 0; i < size;i++){
			scanf("%lf" , &arrayValue[i]);
		}

void aveSum(double arrayValue[],int size,double *avgTotal,double *sumTotal);

printf("The average sum is %lf", &avgTotal);
}

void aveSum(double a[], int n, double*avg, double *sum){
	*sum = 0.0;
		printf("2\n");
	for(int i = 0; i <n; i++){
		(*sum) = (*sum) + a[i];
	}
	(*avg) = (*sum) / n;
}

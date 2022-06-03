#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime);



 int main(){
		 int desiredTime;
		 int test = 0;
		 int test2 = 0;
		 int *departureTime = &test;
		 int *arrivalTime = &test2;
		
		 int hour;
		 int min;
	printf("Enter a 24-hour time: " );
	 scanf("%d:%d", &hour , &min);
	 printf("\n");
	 desiredTime = (hour * 60) + min;
	
	findClosestFlight(desiredTime, departureTime, arrivalTime);
	 int hour2;
	 int min2;
	
	hour = *departureTime / 60;
	min = *departureTime - (hour * 60);
	
	hour2 = *arrivalTime / 60;
	min2 = *arrivalTime - (hour2 * 60);

	printf("Closest departure time is %d:%d , arriving at %d:%d\n", hour, min, hour2, min2);
	 
 }
 
 
 void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
	int hour;
	int min;
	int arrivalTimeTemp;
	int departureTimeTemp;
	int departureTimeTempTemp;
	int counter = 0;
FILE *f = fopen("flights.dat","r");	 
	
    if (f == NULL)
    {
        // checks if NULL
        return;         
    }

	int true = 1;
	
	fscanf(f,"%d:%d", &hour, &min);
	departureTimeTemp = (hour * 60) + min;
	
	fscanf(f,"%d:%d", &hour, &min);
	arrivalTimeTemp = (hour * 60) + min;
	
	counter = abs(desiredTime - departureTimeTemp);
	int counterTemp = 0;

	while (true == 1){
	
	
		fscanf(f,"%d:%d", &hour, &min);
		departureTimeTempTemp = (hour * 60) + min;
		counterTemp = abs(desiredTime - departureTimeTempTemp);
		
		if(counter < counterTemp){
		
		true = 0;
		}else{
		counter = counterTemp;
		departureTimeTemp = departureTimeTempTemp;
		
		fscanf(f,"%d:%d", &hour, &min);
		arrivalTimeTemp = (hour * 60) + min;
		
		
		}	
		
	}
	
	*departureTime = departureTimeTemp;
	*arrivalTime = arrivalTimeTemp;
	

	fclose(f);

	
 }

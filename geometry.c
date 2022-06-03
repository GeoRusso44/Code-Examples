#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "geometry.h"

// Initializes the First Node of the ShapeT type with Malloc, If its not able to malloc then it frees it and returns NULL
ShapeT *initialize(int capacity){
	PointT *tempP1;
	if((tempP1 = (PointT*)malloc(capacity*(sizeof(PointT)))) == NULL){
		
		free(tempP1);
		return NULL;
	}
	ShapeT *tempP2;
	if((tempP2 = (ShapeT*)malloc(sizeof(ShapeT))) == NULL){
		free(tempP2);
		return NULL;
	}
	tempP2 -> capacity = capacity;
	tempP2 -> size = 0;
	tempP2 -> points = tempP1;
	return tempP2;
}
	
int addPoint(PointT point, ShapeT *shape){
	if(shape -> size == shape -> capacity){
		return 0;//This checks to see if the array is full or not
	}
	
	shape -> points[shape -> size] = point;
	shape -> size++;
	return 1;
}
	
PointT getPoint(int num, ShapeT *shape){
	
	for(int i = 0; i<shape -> size; i++){
		if(shape -> points[i].num == num){
			return shape -> points[i];
		}
	}
	PointT *point = malloc(sizeof(PointT));
	
	/*if(point == NULL){
		printf("Could not allocte memory");
		EXIT_FAILURE;
	}
	*/
	
	point -> num = -1;
	point -> x = 0;
	point -> y = 0;
	return *point;
}

int compare(const void *arg1, const void *arg2){
	const PointT *pt1 = (const PointT *)arg1;
	const PointT *pt2 = (const PointT *)arg2;
	
	const int value1 = pt1 -> x;
	const int value2 = pt2 -> x;
	
	if(value1 < value2){
		return -1;
	}
	if(value1 == value2){
		const int valueExtra1 = pt1 -> y;
		const int valueExtra2 = pt2 -> y;
		if(valueExtra1 < valueExtra2){
			return -1;
		}
		if(valueExtra1 == valueExtra2){
			return 0;
		}
		return 1;
	}
	return 1;
}

void sortPoints(ShapeT *shape){
	qsort(&(shape -> points[0]), shape -> size, sizeof(PointT), compare);
	return;
}

void printPoints(ShapeT *shape){
	for(int i = 0; i < shape -> size; i++){
		printf("%d : (%d, %d)\n", shape -> points[i].num, shape -> points[i].x, shape -> points[i].y);
	}
	return;
}

int areaTriangle(int *vertices, ShapeT *shape){
	int pointsTotal = 0;
	int area;
	int calculate1;
	int calculate2;
	PointT *triangle = malloc(3 * (sizeof(PointT)));
	
	/*(if(triangle == NULL){
		printf("Could not allocte memory");
		EXIT_FAILURE;
	}
	*/
	for(int i =0; i< 3; i++){
		for(int j = 0; j < shape -> size; j++){
			if(vertices[i] == shape -> points[j].num){
				triangle[pointsTotal] = shape -> points[j];
				pointsTotal++;
				break;
			}
		}
	}
	if(pointsTotal < 3){
		free(triangle);
		return -1;
	}
	calculate1 = ((triangle[2].x) -(triangle[0].x)) * ((triangle[1].y) - triangle[0].y);
	calculate2 = ((triangle[1].x) -(triangle[0].x)) * ((triangle[2].y) - triangle[0].y);
	area = ((calculate1 - calculate2)/2);
	
	if(area < 0){
		area = abs(area);
	}
	free(triangle);
	return area;
}
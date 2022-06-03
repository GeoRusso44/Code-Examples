#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"


int main(int argc, char ** argv) {
	char *fData = argv[1];
	FILE *file = fopen(fData, "r");
	
	if(file == NULL){
		return 1;
	}
	
	int capacityMain;
	
	if(fscanf(file, "%d", &capacityMain) != 1){
		return 1;
	}
	
	ShapeT *shape = initialize(capacityMain);
	for(int i = 0; i< capacityMain; i++) {
		PointT point;
		if(fscanf(file, "%d %d %d", &point.num, &point.x, &point.y) != 3){
			return 1;
		}
		
		if(addPoint(point, shape) == 0){
			printf("Shape is at capacity and cannot take in more points");
		}
	}
	
	fclose(file);
	
	
	printPoints(shape);
	
	sortPoints(shape);
	
	printf("sorted points:\n");
	
	printPoints(shape);
	
	printf("enter number of each of three points (-1 to quit): ");
	
	int *vertices = malloc(3*(sizeof(int)));
	/*if(vertices == NULL){
		printf("Could not allocte memory");
		EXIT_FAILURE;
	}
	*/
	int true = 1;
	while(true == 1){
		if(scanf("%d %d %d", &vertices[0], &vertices[1], &vertices[2]) != 3) {
			return 1;
		}
		else if(vertices[0] < 0 || vertices[0] > capacityMain || vertices[1] < 0 || vertices[1] > capacityMain || vertices[2] < 0 || vertices[2] > capacityMain) {
			printf("not all points valid\n");
		}
		else {
			PointT p1 = getPoint(vertices[0], shape);
			PointT p2 = getPoint(vertices[1], shape);
			PointT p3 = getPoint(vertices[2], shape);
			int area = areaTriangle(vertices, shape);
			if(area == -1){
				printf("One or more points not found\n");
			}
			printf("area of triangle (%d,%d)-(%d,%d)-(%d,%d) is %d\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);
		}
	}
	free(vertices);
	true = 0;
}
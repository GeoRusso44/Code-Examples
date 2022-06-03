#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"

ShapeT *initialize(int capacity);

int addPoint(PointT point, ShapeT *shape);

PointT getPoint(int num, ShapeT *shape);

void sortPoints(ShapeT *shape);

void printPoints(ShapeT *shape);

int areaTriangle(int *vertices, ShapeT *shape);
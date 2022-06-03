#ifndef GEOMETRY_H
#define GEOMETRY_H
typedef struct{
	int num; //point number
	int x, y; //x,y coordinate of point
} PointT;

typedef struct{
	int size;
	int capacity;
	PointT *points;
} ShapeT;

/*
 * allocates memory for an array of `capacity` points, 
 * and for a `ShapeT` 'object' (array of length one) 
 * that stores a pointer to the array and keeps track 
 * of the current size (set to zero by this function) 
 * and the capacity. Returns NULL is memory allocation
 * fails
 */
ShapeT *initialize(int capacity);
/*
 * adds a point to the array referred to by `shape`. 
 * This function returns 1 if it successfully adds a point, 
 * or returns 0 if it can't add a point because the array is full.
 */
int addPoint(PointT point, ShapeT *shape);
/*
 * returns a point with label `num` from the array referred to 
 * by `shape`. Note that we are assuming that all points have 
 * distinct labels. If the point with label `num` isn't in the 
 * array, then `getPoint` returns a point with label 
 * `num = -1` and `x=0, y=0`.
 */
PointT getPoint(int num, ShapeT *shape);
/*
 * sorts points in lexicographical order (sorting first by 
 * x coordinate, then by y coordinate), using the `qsort` 
 * function from C's standard library.
 */
void sortPoints(ShapeT *shape);
/*
 * prints each point to a line, with the format `num: (x,y)` 
 * (e.g. `2: (3,6)`)
 */
void printPoints(ShapeT *shape);
/* 
 * searches for three points in the array referred to by 
 * `shape`, and computes the area of the triangle formed by 
 * the three points. The labels of the points are in the 
 * `vertices` array. The `areaTriangle` function searches 
 * for the points matching each label and returns the area 
 * of the triangle, or returns -1 if one or more of the 
 * points can't be found.
 */
int areaTriangle(int *vertices, ShapeT *shape);
#endif
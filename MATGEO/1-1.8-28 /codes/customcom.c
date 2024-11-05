

#include <math.h>
#include <stdlib.h>
// Define a structure for 3D points
typedef struct {
    double x;
    double y;
    double z;
} Point3D;

// Define a structure for the result
typedef struct {
    double a;
    double b;
    double c;
    double d;
} Results;

// Function to compute four outputs: distance, midpoint, vector, and squared distance
void calc_perpbis_plane(Point3D* p1, Point3D* p2, Results* result) {
    
    result->a = p1->x - p2->x;
    result->b = p1->y - p2->y;
    result->c = p1->z - p2->z;
    result->d = -(pow(p1->x,2)+pow(p1->y,2) +pow(p1->z,2) - pow(p2->x,2)-pow(p2->y,2)-pow(p2->z,2))/2; 
}


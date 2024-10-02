#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libs/matfun.h"
int main(void) {
    FILE *f = fopen("output.dat", "w");
    double **l1,**l2;
    l2 = createMat(3,1);
    l1 = createMat(3,1); 
    l2[0][0] = 1;l2[0][1] = 2;l2[0][2] = 3;
    l1[0][0] = 5;l1[0][1] =10;l1[0][2] = 4;
    FILE *file;
    file = fopen("values.dat", "w");

    if (file == NULL) {
      	printf("Error opening file!\n");
      	return 1;
    }
    fprintf(file, "a b c\n");
    fprintf(file, "%.02lf %.02lf %.02lf\n", l1[0][0],l1[0][1],l1[0][2]);
    fprintf(file, "%.02lf %.02lf %.02lf\n", l2[0][0],l2[0][1],l2[0][2]);
    fclose(file);
    printf("Results have been written to values.dat\n");
    return 0;
    

    return 0;
}

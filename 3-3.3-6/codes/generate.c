#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libs/matfun.h"
float **calcpoints(double **A, double **B, double **AB){
	AB[0][0]= A[0][0]; AB[1][0]= A[1][0];
	AB[0][51]= B[0][0]; AB[1][51]= B[1][0];
        for(int i = 1; i<=50; i+=1){
          float j = (float) i/50;
          AB[0][i]= AB[0][0] + j*(AB[0][51]- AB[0][0]);
          AB[1][i]= AB[1][0] + j*(AB[1][51]- AB[1][0]);
        }
}
int main(void) {
    FILE *f = fopen("output.dat", "w");

    // Given values
    double a = 6;
    double B = 45 * M_PI / 180;
    double C = 30 * M_PI / 180;

    double ratio = sin(B) / sin(C); // b / c
    double c = a / (cos(B) + ratio * cos(C));

    // Vertex A
    double **vA = createMat(2, 1);
    vA[0][0] = c * sin(B);
    vA[1][0] = c * cos(B);
   
    // Vertex B
    double **vB = createMat(2, 1);
    vB[0][0] = 0;
    vB[1][0] = 0;

    // Vertex C
    double **vC = createMat(2, 1);
    vC[0][0] = a;
    vC[1][0] = 0;
    double **AB,**BC,**CA;
    AB = createMat(3,52);
    BC = createMat(3,52);
    CA = createMat(3,52); 
    calcpoints(vA,vB,AB);
    calcpoints(vB,vC,BC);
    calcpoints(vC,vA,CA);
    FILE *file;
    file = fopen("values.dat", "w");

    if (file == NULL) {
      	printf("Error opening file!\n");
      	return 1;
    }
    fprintf(file, "xab yab xbc ybc xca yca\n");
    for(int i=0; i<=51; i+=1){
      fprintf(file, "%.02lf %.02lf %.02lf %.02lf %.02lf %.02lf\n", AB[0][i],AB[1][i], BC[0][i],BC[1][i],CA[0][i],CA[1][i]);
      }

    fclose(file);
    printf("Results have been written to values.dat\n");
    return 0;
}

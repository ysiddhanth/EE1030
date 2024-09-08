#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "libs/matfun.h"
#include "libs/geofun.h"
float **calcpoints(double **A, double **B, double **AB){
	AB[0][0]= A[0][0]; AB[1][0]= A[1][0];
	AB[0][31]= B[0][0]; AB[1][31]= B[1][0];
        for(int i = 1; i<=30; i+=1){
          float j = (float) i/30;
          AB[0][i]= AB[0][0] + j*(AB[0][31]- AB[0][0]);
          AB[1][i]= AB[1][0] + j*(AB[1][31]- AB[1][0]);
        }
}
int main() {
	double **A,**B, **AB;
	A = createMat(2,1);
	B = createMat(2,1);
	AB = createMat(2,32);
	A[0][0] = -6;
	A[1][0] = 7;
	B[0][0] = -1;
	B[1][0] = -5;
	calcpoints(A,B,AB);
	FILE *file;
	file = fopen("values.dat", "w");

	if (file == NULL) {
		printf("Error opening file!\n");
		return 1;
	}
	fprintf(file, "x y\n");
        for(int i=0; i<=31; i+=1){
  	  fprintf(file, "%.02lf %.02lf\n", AB[0][i],AB[1][i]);
	}
	fclose(file);
	printf("Results have been written to values.dat\n");
	printf("Value of distance between A and B is %lf\n", Matnorm(Matsub(A,B,2,1), 2));
	freeMat(A,2);
	freeMat(B,2);
	freeMat(AB,2);
	return 0;
}

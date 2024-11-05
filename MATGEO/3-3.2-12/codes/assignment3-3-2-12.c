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
	AB[0][51]= B[0][0]; AB[1][51]= B[1][0];
        for(int i = 1; i<=50; i+=1){
          float j = (float) i/50;
          AB[0][i]= AB[0][0] + j*(AB[0][51]- AB[0][0]);
          AB[1][i]= AB[1][0] + j*(AB[1][51]- AB[1][0]);
        }
}

int main() {
        double **A,**B,**C,**AB,**CA,**BC;
	A = createMat(3,1);
	B = createMat(3,1);
	C = createMat(3,1);
	AB = createMat(3,52);
	BC = createMat(3,52);
	CA = createMat(3,52);
	A[1][0] = 3*sqrt(3);
	A[0][0] = 3;
	A[2][0] = 0;
	B[0][0] = 0;
	B[1][0] = 0;	
	B[2][0] = 0;
	C[0][0] = 6;	
	C[1][0] = 0;	
	C[2][0] = 0;
	calcpoints(A,B,AB);
        calcpoints(B,C,BC);
	calcpoints(C,A,CA);
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

	freeMat(AB,3);
	return 0;
}






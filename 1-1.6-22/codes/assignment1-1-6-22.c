#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "libs/matfun.h"
#include "libs/geofun.h"

int main() {
	double **A,**B,**C;
	A = createMat(3,1);
	B = createMat(3,1);
	C = createMat(3,1);
	A[0][0] = 2;
	A[1][0] = -3;
	A[2][0] = 4;
	B[0][0] = -1;
	B[1][0] = 2;	
	B[2][0] = 1;
	C[0][0] = 0;	
	C[1][0] = (float) 1/3;	
	C[2][0] = 2;
	FILE *file;
	file = fopen("values.dat", "w");

	if (file == NULL) {
		printf("Error opening file!\n");
		return 1;
	}
	fprintf(file, "x y z\n");
	fprintf(file, "%.02lf %.02lf %.02lf\n", A[0][0],A[1][0],A[2][0]);
	fprintf(file, "%.02lf %.02lf %.02lf\n", B[0][0],B[1][0],B[2][0]);
	fprintf(file, "%.02lf %.02lf %.02lf\n", C[0][0],C[1][0],C[2][0]);

	fclose(file);
	printf("Results have been written to values.dat\n");

	freeMat(A,2);
	freeMat(B,2);
	freeMat(C,2);
	return 0;
}

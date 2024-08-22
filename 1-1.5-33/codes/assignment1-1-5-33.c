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
	double **k,**M,**C;
	int x1=5,x2=-1,y1=-6,y2=-4;
	M = createMat(2,2);
	k = createMat(2,1);
	C = createMat(2,1);
	M[0][1] = x1;
	M[1][1] = y1;
	M[0][0] = x2;
	M[1][0] = y2;
	k[0][0] = (float)5/6;
	k[1][0] = (float) 1/6;
	C = Matmul(M,k,2,2,1);
	FILE *file;
	file = fopen("values.dat", "w");

	if (file == NULL) {
		printf("Error opening file!\n");
		return 1;
	}
	fprintf(file, "x\ty\t of C\n");
	fprintf(file, "%.02lf\t", C[0][0]);
	fprintf(file, "%.02lf", C[1][0]);

	fclose(file);
	printf("Results have been written to values.dat\n");

	freeMat(M,2);
	freeMat(k,2);
	freeMat(C,2);
	return 0;
}

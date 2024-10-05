#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "libs/matfun.h"
#include "libs/geofun.h"
#include <math.h>
void calcpoints(double **A, double **B, double **AB){
	AB[0][0]= A[0][0]; AB[1][0]= A[1][0];
	AB[0][51]= B[0][0]; AB[1][51]= B[1][0];
        for(int i = 1; i<=50; i+=1){
          float j = (float) i/50;
          AB[0][i]= AB[0][0] + j*(AB[0][51]- AB[0][0]);
          AB[1][i]= AB[1][0] + j*(AB[1][51]- AB[1][0]);
        }
}
void circ_gen(double **circ, double **A, double radius, double k){
        int num_points = 51;
	for(int i=0;i<=num_points;i++){
		double theta = k*M_PI * (double)i / (double)num_points;
		circ[0][i]=A[0][0]+(radius*cos(theta));
		circ[1][i]=A[1][0]+(radius*sin(theta));
	}
}
int main() {
    double x1, y1,x2,y2;
    x1 = 0; y1 = 0; x2=1;y2=sqrt(3);
    int m = 2, n = 1;
    double **A= createMat(m,n);
    double **B=createMat(m,n);
    A[0][0] = x1;
    A[1][0] = y1;
    B[0][0]=x2;
    B[1][0]=y2;
    double radius = 2;
    double **AB = createMat(3,52);double **circ = createMat(3,52);double **circar = createMat(3,52);
    calcpoints(A,B,AB);circ_gen(circ,A,radius,1);circ_gen(circar,A,radius,(double)1/3);
    FILE *file = fopen("values.dat", "w");

    if (file == NULL) {
      	printf("Error opening file!\n");
      	return 1;
    }
    fprintf(file, "x y xc yc xcar ycar\n");
    for(int i=0; i<=51; i+=1){
      fprintf(file, "%.02lf %.02lf %.02lf %.02lf %.02lf %.02lf\n", AB[0][i],AB[1][i], circ[0][i],circ[1][i],circar[0][i],circar[1][i]);
      }

    fclose(file);
    printf("Results have been written to values.dat\n");
    return 0;
}

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
void pointofinter(double **k, double **V, double **u, double **h, double **m, double **f){
        double **g = Matadd(Matadd(Matmul(Matmul(transposeMat(h,2,1),V,1,2,2),h,1,2,1),Matscale(Matmul(transposeMat(u,2,1),h,1,2,1),1,1,2),1,1),f,1,1);
        double **Vhpu = Matadd(Matmul(V,h,2,2,1),u,2,1);
        double **mtvm = Matmul(Matmul(transposeMat(m,2,1),V,1,2,2),m,1,2,1); 
        double **mtVhpu = Matmul(transposeMat(m,2,1),Vhpu,1,2,1);
        double **mtVhpu2 = Matmul(Matmul(transposeMat(m,2,1),Vhpu,1,2,1),Matmul(transposeMat(m,2,1),Vhpu,1,2,1),1,1,1);
        double l = -(mtVhpu[0][0] / mtvm[0][0]);
        double r = (sqrt(mtVhpu2[0][0] - (g[0][0]*mtvm[0][0])) / mtvm[0][0]);
        k[0][0] = l+r; k[1][0] = l-r;
        
}
double areaintegral(double theta,double r){
  return theta*r*r/2;
}
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
    double x1, y1,x2,y2; x1 = 0; y1 = 0; double mx=1; double my=sqrt(3);
    double **V = createMat(2,2);V[0][0] = 1; V[1][0]= 0;V[0][1] = 0; V[1][1]= 1;
    double **h = createMat(2,1);h[0][0] = 0; h[1][0]= 0;
    double **u = createMat(2,1);u[0][0] = 0; u[1][0]= 0;
    double **m = createMat(2,1);m[0][0] = mx; m[1][0]= my;
    double **f = createMat(1,1); f[0][0] = -4;
    double **k = createMat(2,1);
    pointofinter(k,V,u,h,m,f);
    double **A= createMat(2,1);
    double **B=createMat(2,1);
    B =  Matscale(m,2,1,k[0][0]);
    double **B1=createMat(2,1);
    B1 =  Matscale(m,2,1,k[1][0]);
    A[0][0] = x1;
    A[1][0] = y1;
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
    printf("Points of intersections are: (%lf %lf), (%lf,%lf)\n", B[0][0],B[1][0],B1[0][0],B1[1][0]);
    printf("Area bound is %lf\n", areaintegral((double)M_PI/3,radius));
    return 0;
}



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "libs/matfun.h"
#include "libs/geofun.h"
double ndimdis(double **A,double **B, int n){
  return Matnorm(Matsub(A,B,n,1), n);
}



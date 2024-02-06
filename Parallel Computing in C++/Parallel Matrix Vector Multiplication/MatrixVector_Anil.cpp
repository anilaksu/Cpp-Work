#include <math.h>
#include <stdio.h>
#include <lapacke.h>
#include <cblas.h>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <fstream>

using namespace std;

void getVector(int *n, double r[])
{
    //double  r[n];
	int j;
	// the vector with n size
     for(j=0; j<*n; j++)
     {
        r[j]=(double)(1.*(j+1)); 
     }
}

void getMatrix(int *m, double **A)
{

	int i,j;
	// the matrix with n by n size
	for (i=0; i<*m; i++){
		 for(j=0; j<*m; j++)
		 {
			A[i][j]=(double)(1.*(j+1)+1.*(i+1)); 
		 }
	}
}


void copyMatrix_column(double A_node[], double **A, int *size, int *i_start, int *node_range )
{
	// this function copies the elements of p starting from i_start index to g 
	int i,j;

	
for (int j = 0; j < *node_range; j++){
	for(int i = 0; i < *size; i++)
		{
			A_node[i +*node_range *j] = A[i][j+*i_start];
		}
}     
	
}

void copyMatrix_row(double A_node[], double **A, int *size, int *i_start, int *node_range )
{
	// this function copies the elements of p starting from i_start index to g 
	int i,j;
	
for (int i = 0; i < *size; i++){
	for(int j = 0; j < *node_range; j++)
		{
			A_node[j +*node_range *i] = A[j+*i_start][i];
		}
}     
	
}

void copyVector(double g[], double p[], int *size, int *i_start )
{
	// this function copies the elements of p starting from i_start index to g 
	int i;

	for(int i = 0; i < *size; i++)
		{
				g[i] = p[i+*i_start];
		}     
}


int main(int argc, char *argv[])
{
/***********************************************************************
 *                                                                     *
 * This script is developed to perform vector vector multiplication   
 * using MPI and lapack and blas libraries are imported but only
 * blas library is used to perform inner product operation
 ***********************************************************************/
	  const int m=8000;
	  int  n=m;    // total length of vector
	  int p, i, j, ierr;
	  //int N, NRHS, LDA, LDB,incX,incY;
      double result, alpha, beta, pi;
	  double *r;
	  double *y;
	  double **A;

	  A = new double *[m];
	  for(i = 0; i <n; i++)
    	A[i] = new double[m];
	
      int node_range,node_limit_l,node_limit_u;
	 
      int nodeid, source, dest, tag;
     
      float node_result;

	  r = new double[n]; // the vector multiplied with the matrix
	  y = new double[n]; // the resultant vector obtained in the end of the matrix vector multiplication
	  alpha=1.;
	  beta=0.;

	  getVector(&n, r ); // let's get the vector
	  getMatrix(&n, A); // let's get the matrix;
 

	  node_range = n/p; // the length of vector distributed to each process
	  double *r_node = new double[node_range];
	  double *y_node = new double[n];
	  double *A_node = new double[m * node_range];

	
      node_limit_l = nodeid*node_range; // lower limit of the node
	  node_limit_u = (nodeid+1)*node_range-1; // upper limit of the node
	  copyVector(r_node, r, &node_range, &node_limit_l ); // the part of vector to be send to n'th process
	  copyMatrix_column(A_node, A, &n, &node_limit_l, &node_range); // the columm wise part of matrix to be send to n'th process 
	  //copyMatrix_row(A_node, A, &n, &node_limit_l, &node_range); // the row wise part of matrix to be send to n'th process 
	

	  // let's start the timer
	  std::clock_t start;
	  double duration,my_duration;
	  start = std::clock();
	
      // partitioned matrix vector multiplication
	  cblas_dgemv(CblasRowMajor, CblasNoTrans, n, node_range, 1.0, A_node, node_range, r_node, 1, 0., y_node, 1); // column wise partioning 
	  //cblas_dgemv(CblasRowMajor, CblasNoTrans, node_range, n, 1.0, A_node, n, r, 1, 0., y_node, 1); // row wise partioning 
	
	  // the  time elapsed during the matrix vector multiplication
	  my_duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	  cout << "Total number of process "<< p<< '\n'<< endl;
      printf("Process %d has the limit %d the partial result of %f\n",nodeid,node_limit_l,y_node[1]);

      // memory is released
      //delete [] A;
	  //delete [] A_node;
	  //delete [] r;
	

	}


#include <mpi.h>
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

void copy(double g[], double p[], int *size, int *i_start )
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
      int n, p, i, j, ierr;
      double h, result, a, b, pi;
	  double *r;
      int node_range,node_limit_l,node_limit_u;
	 
      int nodeid, source, dest, tag;
     
      float node_result;

      n=40000000;    // total length of vector
	  r = new double[n];
	  getVector(&n, r ); // let's get the vector
      dest = 0;         /* define the process that computes the final result */
      tag = 123;        /* set the tag to identify this particular job */

/* Starts MPI processes ... */
	  MPI_Status status;
      MPI_Init(&argc,&argv);              /* starts MPI */
      MPI_Comm_rank(MPI_COMM_WORLD, &nodeid);  /* get current process id */
      MPI_Comm_size(MPI_COMM_WORLD, &p);     /* get number of processes */

	//cout<< r[1] << endl;
	  //r =  getVector(n); // the total vector of length n
	  node_range = n/p; // the length of vector distributed to each process
	  double *r_node = new double[node_range];
	 
      node_limit_l = nodeid*node_range; // lower limit of the node
	  node_limit_u = (nodeid+1)*node_range-1; // lower limit of the node
	  copy(r_node, r, &node_range, &node_limit_l ); // the part of vector to be send to n'th process
	  // let's start the timer
	  std::clock_t start;
	  double duration,my_duration;
	  start = std::clock();
	 // inner product of each core
	  node_result =  cblas_ddot(node_range, r_node, 1, r_node, 1);
	  // the  time elapsed during the dot product operation
	  my_duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	  cout << "Total number of process "<< p<< '\n'<< endl;
      printf("Process %d has the limit %d the partial result of %f\n",nodeid,node_limit_l,node_result);


	if(nodeid == 0) {
		result = node_result;
		duration = my_duration;
		for (i=1;i<p;i++) {
			source = i;           /* MPI process number range is [0,p-1] */
			MPI_Recv(&node_result, 1, MPI_REAL, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&my_duration, 1, MPI_REAL, source, tag, MPI_COMM_WORLD, &status);
			result += node_result;
			duration += my_duration;
		}
		printf("The result =%f\n",result);
        cout<<"seconds elapsed during the operation is: "<< duration <<'\n'<< endl;
		std::ofstream outfile;
  		outfile.open("MPI_runtime.txt", std::ios_base::app);
  		outfile << p << ' '<< duration <<'\n'; 
	}
	else
	{	MPI_Send(&node_result, 1, MPI_REAL, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
	 	MPI_Send(&my_duration, 1, MPI_REAL, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
	}


	MPI_Finalize();                       /* let MPI finish up ... */
	}


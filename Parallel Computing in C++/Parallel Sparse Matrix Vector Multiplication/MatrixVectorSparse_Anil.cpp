#include <mpi.h>
#include <math.h>
#include <stdio.h>
#include <lapacke.h>
#include <cblas.h>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
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


void multSparseMatVector(int **B_node, double r[], double y_node[], double v_node[], int *list_size)
{
	// this function copies the elements of p starting from i_start index to g 
	int i;

	for(int i = 0; i < *list_size; i++)
		{
				y_node[B_node[i][0]] = y_node[B_node[i][0]]+r[B_node[i][1]]*v_node[i];
		}     
}


int main(int argc, char *argv[])
{
/***********************************************************************
 *                                                                     *
 * This script is developed to perform sparse matrix vector multiplication  
 * using MPI and lapack and blas libraries are imported but they are not used here
 *
 ***********************************************************************/
	  const int m=135888; // the number of nonzero elements in the sparse matrix 
	  const int l=20000; // the size of the sparse matrix 
	  int  n=l;    // total length of vector
	  int p, i, j, ierr;
	  int x;
      double result, alpha, beta, pi;
	  double *r;
	  double *v_node;
	  double *y;
	  double **A;
	  int **B_node;
	  int node_range,node_limit_l,node_limit_u;	 
      int nodeid, source, dest, tag;     

	  y = new double[l]; // the resultant vector obtained in the end of the matrix vector multiplication
	  // let's open the sparse matrix
	  ifstream inFile;
      inFile.open("SparseMatrix2.txt");
	
	
	/* Starts MPI processes ... */
	  MPI_Status status;
      MPI_Init(&argc,&argv);              /* starts MPI */
      MPI_Comm_rank(MPI_COMM_WORLD, &nodeid);  /* get current process id */
      MPI_Comm_size(MPI_COMM_WORLD, &p);     /* get number of processes */
	
	  dest = 0;         /* define the process that computes the final result */
      tag = 2351;        /* set the tag to identify this particular job */
	
      node_range = n/p; // the length of vector distributed to each process
	  node_limit_l = nodeid*node_range; // lower limit of the node
	  node_limit_u = (nodeid+1)*node_range-1; // upper limit of the node
	  // let's open an array to store the non-zero values of the sparse matrix
	  B_node = new int *[node_range]; // this double array stores the indices of the sparse matrix
	  v_node = new double[node_range]; // this array stores the values of the non-zero elements of the sparse matrices
	  for(i = 0; i <node_range; i++)
    	B_node[i] = new int[2];
	
		for (i = 0; i <n; i++){
			for (j = 0; j <3; j++){
				if(i>(node_limit_l-1) && i<(node_limit_u+1)){
					if(j==2){
						inFile>> v_node[i-node_limit_l]; 
					} else {
						inFile>> B_node[i-node_limit_l][j];
						//cout << "The matrix in list form "<< B_node[i-node_limit_l][j] << '\n'<< endl;
					}
					
				}
			}
		}  
	   
	  double *y_node = new double[n];
	
	  r = new double[n]; // the vector multiplied with the matrix
	  getVector(&n, r); // let's get the vector
	
	    // let's start the timer
	  std::clock_t start;
	  double duration,my_duration;
	  start = std::clock();
	  
	  // sparse matrix vector multiplication
	  multSparseMatVector(B_node, r,y_node,v_node, &node_range);  // the resultant subvector
      cout << "The result vector "<< y_node[1] << '\n'<< endl;
		
	  // the  time elapsed during the matrix vector multiplication
	  my_duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	  cout << "Total number of process "<< p<< '\n'<< endl;
      printf("Process %d has the limit %d the partial result of %f\n",nodeid,node_limit_l,y_node[70]);

	
	if(nodeid == 0) {

		for (int j = 0; j < l; j++){
	          y[j]=y_node[j];
		}    
		duration = my_duration;
		for (i=1;i<p;i++) {
			source = i;           /* MPI process number range is [0,p-1] */
			MPI_Recv(&n, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&node_range, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&node_limit_l, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(y_node, 1, MPI_REAL, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&my_duration, 1, MPI_REAL, source, tag, MPI_COMM_WORLD, &status);
			

			for (int j = 0 ; j < l ; j++){
	            y[j] =y[j]+y_node[j];
			}    
			duration += my_duration;
		}
		printf("The result =%f\n",l);
        cout<<"seconds elapsed during the operation is: "<< duration <<'\n'<< endl;
		std::ofstream outfile;
  		outfile.open("MPI_runtime.txt", std::ios_base::app);
  		outfile << p << ' '<< duration <<'\n'; 
	}
	else
	{	MPI_Send(&n, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
		MPI_Send(&node_range, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
		MPI_Send(&node_limit_l, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
	    MPI_Send(y_node, 1, MPI_REAL, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/
	 	MPI_Send(&my_duration, 1, MPI_REAL, dest, tag, MPI_COMM_WORLD);      /* send node_result to intended dest.*/

	
	}


	MPI_Finalize();                       /* let MPI finish up ... */
	}


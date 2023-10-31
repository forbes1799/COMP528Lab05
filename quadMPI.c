#include<stdio.h>
#include<mpi.h>

double func(double);
double independentRankWork(int commSize, int myRank);
void integrationPTP(int commSize, int myRank)

int main(void){
    const int REPEAT = 5;

    double tStart;
    double tEnd;
	
    int count = 0;
    for(count; count < REPEAT; count++){
		
		/*Set up MPI Environment here*/
	
    	tStart = MPI_Wtime();
    	
		integrationPTP(commSize, myRank);
		
		tEnd = MPI_Wtime();

		
		printf("COUNT = %d\n", count);
		printf("Time taken = %f milliseconds\n", 1000.0*(tEnd - tStart));	//print wallTimeTaken

		/*Finalise MPI Environment here*/

	}
}

void integrationPTP(int commSize, int myRank){
	/*
	Type your code here to find the size of the area 
	underneath the code using Point-To-Point communications
	Each process should call independentRankWork and send their result
	to process 0, which will add the results as they are received
	*/
}

double independentRankWork(int commSize, int myRank){
	/*Set up the number of quads*/
	const double a=0.0, b=200.0;
	const int  quads = 50000;
	double const width = (b-a) / (double) quads;
	
	int quadsPerRank = quads / commSize;

	if(myRank == commSize - 1){	//final rank leaving this here for ease
		quadsPerRank = quads - (quadsPerRank*myRank);
	}
	
	int startIter = myRank * quadsPerRank;
	int endIter = startIter + quadsPerRank - 1;
	
	double x, y;
    
	double sum;
	int i;

    for(i = startIter; i <= endIter; i++){
		x = a + i * width;
		y = x + width;
		sum += 0.5*width*(func(x) + func(y));
    }
	return sum;
}


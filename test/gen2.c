#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/* zwraca wartość n-tego wielomianu Hermite'a dla zadanego x */
double her( int n, double x) {
	
	if( n == 0 )
		return 1;
	else if( n == 1)
		return 2*x;
	else
		return 2*x * her( n-1, x ) - 2*(n-1) * her( n-2, x);
}

double fun( double x ) {
	
	double r= ((double)rand() - RAND_MAX/2.0)/RAND_MAX/5; /* +-10%  */
	
	return (1+r)*( 5*her(0, x) + 4* her(1, x) + 2* her(2, x) + 1*her(3, x) + 0.8*her(4, x) + 0.2*her(5, x) +
				   1.4*her(6, x) + 0.01*her(7, x) + 0.4*her(8, x) + 0*her(9, x) + 0.1*her(10, x) + 0.001*her(11, x) );
}

int main( int argc, char **argv ) {
	int n= argc > 1 ? atoi( argv[1] ) : 100;
	double a= argc > 2 ? atof( argv[2] ) : -2;
	double b= argc > 3 ? atof( argv[3] ) : 2;
	FILE *out= argc > 4 ? fopen( argv[4], "w" ) : stdout;

	srand( argc > 5 ? atoi(argv[5]) : time(NULL) );

	int i;
	double dx = (b-a)/(n-1);

	for( i=0; i < n; i++ ) {
		fprintf( out, "%g %g\n", a+i*dx, fun(a+i*dx) );
	}
	fclose( out );

	return 0;
}

#include <stdio.h>
#include <time.h>

int main( int argc, char * argv[] ) {

	clock_t begin = clock();

	int i;
	for( i=0; i<1000000000; i++ ) {

	}

	clock_t end = clock();
	double millis = (double)(end -  begin) / CLOCKS_PER_SEC;
	while (millis > 2)
		millis -= 2;
	millis /= 2;
	printf( "coeff time : %f\n", millis );  

	return 0;
}


#include <stdio.h>

int main( int argc, char **argv )
{
	char *name = "Kurt Schmidt" ;
	int age = 28 ;
	double f = 9283.278365 ;

	printf( "%-15s %4X %9.2f\n", name, age, f ) ;

	return( 0 ) ;
}

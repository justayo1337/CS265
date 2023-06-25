
#include <stdio.h>

int main( void )
{
	char *format = "Size of %-12s is %2d\n" ;

	printf( "\n" ) ;
	printf( format, "char", sizeof( char )) ;
	printf( format, "short", sizeof( short )) ;
	printf( format, "int", sizeof( int )) ;
	printf( format, "long", sizeof( long )) ;
	printf( format, "float", sizeof( float )) ;
	printf( format, "double", sizeof( double )) ;
	printf( format, "long double", sizeof( double )) ;

	printf( "\nDone\n\n" ) ;

	return 0 ;
}

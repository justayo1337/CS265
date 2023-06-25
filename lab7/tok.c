
#include <stdio.h>
#include <string.h>

char l[] = "ab cYdefXYg" ;

char *d1 = "YX" ;
char *d2 = " " ;

int main()
{
	size_t len = strlen( l ) ;
	unsigned short i = 0 ;

	char *p = strtok( l, d2 ) ;

	while( p != NULL )
	{
		printf( "The %dth field is: %s\n", i, p ) ;
		++i ;
		p = strtok( NULL, d1 ) ;
	}

	puts( "\n" ) ;

	for( i=0; i<len; ++i )
		printf( "%d: %c\n", i, l[i] ) ;
	
	return 0 ;
}

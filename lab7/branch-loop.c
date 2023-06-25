/***********************************************************************
 *
 * <init>
 * while( <cond> )
 *	<body>
 *  <inc. step>
 * 
 * for( <init> ; <cond> ; <incr. step> )
 *		<body>
 *
 ***************************************************/


#include <stdio.h>
#include <stdbool.h>

typedef enum { FALSE, TRUE } myBool ;

_Bool bSailing ;

int bools()
{
	if( true )
		puts( "Yes, all lower\n" ) ;
	
	return false ;
}

void if1( int n )
{
	if( n>12 ) {
		n -= 2 ;
		printf( "if1> if: n = %d\n", n ) ;
	}
}

void if2( int n )
{
	if( n>12 ) 
		n -= 2 ;
	else
	{
		n += 1 ;
		puts( "n is <= 12\n" ) ;
	}
}

bool bRaining, bOilies, bSunglasses, bOutside ;

void dress()
{
	if( bRaining ) 
	{
		if( bOutside )
			bOilies = true ;
	}
	else
		bSailing = true ;

}

long maxl( long a, long b )
{
	return a>b ? a : b ;
}

void mySwitch( int n )
{
	switch( n )
	{
		case 1 :
			puts( "You input 1\n" ) ;
			break ;
		case 2 :
		case 3 :
			puts( "n is odd" ) ;
			/* fall through */
		case 4 :
			puts( "You entered 2, 3, or 4\n" ) ;
			break ;
		case 13 :
			puts( "You entered 13\n" ) ;
			break ;
		default :
			puts( "I didn't recognise that number\n" ) ;
	}  // switch n
}

void W()
{
	int i ;
	char c ;

	while( (i=getchar()) != -1 )
	{
		c = (char) i ;
		printf( "You gave me a %c\n", c ) ;
	}
	puts( "\nDone.\n\n" ) ;
}

void W2( int start, int end, int step )
{
	int i = start ;
	while( i<=end )
	{
		printf( "%d\n", i ) ;
		i += step ;
	}

	puts( "W2-----------\n" ) ;

	do
	{
		printf( "%d\n", i ) ;
		i += step ;
	} while( i<=end ) ;

	puts( "W2-----------\n" ) ;

	for( int j=start; j<=end; j+=step )
		printf( "%d\n", j ) ;

	// printf( "After loop, j = %d\n", j ) ;  // j undeclared
}

struct sNode {
	int data ;
	struct sNode *next ;
}

int processOdds( struct sNode *L )
{
	int sum ;
	int cnt ;

	for( struct sNode *p=L; p!=NULL; p=p->next )
	{
		if( bEven( p->data ))
			continue ;
		// throwParty
		sum += p->data ;
		++cnt ;
	}
}

int main()
{
	// if1( 11 ) ;
	W2( 5, 12, 3 ) ;

	return 0 ;
}

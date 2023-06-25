/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person* a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a[], size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[CAP] = { NULL } ; /* rest are initialised to 0 */

	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] ) ;
			exit( 1 ) ;
		}
	}

	readPeople( team, fin ) ;

	freePeople( team, CAP ) ;

	return 0 ;
}

void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;
   int start = 0;
	int end = 2;
	int pos = 0;
	
   person *names = malloc(1024);
	while( getline( &buff, &len, f ) > 1 ) 
	{

		// We read a last name (with the newline)
		// - get memory for person
		// - append to array
		// - read next 2 lines, fill it in 
     buff [strlen(buff) - 1] = '\0';  
	 
      if ( cnt == start ){
	  strcpy(names->last,buff); 
		++cnt ;
	}else if (cnt == start + 1) {
	strcpy(names->first,buff); 
	++cnt ; 
} else if (cnt == end){
	names->age= atoi(buff); 
    *(a+pos)= names; 
//	 printf("%s , %s, %d\n",(*(*(a+pos))).first,(*(*(a+pos))).last,(*(*(a+pos))).age);
	 
		start = cnt +1;
		end = start + 2;
      ++cnt;
		++pos;
 names = malloc(1024);     
}

	}
free(names);
	free( buff ) ;
}

void freePeople( person* a[], size_t n ) 
{

// Do NOT assume array is dense.  Check every element
     
for( int i = 0 ; i < n ; ++i){
   if ( (*(a+i))->first != NULL) {
printf("%s\n", (*(a+i))->first);

      free(*(a+i)); 
      (*(a+i)) = NULL;

}
	}
	}

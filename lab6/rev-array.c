/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
	char *buff = NULL ;
	size_t len ;
	int cnt = 0 ;
   double orig[MAX] ;
   
	printf("Enter a number > ");


	while( getline( &buff, &len, stdin ) > 1 )
	{
	   orig[cnt] = atof(buff);	
		++cnt ;
      printf("Enter another number >");
	}
   double reverd[cnt];
	//reverse original array
	for (int i=0; i< cnt;++i){
     	reverd[cnt-i-1] = orig[i]; 
		//printf("%lf\n", orig[i]);
	}
  puts("\nReversed Array: \n"); 
	//output reversed array
   for (int i=0; i< cnt;++i){
      	 
	printf("%lf ", reverd[i]);
	}
	printf("\n");
	free( buff ) ;
	return 0 ;
}

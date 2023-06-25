/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buff = NULL ;
	size_t len  ;
	int cnt = 0 ;
   double min,max,mean,total = 0 ;   
   
printf("Enter a number > ");


	while( getline( &buff, &len, stdin ) > 1 )
	{
		++cnt ;
      if (cnt == 1){
			max = atof(buff);
			min = atof(buff);
			total += atof(buff);
		}else if ( atof(buff) < min ) {
			min = atof(buff);
         total += atof(buff); 
		} else if ( atof(buff) > max ) {
			max = atof(buff);
         total +=atof(buff); 
			}else {
              total += atof(buff);
			}	


		printf("Enter another number > ");
	}
mean = total / cnt;
	//printf( "\nEnd of input detected.  I read %d lines.\n", cnt ) ;
printf("\nMean: %lf | Minimum: %lf | Maximum: %lf\n",mean,min,max);
	free( buff ) ;
	return 0 ;
}

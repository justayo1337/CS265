#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
*Function: capitalise
*----------------------
*takes a string and capitalises all the letters 
*
*str: the string to be capitalised
*
*returns: NULL

*/

void capitalise(char* str){
  int cnt = 0;
   while (*(str+cnt) != '\0'){
		if (islower(*(str+cnt)) ) {
             *(str+cnt) = toupper(*(str+cnt));
		}
   ++cnt;
	}
}

int main()
{
        char *buff = NULL ;
        size_t len ;
        int cnt = 0 ;

        while( getline( &buff, &len, stdin ) > 1 )
        {
               capitalise(buff);
					printf("%s",buff);
					 ++cnt ;
        }
		  

		   free( buff ) ;
        return 0 ;
}

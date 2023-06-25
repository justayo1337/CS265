#include <stdio.h>
#include <stdlib.h>

/*
*Function: arrFind
*----------------------
*takes an array of integers and searches for a specified integer (target)
*
*arr: the array of integers
*n: the size of the array
*target: the integer to be searched for within the array(arr)
*
*returns: Pointer to the first occurence of the integer in the array or NULL if the integer is not found in the array

*/
int *arrFind(int *arr, size_t n, int target) {
for ( int i = 0; i< n ; ++i){
if (*(arr+i) == target) {
	return arr+i; 
}else {
	continue;
}}


return NULL; } 


int main() {

        char *buff = NULL ;
        size_t len ;
        int cnt = 0;
        int *arr = malloc(4096),*final ,goal=1000;
		  
        while( getline( &buff, &len, stdin ) > 1 )
        {
              *(arr+cnt) = atoi(buff);
                ++cnt ;
        }
     final =   arrFind(arr,cnt,goal);
      if (final !=NULL ){ 
		 printf("%p, %d\n",final,*final);
		} 
		else {
			printf("NULL\n");}
		 free (buff) ;
		 return 0;

}

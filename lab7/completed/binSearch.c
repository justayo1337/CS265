#include <stdio.h>
#include <stdlib.h>

/*
*Function: binSearch
*----------------------
*searches for the position of a given integer within a given array of integers
*
*arr: the array of integers, assumed to be in ascending order
*n: the size of the array
*goal: the integer to search for 
*
*returns: the index of the target element if found, otherwise returns the size of the array 'n'

*/
int binSearch(int *arr, size_t n, int goal){
 int start = 0;
 int end = n-1;
 int mid;

while (start <= end ) {
 mid = (end+start)/2;
if (arr[mid] == goal){
		return mid ;
	} else if (arr[mid] > goal) {
        end= mid -1;
	} else if (arr[mid]  < goal ) {
		start = mid + 1;
}/*else{
	return n;
}*/}
return n;
}



int main() {

 char *buff = NULL;
 size_t len;
 int cnt =0;
 int vals[10];
 int final ;
while (getline(&buff,&len,stdin) > 1 ){
  vals[cnt] = atoi(buff);  
	 ++cnt;

 }

final = binSearch(vals,cnt,5);
printf("%d\n", final);
free(buff);
	return 0 ;

}

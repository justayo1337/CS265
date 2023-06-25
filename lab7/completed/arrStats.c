#include  <stdio.h> 
#include <stdlib.h>

/*
*Function: arrStats
*----------------------
*takes an array of doubles  and computes the arithmetic mean, max and min as doubles.
*
*arr: the array of doubles
*n: the size of the array
*mean: pointer to a double to store the value of the mean
*min: pointer to a double to store the value of the minimum value
*max: pointer to a double to store the value of the maximum value 
*
*returns: NULL 

*/
void arrStats(double *arr, size_t n, double *mean, double *min, double *max) {
 double total;
 *min = *(arr) ; 
 *max = *(arr);
for (int i = 0; i < n ; ++i) {
 total += *(arr+i);
  *min =  (*(arr+i) < *min ) ? *(arr+i) : *min;
  *max =  (*(arr+i) > *max ) ? *(arr+i) : *max;
}
*mean = total/n;

}

int main() {

	char *buff = NULL ;
        size_t len ;
        int cnt = 0;
        double *arr = malloc(4096) ,min,max,mean;
        while( getline( &buff, &len, stdin ) > 1 )
        {
			       *(arr+cnt) = atof(buff); 
                ++cnt ;
        }
       arrStats(arr,cnt,&mean,&min,&max);
  
printf("Min: %lf Max: %lf \n",min,max);
printf("Mean: %lf\n", mean);

  free (buff) ;
		  return 0;
}

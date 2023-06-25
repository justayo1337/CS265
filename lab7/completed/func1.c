#include <stdio.h>
#define MAX 100 
#include <stdlib.h>

double arrAvg(double *arr, size_t arrSize){
 double total, mean; 

 for (int i = 0; i < arrSize ; ++i){

	//printf("%lf\n",arr[i]);
   total += arr[i];

 }
mean = total /arrSize;
//printf("%lf\n",mean);
return mean;
}


void main(){

  char *buff = NULL;
  size_t len;
  int cnt = 0;
  double means;
  double inputs[MAX];

while(getline(&buff,&len,stdin) > 1) {
	inputs[cnt] = atof(buff);
	++cnt;
	}
  double updateInps[cnt];
 for (int i =0; i < cnt ; ++i ) {
	updateInps[i] = inputs[i] ; }

//arrAvg(inputs,sizeof(inputs));

 means = arrAvg(updateInps,cnt);
printf("Mean: %lf\n",means);
 

free( buff );

}

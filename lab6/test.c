#include <stdio.h>


void main(){

	int i=5,j=12,k=-13,z=0;
   _Bool a= j < 1;
   _Bool b = ! j < i;
     _Bool c=(! j) < i; 
	_Bool d = i + j;
   _Bool e = !i + j;
	_Bool f = !!i + !j;
	_Bool g = j && k;
	_Bool h = i && j || z;
	_Bool i2 = i && (j || z );

printf("a. %d\nb. %d\nc. %d\nd. %d\ne. %d\nf. %d\ng. %d\nh. %d\ni. %d\n",a,b,c,d,e,f,g,h,i2);

}

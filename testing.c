#include <stdio.h>


void main() {

	int i, *z;
	z=&i;
   i=22;
	printf("%p\n%d\n",z,*z);
}

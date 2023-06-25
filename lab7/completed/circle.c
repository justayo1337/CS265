#include <stdio.h>
#include <stdlib.h>
#include <math.h>






int main(int argc, char *argv[]){
	
  if (argc-1 != 2 ){
		printf("Need 2 arguments, a name and a radius\n");
		return 300 ;
	}
   
	char *name = argv[1];
	double radius = atof(argv[2]);
	double area;

	area = M_PI * radius * radius;
	printf("%s, your area is %.3E units square\n",name, area);
	return 0;

}

#include <stdio.h>

void main(){
	int total,twenty,ten,five,ones,remains;
	printf("Enter a dollar amount = > ");	
	scanf("%d",&total );

	twenty = total / 20;
	remains = total % 20;
	ten = remains / 10;
	remains = remains % 10;
	five = remains / 5;
	remains = remains % 5;
   ones = remains / 1;
  
  printf("$20 bills: %3d\n$10 bills: %3d\n$ 5 bills: %3d\n$ 1 bills: %3d\n",twenty,ten,five,ones);

}

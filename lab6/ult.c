#include <stdio.h>



int main(){

	int size ;
	puts("Enter your integer: " );
	scanf("%d",&size);
	char test = '*';
	for (int i = size; i>0; i--){
		int j = 1;
		while (j<=i) {
			printf("%c",test);
		   ++j;
		}
		printf("\n");
	}
}

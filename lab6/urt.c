#include <stdio.h>
#include <string.h>


int main(){

	int size ;
	puts("Enter your integer: " );
	scanf("%d",&size);
	char test[1] = "*";
	for (int i = size; i>0; --i){
		int j = 1;
		char str[size];
		strcpy(str,"");

		while (j<=i) {
		//	#strcpy(str,strcat(str,test));
      strcat(str,test);		
		++j;
		}
		printf("%*s\n",size,str);
		strcpy(str,"");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void int2string(int n, char answer[] ) {
 char temp[10]; 
 unsigned int rem,num, cnt=0;
 
num = n;
while (num != 0 ) {
	
	rem = num % 10;
   temp[cnt] = ( char)  rem + '0';
	++cnt;
	num /= 10;
}
for (int i = 0; i<cnt ; ++i){
	answer[cnt - i - 1] = temp[i];
}
if (n==0) {
	answer[0] = '0';
}else{
answer[cnt] = '\0';}
//free(temp);
}




int main() {
 char *buff = NULL ;
        size_t len ;
        int cnt = 0 ;
     unsigned int num;
        char *end;
        char num_str[10];
        while( getline( &buff, &len, stdin ) > 1 )
        
		 {
       num = strtoul(buff,&end,10);
       int2string(num,num_str);
       printf("%s\n",num_str);
		 ++cnt ;
        }


        free( buff ) ;
        return 0 ;

}

#include <stdio.h>

void main() {
int i, j;
i = 5;
j = 3;

printf("before: i = %d | j = %d\n", i, j);

i += j;
printf("a.)i = %d | j = %d\n", i, j);

i = 5;
j = 3;

i = j++;
printf("b.)i = %d | j = %d\n", i, j);

i = 5;
j = 3;

i = ++j;
printf("c.)i = %d | j = %d\n", i, j);

i = 5;
j = 3;

int val = i % j;
printf("d.)i = %d; j=%d || i %% j = %d\n",i,j,val);

i = 5;
j = 3;
val = i % j++;
printf("e.) i = %d; j= %d || i %% j++ = %d\n", i,j,val);

}

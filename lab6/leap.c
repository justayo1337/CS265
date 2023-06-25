/*#Author: Ayomide Adetunji
#Date: 7/31/2022
#Filename: leap.c
Code that checks if the yeear a user enters is a leap year. */
#include <stdio.h> 

void main(){

	int year;
	puts("Kindly enter a year: ");
	scanf("%d",&year);
	
	if ((year % 4 == 0 && ( year % 100 == 0 && year % 400 == 0)) || ( year % 4 == 0 && !( year % 100 == 0)) ){
		puts("YES");
	}else {
		puts("NO");
		}
}

#include <stdio.h>




void main() {
	double subtotal;
   float tip,tax;

   printf("Enter the current Subtotal: " ) ; 
	scanf("%lf",&subtotal);

   tax = 0.07 * subtotal;
	tip = 0.22 * subtotal;

	double total = tax + tip + subtotal;

	printf("The total amount to the paid is $%.2lf\n", total);

}

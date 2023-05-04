// C program to demonstrate working of memset()
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "This is an example of a long string....";
	printf("\nBefore memset(): %s\n", str);

	// Fill 13 characters starting from str[8] with '_'
	memset(str + 8, '_', 13*sizeof(char));

	printf(" After memset(): %s\n", str);
	return 0;
}

/* OUTPUT:

Before memset(): This is an example of a long string....
 After memset(): This is _____________ a long string....

*/

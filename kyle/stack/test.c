#include <stdio.h>
#include <string.h>

int main()
{
	char x[] = "5 55";
	char test[100];
	strcat(test, x);
	strcat(test, x);
	int b;
	b = x[0];
	printf("%s\n", test);
	printf("%i\n", b);
}

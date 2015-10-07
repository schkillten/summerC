#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"


/*
int doRpnT(char* p)
{
	printf("%s\n", p);
	size_t i;
	Stack* calc = newStack();
	char* num[10]; I DO WHAT I WANT
	for (i=0; i<strlen(p); i++){
		while (isdigit(p[i])){	
			strcpy(num, "5");
			printf("%c\n", p[i]);
			i++;
		}
	}
	push(calc, "55");
	printf("%i\n", atoi(top(calc))+1);
	return 1;
}
*/
int doRpn(char* p)
{
	Stack* calc = newStack();
	size_t i;

	for (i=0; i<strlen(p); i++)
	{
		if (p[i] == '+')
		{
			int v1 = pop(calc);
			int v2 = pop(calc);
			int newVal = v1 + v2;
			push(calc, newVal);
		}
		else if (p[i] == '-')
		{
			int v1 = pop(calc);
			int v2 = pop(calc);
			int newVal = v2 - v1;
			push(calc, newVal);
		}

		else
		{
			int x = 0;
			char* start = p+i;
			while(isdigit(p[i])){
				x++;
				i++;
			}
			char num[100];
			strncpy(num, start, x);
			num[x] = '\0';
			printf("%s\n", num);
			printf("%s\n", p+i);
			push(calc, atoi(num));
		}
	}
	printf("%i\n", top(calc));
	
	return 1;
}

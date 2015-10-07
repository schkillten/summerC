#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

#define INT_TO_CHAR 48

char* decToBin(char* bin, int n)
{
	int rem, quot,i,j;
	quot = n;
	for(i=0;(!(quot <= 0));i++){
		rem = quot % 2;
		quot /= 2;
		bin[i] = rem+INT_TO_CHAR;
	}
	for(j=0;j<(8-i);j++){
		bin[i+j] = 0+INT_TO_CHAR;
	}
	bin[8] = '\0';
	return bin;
}


int binToDec(char* b)
{
	int pof2[9] = {1,2,4,8,16,32,64,128, '\0'};
	int i;
	int dec = 0;
	for(i=0;b[i]!='\0';i++){
		if(b[i]  != '0'){
			dec += pof2[i];
		}
	}
	return dec;
}

char* rev(char* b)
{
    size_t l = strlen(b)-1;
    char temp[l+1];
    size_t i;
    for(i=0;i<=l;i++){
        temp[l-i] = b[i];
    }
    temp[l+1] = '\0';
    strncpy(b, temp, l+1);
    return b; 
}
/*
i=0
l=2
new[2] = b[0]
i=1
l=2
new[1] = b[1]
i=2
l=2
new[0] = b[2]
*/

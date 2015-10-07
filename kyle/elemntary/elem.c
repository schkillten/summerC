#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "elem.h"
#include "helpers.h"

#define INT_TO_CHAR 48

/*

TODO fix the converters for bin and decimal
TODO figure out how I want to handle changing the next generation to the current generation 
     when the nextGen function is finished (right now I'm just returning the struct and printing
     them by themselves
TODO make the neighbor count function less shitty looking
TODO Cleanup code and the main file

*/

struct Generations{
    CellType current;
    CellType next;
    char* rule;
    int width;
};

Generations* nextGen(Generations* g)
{
    int i, n_count;
    for(i=0;i<g->width;i++){
        n_count = getNeighborsCount(g, i);
        g->next[i] = g->rule[n_count];
    }
    strncpy(g->current, g->next, g->width);
    return g;
}

/*
FIXME YOU NEED TO GET A BIT STRING FROM THE INDEXES AND DO A BINTODEC CONVERSION AND USE THAT INDEX
*/
int getNeighborsCount(Generations* g, int cell_pos)
{
    char bitString[4];
    int n_index;
    if(cell_pos<1){ 
        bitString[2] = '0';
        bitString[1] = g->current[cell_pos];
        bitString[0] = g->current[cell_pos+1];
        bitString[3] = '\0';
    }else if(cell_pos<g->width-1){
        bitString[2] = g->current[cell_pos-1];
        bitString[1] = g->current[cell_pos];
        bitString[0] = g->current[cell_pos+1];
        bitString[3] = '\0';
    }else{
        bitString[2] = g->current[cell_pos-1];
        bitString[1] = g->current[cell_pos];
        bitString[0] = '0';
        bitString[3] = '\0';
    }
    /*rev(bitString);*/
    n_index = binToDec(bitString);
    return n_index;
}

void printStuff(Generations* g)
{
    int i;
    for(i=0;i<g->width;i++){
        if(g->current[i] == '1'){
            printf("\u2588");
        }else{
            printf(" ");
        }
    }
    printf("\n");
}

Generations* newGen(char* r, int w)
{
    Generations* gen_p = (Generations*)malloc(sizeof(Generations));
    gen_p->rule = r;
    gen_p->width = w;
    w++;
    gen_p->current = (CellType)malloc(sizeof(CellType)*w);	
    gen_p->next = (CellType)malloc(sizeof(CellType)*w);
    randInit(gen_p);
    /*centerInit(gen_p);*/
    return gen_p;
}

Generations* randInit(Generations* g)
{
    srand(time(NULL));
    int i;
    for(i=0;i<g->width;i++){ 
        g->current[i] = (rand()%2)+INT_TO_CHAR;
    }
    g->current[g->width] = '\0';
    return g;
}

Generations* centerInit(Generations* g)
{
    int i;
    for(i=0;i<g->width;i++)
    {
        g->current[i] = '0';
    }
    g->current[g->width/2] = '1';
    g->current[g->width] = '\0';
    return g;
}

/*
sooo

First, get the rule and turn it into binary.

Create the struct with the desired width and the binary rule char*

create empty current and next generations


*/

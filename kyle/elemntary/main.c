#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "helpers.h"
#include "elem.h"

/*
TODO handle case when no init_size is passed (at some point just make it user input rather than command line
*/

int main(int argc, char* argv[])
{
	
	if(argc > 1)
	{
		int init_num = atoi(argv[1]);
        if(argc > 2){

        int init_size = atoi(argv[2]);
		if(init_num <= 255 && init_num >= 0){	
			char bin[9];
			decToBin(bin, init_num);	
            Generations* g = newGen(bin, init_size);
            int m = 5000;
            int j;
            unsigned int me;
            me = 20000;
            for(j=0;j<m;j++){
                printStuff(g);
                nextGen(g);
                usleep(me);
            }
            /*
			int ret = binToDec(bin);
			printf("INITIAL VALUE: %i RETURNED VALUE: %i\n", init_num, ret);
            */
		}else{
			printf("ARGS OUT OF RANGE\n");
		}
    }else {
        printf("NO WIDTH PARAM GIVEN\n");
    }
	}else{
		printf("NO ARGS GIVEN\n");
	}
	return 1;
}


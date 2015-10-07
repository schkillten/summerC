#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>



void my_wc(int* c, char* s, long size);

int main(int argc, char* argv[])
{
	long file_size = 0;
	FILE* fp;
	int totals[4];


	if(argc > 1){
		fp = fopen(argv[1], "r");
		if(fp){
			fseek(fp, 0L, SEEK_END);
			file_size = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			char* s = (char*)malloc(file_size);
			fread(s, file_size, 1, fp);
			fclose(fp);
			my_wc(totals, s, file_size);
			printf(" %i  %i %i %s\n", totals[0], totals[1], totals[2], argv[1]);
		}else{
			printf("Unable to open file: %s\n", argv[1]);
		}	
	}else{
		printf("No files given\n");
	}
}

void my_wc(int* counts,char* s,long size)
{

	size_t i;
	/*
	int max_size = 20;
	char** somtin = (char**)malloc(max_size*sizeof(char*));
	*/
	int chars = 0;
	int lines = 0;
	int words = 0;
	for(i=0; i<size;i++){
		if(s[i] != ' ' && s[i] != '\0' && s[i] != '\n'){
			words++;
			int x = 0;
			char* start = s+i;
			while(s[i] != ' ' && s[i] != '\0' && s[i] != '\n'){
				x++;
				i++;
			}
			s[++i] = '\0';
			/*
			if(words >= max_size-2){
				max_size *= 2;
				somtin = (char**)realloc(somtin, max_size*sizeof(char*));
			}
			somtin[words-1] = (char*)malloc(x*sizeof(char));
			strncpy(somtin[words-1], start, x);
			somtin[words] = "\0";
			*/
		}
		if(s[i]=='\n'){
			lines++;
		}
	}	
	/*srand(time(NULL));*/
	
	chars = i;
	/*
	int rand_num;
	for(i=0;i<10;i++){
		rand_num = rand()%words;
		printf("%s\n", somtin[rand_num]);
	}
	printf("%i\n", somtin[8784882]);
	*/
	counts[0] = lines;
	counts[1] = words;
	counts[2] = chars;

	counts[3] = '\0';
}

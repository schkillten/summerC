#include <stdio.h>

#define MAX_BUFF 10

int main(){
  char buffer[MAX_BUFF];
  FILE *f_p;
  f_p = fopen("textFile", "r");
  if(f_p != NULL) {
    while(fgets(buffer, MAX_BUFF, f_p) != NULL){
      printf("%s\n", buffer);
    }
    fclose(f_p);
  } else {
    printf("File not found");
    return -1;
  }
  return 0;
}

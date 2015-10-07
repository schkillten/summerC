#include <stdio.h>
#include <string.h>

int main() {
  char src[] = "what do you want breh";
  char des[100];

  strncpy(des,src, 10);
  des[10] = '\0';
  printf("%s\n", des);



  strcpy(des, src);
  printf("%s\n", des);
  printf("%lu\n", strlen(des));

  strcat(des,src);
  printf("%s\n", des);
  printf("%lu\n", strlen(des));


}

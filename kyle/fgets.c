#include <stdio.h>

#define MAX_BUFF 80

int main() {
  char buffer[MAX_BUFF];
  while(fgets(buffer, MAX_BUFF, stdin) != NULL){
    printf("%s", buffer);
  }
}

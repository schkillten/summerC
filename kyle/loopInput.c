#include <stdio.h>

int main (char *argv[]) {
  int count;

  printf("p");
  while(1) {
    printf("p");
    for(count = 1; count < argc; count++){
      printf("p");
    }
  }
}

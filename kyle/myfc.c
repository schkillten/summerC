#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//void (my_func_p)(int);

void handle_sig_int(int value)
{
  printf("ARG: %d", value);
  fflush(stdout);
  //exit(0);
}

int main() {

  signal(SIGINT,  &handle_sig_int);
  signal(SIGTERM, &handle_sig_int);
  signal(SIGKILL, &handle_sig_int);
  signal(SIGTSTP, &handle_sig_int);
  while (1)
    usleep(500);
}

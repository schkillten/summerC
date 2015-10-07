#include <stdio.h>
#include <signal.h>

#include <stdlib.h>

// man signal, look at sighandler, this is the function pointer
void (*p_handle_sig)(int);

// need an actual function so we can point to it
void handle_sig(int value)
{
  printf("ARG: %i\n", value);
}

int main()
{
  // Different way to do it
  // p_handle_sig = handle_sig;
  // signal(SIGIN, p_handle_sig);

  // & returns the pointer value
  signal(SIGINT,  &handle_sig);

  // Handles some more signal, play around with them!
  // 'man 7 signal' for a list of signal
  // signal(SIGKILL, &handle_sig);
  // signal(SIGTERM, &handle_sig);
  //signal(SIGTSTP, &handle_sig);

  // dont want to kill the CPU
  while (1)
    usleep(500);
}

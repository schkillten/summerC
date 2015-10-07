#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct
{
  unsigned words;
  unsigned chars;
  unsigned lines;
} FileInfo;

FileInfo get_wc(char* file)
{
  FileInfo info = {0};
  char* p = file;

  while (*p)
  {
    if (*p == '\n')
    {
      info.lines++;
    }
    else
    {
      int count = 0;
      while (*p && *p != '\n' && *p != ' ')
      {
        p++;
        count++;
      }

      if (*p == '\n')
        info.lines++;

      if (count > 0)
        info.words++;

      info.chars += count;
    }

    info.chars++;
    p++;
  }

  return info;
}

void print_word(char* input, int pos)
{
  char* p = input;
  int current = 0;
  while (current < pos)
  {
    if (*p == '\0')
    {
      current++;
      while (*p == '\0')
        p++;
    }

    p++;
  }

  //printf("%i %i\n", pos, current);
  printf("(%s) --- (%c)\n", p, (*p));
}

void find_n_random(int n, char* input, FileInfo info)
{
  char* p = input;
  int i = 0;

  while (*p)
  {
    if (*p == ' ' || *p == '\n')
    {
      if (*(p + 1) != '\0')
      {
        *p = '\0';
        i++;
      }
    }

    p++;
  }

  int t;
  for (t = 0; t < 10; t++)
    print_word(input, rand() % info.words);

/*
  printf("----\n");
  for (t = 0; t < 20; t++)
    printf("%s\n", new[t]);
  printf("----\n");

  for (t = i - 20; t < i ; t++)
    printf("%s\n", new[t]);
    */
}

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    FILE* f = fopen(argv[1], "r");
    srand(time(NULL));

    if (f)
    {
      long file_size = 0;

      fseek(f, 0L, SEEK_END);
      file_size = ftell(f);
      fseek(f, 0L, SEEK_SET);

      char* s = (char*)malloc(file_size * sizeof(char));

      fread(s, file_size, 1, f);
      s[file_size] = '\0';
      fclose(f);

      FileInfo info = get_wc(s);
      printf("%i %i %i %s\n", info.words, info.lines, info.chars, argv[1]);

      find_n_random(10, s, info);
    }
  }
}

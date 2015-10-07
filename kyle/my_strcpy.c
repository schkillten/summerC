#include <stdio.h>
#include <string.h>

char* my_strcpy(char *dest, const char *src);
char* super_cpy(char* dest, char* const src);
char* my_strcat(char* dest, char const *src);
size_t my_strlen(const char *s);


int main()
{
  char src[] = "Yooobruhh";
  char dest[100];
  my_strcpy(dest, src);
  printf("%s\n", dest);
  printf("%lu\n", my_strlen(src));

  my_strcat(dest, src);
  printf("%s\n", dest);
}


char* my_strcpy(char *dest, const char *src)
{
  int i;
  i = 0;
  while(src[i])
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest; 
}

char* my_strcat(char *dest, const char *src)
{
  size_t dest_len = my_strlen(dest);
  size_t i;
  i = 0;

  while(src[i])
  {
    dest[dest_len + i] = src[i];
    i++;
  }
  return dest;
}

size_t my_strlen(const char *s) 
{
  size_t n;
  n = 0;
  while(*s++)
  {
    n++;
  }

  return n;
}

char* super_cpy(char* dest, char* src)
{
  /*

   1  2  3  4  5  6  7 
  [0][d][d][d][d][d][0]]
      ^
      |
      |
      p 0x2

   *p = '\0';

   (*P)++
   p++;

   p = '\0';

  */
  while (*dest++ = *src++);

  return dest;
}

/*char* my_strcat(char kk*/


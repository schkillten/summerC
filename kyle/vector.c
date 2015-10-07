#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 32

struct Vector
{
  int* elems;
  int  size;
  int  max_size;
};

Vector* vector_new(int size)
{
  if (size <= 0)
    size = DEFAULT_SIZE;

  Vector* vector   = (Vector*)malloc(sizeof(Vector));
  vector->elems    = (int*)malloc(sizeof(int) * size);
  vector->size     = 0;
  vector->max_size = size;
}

void vector_delete(Vector* vector)
{
  free(vector->elems);
  free(vector);

  vector->elems = NULL;
  vector        = NULL;
}

static void vector_double_size(Vector* vector)
{
  int new_size     = vector->max_size * 2;
  vector->max_size = new_size;
  vector->elems    = (int*)realloc(vector->elems, sizeof(int) * new_size);
}

void vector_push_back(Vector* vector, int elem)
{
  if (vector->size + 1 >= vector->max_size)
    vector_double_size(vector);

  vector->elems[vector->size] = elem;
  vector->size++;
}

void vector_pop_back(Vector* vector)
{
  if (vector->size > 0)
    vector->size--;
}

int vector_back(Vector* vector)
{
  if (vector->size > 0)
    return vector->elems[vector->size - 1];

  fprintf(stderr, "Error, no elements are in the vector\n");
  return -1;
}

int vector_get(Vector* vector, int index)
{
  if (index >= 0 && index < vector->size)
    return vector->elems[index];

  fprintf(stderr, "Index out of bounds!\n");
  return -1;
}

int vector_size(Vector* vector)
{
  return vector->size;
}

int vector_empty(Vector* vector)
{
  return vector->size == 0;
}

int main2()
{
  int i;
  Vector* vector = vector_new(0);

  printf("SIZE: %i\n", vector_size(vector));
  for (i = 0; i < 66666666; i++)
    vector_push_back(vector, i);

  printf("SIZE: %i\n", vector_size(vector));

  for (i = 0; i < 1000; i++)
    printf("%i, ", vector_get(vector, i));
  printf("\n");

  int size = vector_size(vector);
  for (i = 0; i < size; i++)
    vector_pop_back(vector);

  printf("SIZE: %i\n", vector_size(vector));
}

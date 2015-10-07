#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector Vector;

extern Vector* vector_new   (int size);
extern void    vector_delete(Vector* vector);

extern void vector_push_back(Vector* vector, int elem);
extern void vector_pop_back (Vector* vector);
extern int  vector_back     (Vector* vector);
extern int  vector_get      (Vector* vector, int index);
extern int  vector_size     (Vector* vector);
extern int  vector_empty    (Vector* vector);

#endif // VECTOR_H

#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 20

typedef struct cvector{
    void **data;
    int idx;
    int size;
}cvector;

cvector *create(void);

void  insert(cvector *vec, int idx, void *value);
void  swap(cvector *vec, int idx, int idx_);
void  push_back(cvector *vec, void *value);
void  pop_back(cvector *vec);
void  delete(cvector *vec);

#endif 
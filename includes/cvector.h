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

cvector *cvector_create(void);
void  cvector_insert(cvector *vec, int idx, void *value);
void  cvector_swap(cvector *vec, int idx, int idx_);
void  cvector_push_back(cvector *vec, void *value);
void  cvector_pop_back(cvector *vec);
void  cvector_delete(cvector *vec);

#endif 

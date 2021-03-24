#ifndef CVECTOR_H
#define CVECTOR_H

#include "libft.h"

#define INITIAL_SIZE 20

typedef struct cvector{
    void **data;
    int idx;
    int size;
}cvector;

cvector *cvector_create(void);
int     cvector_resize(cvector *vec, size_t size);
int     cvector_init(cvector*   vec);
void    cvector_insert(cvector *vec, int idx, void *value);
void    cvector_swap(cvector *vec, int idx, int idx_);
void    cvector_push_back(cvector *vec, void *value);
void    cvector_pop_back(cvector *vec);
void    cvector_delete(cvector *vec, void (*del)(void *));

#endif 

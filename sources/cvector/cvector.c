#include "cvector.h"

/*
**  Initialises an already existing cvector
*/

int cvector_init(cvector*   vec)
{
    if (!(vec->data = ft_memalloc(sizeof(void *) * INITIAL_SIZE)))
        return (0);
    vec->idx = 0;
    vec->size = INITIAL_SIZE;
    return (1);
}

/*
**  Allocates a new vector and initializes it
*/

cvector *cvector_create(void){
    cvector *vec;
    
    if (!(vec = (cvector*)malloc(sizeof(cvector))))
        return (NULL);
    if (!cvector_init(vec))
    {
        free(vec);
        return (NULL);
    }
    return vec;
}

/*
**  resizes the vector size
*/

int cvector_resize(cvector *vec, size_t size)
{
    if (!(vec->data = realloc(vec->data, sizeof(void*) * size)))
        return (0);
    vec->size = size;
    return (1);
}

/*
**  add element at the end 
*/

void cvector_push_back(cvector *vec, void *value){
    if ((vec->idx >= vec->size))
    {
        vec->size = (vec->size) << 1;
        vec->data = realloc(vec->data, sizeof(void*) * (vec->size));        
    }
    vec->data[vec->idx] = value;
    vec->idx++;
}

/*
**  delete last element
*/

void cvector_pop_back(cvector *vec){
    if((vec->idx != 0)){
        vec->data[vec->idx - 1] = 0;
        vec->idx--;
    }
}

/*
**  frees the vector and all it's elements using del function if passed
*/

void cvector_delete(cvector *vec, void (*del)(void *)){
    int index;

    index = 0;
    if (del)
    {
        while (index < vec->size)
        {
            del(vec->data[index]);
            index++;
        }
    }
    free(vec->data);
    free(vec);
}

/*
    insert element
*/

void cvector_insert(cvector *vec, int idx, void *value){
    if ((idx > -1) && (idx <= (vec->size - 1)))
    {
        vec->data[idx] = value;
    }
}

/*
    swap elements
*/

void cvector_swap(cvector *vec, int idx, int idx_){
    void *tmp;
    if ((idx > -1) && (idx <= (vec->size - 1)))
    {
        tmp = vec->data[idx];
        vec->data[idx] = vec->data[idx_];
        vec->data[idx_] = tmp;
    }
}

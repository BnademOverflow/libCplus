#include "cvector.h"

cvector *cvector_create(void){
    cvector *vec = (cvector*)malloc(sizeof(cvector));    
    vec->data = malloc(sizeof(void*) * INITIAL_SIZE);

    if ((vec == NULL) || (vec->data == NULL))
    {
        perror("malloc");
        exit(-1);
    memset(vec->data, 0, (INITIAL_SIZE * sizeof(vec->data)));
    }
    vec->idx = 0;
    vec->size = INITIAL_SIZE;
    return vec;
}

/*
    add element at the end 
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
    delete last element
*/

void cvector_pop_back(cvector *vec){
    if((vec->idx != 0)){
        vec->data[vec->idx - 1] = 0;
        vec->idx--;
    }
}

/*
    *magic*
*/

void cvector_delete(cvector *vec){
    if ((vec->data != NULL))
    {    
        free(vec->data);
        free(vec);
    }
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

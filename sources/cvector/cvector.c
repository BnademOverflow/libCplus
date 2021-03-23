#include "cvector.h"

cvector *create(void){
    cvector *vec = (cvector*)malloc(sizeof(cvector));    
    vec->data = malloc(sizeof(void*) * INITIAL_SIZE);

    memset(vec->data, 0, (INITIAL_SIZE * sizeof(vec->data)));
    if ((vec == NULL) || (vec->data == NULL))
    {
        perror("malloc");
        exit(-1);
    }
    vec->idx = 0;
    vec->size = INITIAL_SIZE;
    return vec;
}

/*
    add element at the end 
*/

void push_back(cvector *vec, void *value){
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

void pop_back(cvector *vec){
    if((vec->idx != 0)){
        vec->data[vec->idx - 1] = 0;
        vec->idx--;
    }
}

/*
    *magic*
*/

void delete(cvector *vec){
    if ((vec->data != NULL))
    {    
        free(vec->data);
        free(vec);
    }
}

/*
    insert element
*/

void insert(cvector *vec, int idx, void *value){
    if ((idx > -1) && (idx <= (vec->size - 1)))
    {
        vec->data[idx] = value;
    }
}

/*
    swap elements
*/

void swap(cvector *vec, int idx, int idx_){
    void *tmp;
    if ((idx > -1) && (idx <= (vec->size - 1)))
    {
        tmp = vec->data[idx];
        vec->data[idx] = vec->data[idx_];
        vec->data[idx_] = tmp;
    }
}

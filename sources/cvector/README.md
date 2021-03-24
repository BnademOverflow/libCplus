# cvector
dynamic array implementation in c.

## functions
- `cvector *create(void);`
- `int     cvector_resize(cvector *vec, size_t size);`
- `void  cvector_insert(cvector *vec, int idx, void *value);` 
- `void  cvector_swap(cvector *vec, int idx, int idx_);`
- `void  cvector_push_back(cvector *vec, void *value);`
- `void  cvector_pop_back(cvector *vec);`
- `void    cvector_delete(cvector *vec, void (*del)(void *));`

### test

```
int main(void){
    cvector *vec = create();
    cvector_push_back(vec, "wesh");
    cvector_push_back(vec, "wesh");
    cvector_push_back(vec, "azin");
    cvector_swap(vec, 2, 1);
    ...
    cvector_delete(vec);
}
```
### output

```
wesh azin wesh
```

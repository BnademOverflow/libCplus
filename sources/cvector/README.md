# cvector
dynamic array implementation in c.

## functions
- `cvector *create(void);`
- `void  insert(cvector *vec, int idx, void *value);` 
- `void  swap(cvector *vec, int idx, int idx_);`
- `void  push_back(cvector *vec, void *value);`
- `void  pop_back(cvector *vec);`
- `void  delete(cvector *vec);`

### test

```
int main(void){
    cvector *vec = create();
    push_back(vec, "wesh");
    push_back(vec, "wesh");
    push_back(vec, "azin");
    swap(vec, 2, 1);
    ...
    delete(vec);
}
```
### output

```
wesh azin wesh
```
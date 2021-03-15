# TTSLIST
a linked list library
# Dependencies
No dependencies
# Headers
`ttslist.h` in `includes` directory
# Structs
`t_list_head` contains fields :

- `size`: number  of elements in the list

- `first`: first node (`t_list_node`) in the list

- `last`: last_node (`t_list_node`) in the list

- `push`: pointer to function to push element in the end

- `push_front`: pointer to function to push element in the front

- `pop`: pointer to function to remove element from the end

- `pop_front`: pointer to function to remove element from the front

- `iterator`: current node, while iterating using `ttslist_iter_content` or `ttslist_iter`

`t_list_node` contains fields:
- `content`: pointer to the content of the node
- `content_size`: not used internaly by the library functions, but can be used to keep of the size of `content`
- `next`: pointer to the next node in the list
- `prev`: pointer to the previous node in the list

idea is you can have same struct, but changing the pop, push, pop_front, pop_front can change the behaviour, so it can act as a `list` or `stack` or `queue` or `dequeue`

# Functions
## Constructor :
```C
void		ttslist_init(t_list_head *head);
```
Initialises a `t_list_head`
## Iterating :
```C
void		*ttslist_iter_content(t_list_head *head);
```
Iterated thru the list and returns content of each node
### Example :
consider we have a `t_list_head my_list` and we want to iterate thru without using a temp `t_list_node *temp`.

This is an easier way to do it, in a `foreach` fashion.
```C
void *content;

my_list.iterator = mylist.first;
while ((content = ttslist_iter_content(&my_list)))
{
    printf("you can now access the content : %s\n", content);
}
```
### What if i want to iterate thru each node, and not the content ?
```C
t_list_node *ttslist_iter(t_list_head *head);
```
same as `ttslist_iter_content` but at each iteration it returns the current node (content of `iterator`)
## Search :
```C
void		*ttslist_get_id_content(t_list_head *head, int id);
```
Gets the content of the node at index `id`.
```C
int			ttslist_get_content_id(t_list_head *head, void *content);
```
Gets the index of the node with the given `content`, by comparing content addresses.
```C
int			ttslist_remove_node_with_content(t_list_head *list, void *content);
```
Removes the node with the content `content`
# Operations
The linked list supports various operations
## Adding element at the end:
```C
t_list_node	*ttslist_push(t_list_head *head, t_list_node *newnode);
t_list_node	*ttslist_push_new(t_list_head *head, void *content);
```
## Adding element at the start:
```C
t_list_node	*ttslist_push_front(t_list_head *head, t_list_node *newnode);
t_list_node *ttslist_push_front_new(t_list_head *head, void *content);
```
## Removing element from the end:
```C
t_list_node	*ttslist_pop(t_list_head *head);
void		*ttslist_pop_content(t_list_head *head);
```
## Removing element from the start:
```C
t_list_node	*ttslist_pop_front(t_list_head *head);
void		*ttslist_pop_front_content(t_list_head *head);
```
## Removing a specific node from any position:
```C
void		*ttslist_splice(t_list_head *head, t_list_node *node);
```
# Destructor
```C
void		ttslist_purge(t_list_head *list, void (*purge)(void *));
```
# Demo
```C
#include <stdio.h>
#include "libft.h"
#include "ttslist.h"

int main(void)
{
    t_list_head string_list;

    // initialising the list
    ttslist_init(&string_list);

    // pushing some elements
    string_list.push(&string_list, ft_strdup("Pushing to back"));
    string_list.push_front(&string_list, ft_strdup("Pushing to front"));
    ttslist_push_new(&string_list, ft_strdup("Pushing with function to back"));
    ttslist_push_front_new(&string_list, ft_strdup("Pushing with function to front"));

    // iterating thru the elements
    char    *string;
    int     element_index = 0;

    string_list.iterator = string_list.first;
    while ((string = (char *)ttslist_iter_content(&string_list)))
    {
        printf("string_list[%d] = %s\n", element_index, string);
        element_index++;
    }

    // Freeing the list and the content
    ttslist_purge(&string_list, &free);

    return (0);
}
```
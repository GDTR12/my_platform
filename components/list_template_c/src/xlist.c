#include "xlist.h"

// idx=0 ret:head   if idx > number of list return the end of node
inline xlist_node_t* list_get_item(const xlist_node_t *head, uint16_t idx)
{
    xlist_node_t* tmp = head;
    while (!list_is_last(tmp,head) && idx != 0)
    {
        tmp = tmp->next;
        idx--; 
    }
    return tmp;
}

inline uint16_t list_get_total(const xlist_node_t *head)
{
    uint16_t total = 0;
    xlist_node_t* tmp = head;
    while (!list_is_last(tmp,head))
    {
        tmp = tmp->next;
        total++; 
    }
    return total;
}

// @ret: -1: 没有这个节点   0：item==head
inline int list_get_idx(const xlist_node_t *item,const xlist_node_t *head)
{
    uint16_t idx = 0;
    xlist_node_t* tmp = head;
    while (tmp != item)
    {
        if(list_is_last(tmp, head)){
            return -1;
        }
        tmp = tmp->next;
        idx++; 
    }
    return idx;
}

static inline void __list_add(xlist_node_t *new,
			      xlist_node_t *prev,   //head
			      xlist_node_t *next)   //head
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
    prev->next = new;
}

inline void list_add_first(xlist_node_t *new,xlist_node_t *head)
{
    __list_add(new,head,head->next);
    return;
}

inline void list_add_end(xlist_node_t *new, xlist_node_t *head)
{
    __list_add(new,head->prev,head);
    return;
}

inline int list_empty(const xlist_node_t *head)
{
    return head->next == head;
}

static inline int __list_remove(xlist_node_t *prev,
			      xlist_node_t *mid,
			      xlist_node_t *next)
{
    mid->next = NULL;
    mid->prev = NULL;
    prev->next = next;
    next->prev = prev;
}                

inline void list_remove_first(xlist_node_t *head)
{
    if(list_empty(head))return;
    __list_remove(head,head->next,head->next->next);
}

inline void list_remove_end(xlist_node_t *head)
{
    if(list_empty(head))return;
    __list_remove(head->prev->prev,head->prev,head);
}

inline int list_is_last(const xlist_node_t *list,
				const xlist_node_t *head)
{
	return list->next == head;
}

inline list_iter_t list_iter(const xlist_node_t *head)
{
    list_iter_t ret;
    ret.now = head->next;
    ret.end = head;
    return ret;
}

inline void list_iter_next(list_iter_t *iter)
{
    iter->now = iter->now->next;
}

inline uint16_t list_iter_end(list_iter_t *iter)
{
    return iter->now == iter->end;
}

inline list_iter_t list_reverse_iter(const xlist_node_t *head)
{
    list_iter_t iter;
    iter.now = head->prev;
    iter.end = head;
    return iter;
}

inline void list_reverse_iter_next(list_iter_t *iter)
{
    iter->now = iter->now->prev;
}

inline uint16_t list_reverse_iter_end(list_iter_t *iter)
{
    iter->now == iter->end;
}


/*----------------------------------------------------------------------------
 * author: gdtr
 * function: 参考linux 内核的一个双向循环链表，理论下适用所有包含 list_node_t list 的结构。
 *---------------------------------------------------------------------------*/


#ifndef XLIST_H
#define XLIST_H

#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#define xlist_malloc 

#define offsetof(type,member) ((size_t)& ((type*)0)->member)

#define container_of(ptr,type,member) ({ \
    const typeof(((type*)0)->member)* __ptr = (ptr); \
    (type*)((char*)__ptr - offsetof(type,member)); })



#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_NODE_INIT(name) { NULL, NULL }
#define LIST_HEAD(name) xlist_node_t name = LIST_HEAD_INIT(name)
#define LIST_NODE(name) xlist_node_t name = LIST_NODE_INIT(name)
#define INIT_LIST_HEAD(name) { ((name).next) = (&(name)); ((name).prev) = (&(name));}
#define INIT_LIST_NODE(name) { ((name).next) = (NULL); ((name).prev) = (NULL);}

typedef struct xlist_node {
    struct xlist_node *next;
    struct xlist_node *prev;
}xlist_node_t;

#define list_entry(ptr, type, member) container_of(ptr, type, member)
void list_add_end(xlist_node_t *new_l, xlist_node_t *head);
void list_add_first(xlist_node_t *new_l,xlist_node_t *head);
void list_remove_first(xlist_node_t *head);
void list_remove_end(xlist_node_t *head);
xlist_node_t* list_get_item(const xlist_node_t *head, uint16_t idx);
uint16_t list_get_total(const xlist_node_t *head);
int list_get_idx(const xlist_node_t *item,const xlist_node_t *head);

int list_empty(const xlist_node_t *head);
int list_is_last(const xlist_node_t *list, const xlist_node_t *head);

typedef struct{
    xlist_node_t* now;
    xlist_node_t* end;
}list_iter_t;

/* 
链表的正向遍历：    
eg:
    list_iter_t iter_sev = list_iter( &(mq->head_service) );
    for(; !list_iter_end(&iter_sev); list_iter_next(&iter_sev))
    {
        mqtt_service_t* sev = list_entry(iter_sev.now, mqtt_service_t, list);
    }

*/ 
list_iter_t list_iter(const xlist_node_t *head);
void list_iter_next(list_iter_t *iter);
uint16_t list_iter_end(list_iter_t *iter);

/* 
链表的反向遍历：    
eg:
    list_iter_t iter_sev = list_reverse_iter(&(mq->head_service));
    for(; !list_reverse_iter_end(&iter_sev); list_reverse_iter_next(&iter_sev))
    {
        mqtt_service_t *sev = list_entry(iter_sev.now, mqtt_service_t, list);
    }
*/ 
list_iter_t list_reverse_iter(const xlist_node_t *head);
void list_reverse_iter_next(list_iter_t *iter);
uint16_t list_reverse_iter_end(list_iter_t *iter);





#endif

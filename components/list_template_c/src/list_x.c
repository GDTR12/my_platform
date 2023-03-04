#include "list_x.h"
#include "stdio.h"
#include "stdbool.h"

ListX_t* listX_new(ListX_register_t func)
{
    CHECK_EQUAL_RETURN(func.listX_malloc,NULL,NULL);
    CHECK_EQUAL_RETURN(func.listX_free,NULL,NULL);
    CHECK_EQUAL_RETURN(func.listX_printValue, NULL, NULL);

    ListX_t* ret = func.listX_malloc(sizeof(ListX_t));
    CHECK_EQUAL_RETURN(ret, NULL, NULL);

    ret->num = 0;
    ret->phead = NULL;
    ret->funcs.listX_free = func.listX_free;
    ret->funcs.listX_malloc = func.listX_malloc;
    ret->funcs.listX_printValue = func.listX_printValue;
    return ret;
}

ListX_Error_Type_t listX_destroy(ListX_t* list)
{
    CHECK_EQUAL_RETURN(list, NULL, LISTX_DATA_ERROR);
    ListX_Node_t* ptemp = list->phead;
    while (ptemp != NULL)
    {
        ListX_Node_t* to_be_free = ptemp;
        ptemp = ptemp->next;
        list->funcs.listX_free(to_be_free);
    }
    list->funcs.listX_free(list);
    return LISTX_OK;
}

ListX_Node_t* listX_append(ListX_t* list, LISTX_ITEM_TYPE data)
{
    CHECK_EQUAL_RETURN(list, NULL, NULL);
    ListX_Node_t* ptemp = list->phead;
    if(ptemp == NULL)
    {
        list->phead = list->funcs.listX_malloc(sizeof(ListX_Node_t));
        CHECK_EQUAL_RETURN(list->phead, NULL, NULL);
        list->phead->data = data;
        list->num++;
        return list->phead;
    }else
    {
        while (ptemp->next != NULL)
        {
            ptemp = ptemp->next;
        }
        ptemp->next = list->funcs.listX_malloc(sizeof(ListX_Node_t));
        CHECK_EQUAL_RETURN(ptemp->next, NULL, NULL);
        ptemp->next->data = data;
        list->num++;
        return ptemp->next;       
    }

}

ListX_Error_Type_t listX_pop(ListX_t* list)
{
    CHECK_EQUAL_RETURN(list, NULL, LISTX_DATA_ERROR);
    CHECK_EQUAL_RETURN((list->num == 0), true, LISTX_DATA_ERROR);

    ListX_Node_t* ptemp = list->phead;

    if(list->num <= 1)
    {
        list->funcs.listX_free(list->phead);
        list->phead = NULL;
        list->num--;
    }else
    {
        while (ptemp->next->next != NULL)
        {
            ptemp = ptemp->next;
        }
        list->funcs.listX_free(ptemp->next);
        ptemp->next = NULL;
        list->num--;
    }
    return LISTX_OK;
}

ListX_Node_t* listX_insert(ListX_t* list, LISTX_ITEM_TYPE data, uint16_t index)
{
    CHECK_EQUAL_RETURN(list, NULL, NULL);
    CHECK_EQUAL_RETURN((index > list->num), true, NULL);
    
    if(list->phead == NULL) // 链表无节点
    {
        list->phead = list->funcs.listX_malloc(sizeof(ListX_Node_t));
        CHECK_EQUAL_RETURN(list->phead, NULL, NULL);
        list->phead->data = data;
        list->num++;
        return list->phead;
    }
    else
    {
        if(index == 0)
        {
            ListX_Node_t* to_be_insert = list->funcs.listX_malloc(sizeof(ListX_Node_t));
            CHECK_EQUAL_RETURN(to_be_insert, NULL, NULL);
            to_be_insert->data = data;
            to_be_insert->next = list->phead;
            list->phead = to_be_insert;
            list->num++;
            return to_be_insert;           
        }
        else // 非头结点插入
        {
            ListX_Node_t* ptemp = list->phead;
            index -= 1;
            while (index--)
            {
                ptemp = ptemp->next;
            }
            ListX_Node_t* to_be_insert = list->funcs.listX_malloc(sizeof(ListX_Node_t));
            CHECK_EQUAL_RETURN(to_be_insert, NULL, NULL);
            to_be_insert->data = data;
            to_be_insert->next = ptemp->next;
            ptemp->next = to_be_insert;
            list->num++;
            return to_be_insert;              
        }
    }

}

ListX_Error_Type_t listX_remove(ListX_t* list, ListX_Node_t* node)
{
    CHECK_EQUAL_RETURN(list, NULL, LISTX_DATA_ERROR);
    CHECK_EQUAL_RETURN(node, NULL, LISTX_DATA_ERROR);

    ListX_Node_t* ptemp = list->phead;
    if(ptemp == NULL)
    {
        return LISTX_DATA_ERROR;    
    }
    if(ptemp == node)
    {
        list->phead = list->phead->next;
        list->funcs.listX_free(ptemp);
        list->num--;
        return LISTX_OK;
    }
    while (ptemp->next != node && ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    if(ptemp->next == node)
    {
        ListX_Node_t* to_be_free = ptemp->next;
        ptemp->next = ptemp->next->next;
        list->funcs.listX_free(to_be_free);
        list->num--;
        return LISTX_OK;
    }
    return LISTX_DATA_ERROR;
}

int listX_get_index(ListX_t* list, ListX_Node_t* node)
{
    CHECK_EQUAL_RETURN(list, NULL, LISTX_DATA_ERROR);
    CHECK_EQUAL_RETURN(list->phead, NULL, LISTX_DATA_ERROR);
    CHECK_EQUAL_RETURN(node, NULL, LISTX_DATA_ERROR);
    int index = 0;
    ListX_Node_t* ptemp = list->phead;
    while (ptemp != node && ptemp->next != NULL)
    {
        ptemp = ptemp->next;
        index++;
    }
    if(ptemp == node)
    {
        return index;
    }
    else
    {
        return -1;
    } 
}

ListX_Error_Type_t listX_print(ListX_t* list)
{
    CHECK_EQUAL_RETURN(list, NULL, LISTX_DATA_ERROR);
    ListX_Node_t* ptemp = list->phead;
    while (ptemp != NULL)
    {
        list->funcs.listX_printValue(ptemp);
        ptemp = ptemp->next;
    }
    return LISTX_OK;
}

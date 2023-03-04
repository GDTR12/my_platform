#ifndef LIST_X_H
#define LIST_X_H

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#ifdef __cplusplus__
extern "C"{
#endif

typedef struct ListX_data
{
    
}ListX_data_t;


#define LISTX_ITEM_TYPE int

#define CHECK_EQUAL_RETURN(_toBeCheck, _value, _toReturn) if(_toBeCheck == _value)return _toReturn;
#define CHECK_UNEQUAL_RETURN(_toBeCheck, _value, _toReturn) if(_toBeCheck != _value)return _toReturn;


typedef struct ListX_Node
{
    LISTX_ITEM_TYPE data;
    struct ListX_Node* next;
}ListX_Node_t;

typedef struct ListX ListX_t;

typedef struct ListX_register
{
    void* (*listX_malloc)(size_t size);
    void (*listX_free)(void* _pObj);
    void (*listX_printValue)(ListX_Node_t* node);
}ListX_register_t;

typedef struct ListX
{
    ListX_Node_t* phead;
    uint16_t num;
    struct ListX_register funcs;
}ListX_t;

typedef enum
{
    LISTX_OK,
    LISTX_MALLOC_ERROR,
    LISTX_DATA_ERROR,
}ListX_Error_Type_t;

ListX_t* listX_new(ListX_register_t func);
ListX_Error_Type_t listX_destroy(ListX_t* list);

ListX_Node_t* listX_append(ListX_t* list, LISTX_ITEM_TYPE data);
ListX_Error_Type_t listX_pop(ListX_t* list);

ListX_Node_t*  listX_insert(ListX_t* list, LISTX_ITEM_TYPE data, uint16_t index);
ListX_Error_Type_t listX_remove(ListX_t* list, ListX_Node_t* node);

int listX_get_index(ListX_t* list, ListX_Node_t* node);

ListX_Error_Type_t listX_print(ListX_t* list);

#ifdef __cplusplus__
}
#endif

#endif

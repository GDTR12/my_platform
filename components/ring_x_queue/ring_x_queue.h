#ifndef RING_X_QUEUE_H
#define RING_X_QUEUE_H

typedef int Ring_Data;

typedef struct Data_Ring_queue{  
    unsigned int now_idx;
    unsigned int size; 	//环形缓冲区容量
    Ring_Data *array;   		//实际缓冲区（数组）的首地址
}Data_Ring_queue_t; 

void frq_init(Data_Ring_queue_t* frq, Ring_Data* array, int size);
void frq_push(Data_Ring_queue_t* frq, Ring_Data data);
Ring_Data frq_get(Data_Ring_queue_t* frq);
Ring_Data frq_get_byIdx(Data_Ring_queue_t* frq, unsigned int idx);

void frq_init(Data_Ring_queue_t* frq, Ring_Data* array, int size)
{
    frq->array = array;
    frq->size = size;
    frq->now_idx = 0;
}

void frq_push(Data_Ring_queue_t* frq, Ring_Data data)
{
    frq->now_idx += 1;
    if(frq->now_idx >= frq->size){
        frq->now_idx = 0;
    }
    frq->array[frq->now_idx] = data;
}

Ring_Data frq_get(Data_Ring_queue_t* frq)
{
    return frq->array[frq->now_idx];
}

Ring_Data frq_get_byIdx(Data_Ring_queue_t* frq, unsigned int idx)
{
    if(idx >= frq->size){
        return frq->array[frq->now_idx];
    }
    int to_idx = frq->now_idx - idx;
    if(to_idx < 0)
    {
        to_idx += frq->size;
    }
    return frq->array[to_idx];
}

#endif

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "xlist.h"
#include "stdlib.h"
#include "mdefine.h"



#ifdef __cplusplus__
extern "C" {
#endif

#define CHECK_EQUAL_RETURN(_toBeCheck, _value, _toReturn) if(_toBeCheck == _value)return _toReturn;


typedef struct {
    xlist_node_t list;
    oc_mqtt_profile_kv_t pro;
}mqtt_proprety_t;


typedef struct{
    xlist_node_t list;
    xlist_node_t head_proprety;
    oc_mqtt_profile_service_t sev;
}mqtt_service_t;

typedef struct{
    xlist_node_t head_service;
}mqtt_report_t;

#define kmalloc(size) malloc(size)
#define kfree(ptr)  free(ptr)

#define INIT_MQTT_REPORT(name) mqtt_report_t name;\
                               INIT_LIST_HEAD((name).head_service);


mqtt_service_t* mqtt_add_service(mqtt_report_t *mq, const char* service_name,const char* event_time);
mqtt_proprety_t * mqtt_add_proprety(mqtt_report_t *mq, const char* service_name,\
                        const char* proprety_name,en_oc_profile_data_t type,\
                        void* pdata);
void mqtt_reportinfo_print(mqtt_report_t *mq);
void mqtt_report_free(mqtt_report_t *mq);



#ifdef __cplusplus__
}
#endif


#endif 

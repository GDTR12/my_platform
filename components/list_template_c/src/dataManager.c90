#include "dataManager.h"
#include "string.h"

mqtt_service_t* mqtt_add_service(mqtt_report_t *mq, const char* id,const char* event_time)
{        
    mqtt_service_t* service = kmalloc(sizeof(mqtt_service_t));
    CHECK_EQUAL_RETURN(service,NULL,NULL);
    INIT_LIST_HEAD(service->head_proprety);


    service->sev.event_time = event_time;
    service->sev.service_id = id;
    service->sev.nxt = NULL;
    service->sev.service_property = NULL;
    
    list_add_end(&(service->list),&(mq->head_service));
    if(list_get_total(&(mq->head_service)) > 1)
    {
        mqtt_service_t* pre_sev = list_entry(service->list.prev,mqtt_service_t,list);
        pre_sev->sev.nxt = &(service->sev);
    }
    return service;
}

static uint16_t sev_name_equ(xlist_node_t *node,const char* name)
{
    mqtt_service_t* tmp_sev =  list_entry(node,mqtt_service_t,list);
    return !strcmp(tmp_sev->sev.service_id, name);
}

static mqtt_service_t* mq_has_sev(mqtt_report_t *mq, const char* service_name)
{
    list_iter_t iter = list_iter(&(mq->head_service));
    for(; !list_iter_end(&iter); list_iter_next(&iter))
    {
        mqtt_service_t* sev = list_entry(iter.now,mqtt_service_t,list);
        if(!strcmp(sev->sev.service_id, service_name))return sev;
    }
    return NULL;
    
}

mqtt_proprety_t * mqtt_add_proprety(mqtt_report_t *mq, const char* service_name,\
                        const char* proprety_name,en_oc_profile_data_t type,\
                        void* pdata)
{
    mqtt_service_t* service = mq_has_sev(mq,service_name);
    CHECK_EQUAL_RETURN(service, NULL, NULL);
    
    mqtt_proprety_t *pro = kmalloc(sizeof(mqtt_proprety_t));
    CHECK_EQUAL_RETURN(pro,NULL,NULL);
    pro->pro.key = proprety_name;
    pro->pro.nxt = NULL;
    pro->pro.type = type;
    pro->pro.value = pdata;
    list_add_end(&(pro->list), &(service->head_proprety));
    if(list_get_total(&(service->head_proprety)) > 1)
    {
        mqtt_proprety_t* pre_pro = list_entry(pro->list.prev,mqtt_proprety_t,list);
        printf("pre_pro name:%s\n",pre_pro->pro.key);
        pre_pro->pro.nxt = &(pro->pro);
    }else{
        service->sev.service_property = &(pro->pro);
    }
    return pro;
}

static char* const data_int = "int";
static char* const data_long = "long";
static char* const data_float = "float";
static char* const data_double = "double";
static char* const data_string = "string";
static char* data_type[5] = {data_int, data_long, data_float, data_double, data_string};

void mqtt_reportinfo_print(mqtt_report_t *mq)
{
    list_iter_t iter_sev = list_iter(&(mq->head_service));
    printf("========================================================\n");
    for(; !list_iter_end(&iter_sev); list_iter_next(&iter_sev))
    {
        mqtt_service_t* sev = list_entry(iter_sev.now,mqtt_service_t,list);
        printf("%s\n", sev->sev.service_id);

        list_iter_t iter_pro = list_iter(&(sev->head_proprety));
        for(; !list_iter_end(&iter_pro); list_iter_next(&iter_pro))
        {
            mqtt_proprety_t* pro = list_entry(iter_pro.now,mqtt_proprety_t,list);
            printf("  |--%s(name)    %s(type)    ", pro->pro.key, data_type[pro->pro.type]);
            switch (pro->pro.type)
                {
                case EN_OC_MQTT_PROFILE_VALUE_INT:
                    /* code */
                    printf("%d(value)\n", *((int*)pro->pro.value));
                    break;
                case EN_OC_MQTT_PROFILE_VALUE_LONG:
                    /* code */
                    printf("%d(value)\n", *((long*)pro->pro.value));
                    break;
                case EN_OC_MQTT_PROFILE_VALUE_FLOAT:
                    /* code */
                    printf("%.3f(value)\n", *((float*)pro->pro.value));
                    break;
                case EN_OC_MQTT_PROFILE_VALUE_DOUBLE:
                    /* code */
                    printf("%.3f(value)\n", *((double*)pro->pro.value));
                    break;
                case EN_OC_MQTT_PROFILE_VALUE_STRING:
                    /* code */
                    printf("%s(value)\n", (char*)pro->pro.value);
                    break;
                default:
                    break;
                }
        }
    }
    printf("========================================================\n");
}

void mqtt_report_free(mqtt_report_t *mq)
{
    list_iter_t iter_sev = list_reverse_iter(&(mq->head_service));
    for(; !list_reverse_iter_end(&iter_sev); list_reverse_iter_next(&iter_sev))
    {
        mqtt_service_t *sev = list_entry(iter_sev.now, mqtt_service_t, list);
        list_iter_t iter_pro = list_reverse_iter(&(sev->head_proprety));
        for(; !list_reverse_iter_end(&iter_pro); list_reverse_iter_next(&iter_pro))
        {
            mqtt_proprety_t *pro = list_entry(iter_pro.now, mqtt_proprety_t, list);
            kfree(pro);
        }
        kfree(sev);
    }
    return;
}

int mqtt_report_publish(mqtt_report_t *mq)
{
    oc_mqtt_profile_service_t sev;
    list_iter_t iter_sev = list_iter(&(mq->head_service));
    
    for(; !list_iter_end(&iter_sev); list_iter_next(&iter_sev))
    {
        mqtt_service_t* sev_tmp = list_entry(iter_sev.now,mqtt_service_t,list);
        
        list_iter_t iter_pro = list_iter(&(sev_tmp->head_proprety));
        for(; !list_iter_end(&iter_pro); list_iter_next(&iter_pro))
        {
            mqtt_proprety_t* pro_tmp = list_entry(iter_pro.now, mqtt_proprety_t, list);
            
        }
    
    }
}

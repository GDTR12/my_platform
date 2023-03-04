#ifndef MDEFINE_H
#define MDEFINE_H

////< enum all the data type for the oc profile
typedef enum
{
    EN_OC_MQTT_PROFILE_VALUE_INT = 0,
    EN_OC_MQTT_PROFILE_VALUE_LONG,
    EN_OC_MQTT_PROFILE_VALUE_FLOAT,
    EN_OC_MQTT_PROFILE_VALUE_DOUBLE,
    EN_OC_MQTT_PROFILE_VALUE_STRING,           ///< must be ended with '\0'
    EN_OC_MQTT_PROFILE_VALUE_LAST,
}en_oc_profile_data_t;

typedef struct
{
    void                 *nxt;   ///< ponit to the next key
    char                 *key;
    en_oc_profile_data_t  type;
    void                 *value;
}oc_mqtt_profile_kv_t;


typedef struct
{
   void *nxt;
   char *service_id;                         ///< the service id in the profile, which could not be NULL
   char *event_time;                         ///< eventtime, which could be NULL means use the platform time
   oc_mqtt_profile_kv_t *service_property;   ///< the property in the profile, which could not be NULL
}oc_mqtt_profile_service_t;

#endif


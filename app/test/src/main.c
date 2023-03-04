#include "stdio.h"
#include "test.h"
#include "stdlib.h"
#include "list_x.h"
#include "ring_x_queue.h"


//======================== Test List_X=============================
// void to_print(ListX_Node_t* node)
// {
//     printf("node:%d\n",node->data);
// }


// ListX_register_t regfunc={
//     .listX_malloc = malloc,
//     .listX_free = free,
//     .listX_printValue = to_print
// };

// int main()
// {
//     printf("[%s] print.\n", __func__);
//     compent_test();
    
//     ListX_t* lst = listX_new(regfunc);
//     // ListX_Node_t* a0 = listX_insert(lst, 0, 0);
//     // ListX_Node_t* a1 = listX_insert(lst, 1, 1);
//     // ListX_Node_t* a2 = listX_insert(lst, 2, 2);
//     // ListX_Node_t* a3 = listX_insert(lst, 3, 2);
//     // ListX_Node_t* a4 = listX_insert(lst, 4, 2);

//     ListX_Node_t* a0 = listX_append(lst,0);
//     ListX_Node_t* a1 = listX_append(lst,1);
//     ListX_Node_t* a2 = listX_append(lst,2);
//     ListX_Node_t* a3 = listX_append(lst,3);
//     ListX_Node_t* a4 = listX_append(lst,4);
//     listX_print(lst);
//     listX_remove(lst,a0);
//     int b0 = listX_get_index(lst,a0);
//     int b1 = listX_get_index(lst,a1);
//     int b2 = listX_get_index(lst,a2);
//     int b3 = listX_get_index(lst,a3);
//     int b4 = listX_get_index(lst,a4);

//     printf("[0]:%d\n[1]:%d\n[2]:%d\n[3]:%d\n[4]:%d\n",b0,b1,b2,b3,b4);


//     listX_remove(lst,a2);
//     listX_remove(lst,a0);
//     listX_remove(lst,a0);
//     listX_remove(lst,a4);

//     listX_destroy(lst);
//     return 0;
// }

// ======================== Test Ring_X =============================

// int main()
// {
//     Data_Ring_queue_t rq;
//     Ring_Data data[5];
//     frq_init(&rq,data,5);
//     frq_push(&rq,1);
//     frq_push(&rq,2);
//     frq_push(&rq,3);
//     frq_push(&rq,4);
//     frq_push(&rq,5);
//     frq_push(&rq,6);
//     frq_push(&rq,7);
//     frq_push(&rq,8);
//     for(int i = 0; i < 10; i++)
//     {
//         printf("[%d]:%d\n",i, frq_get_byIdx(&rq, i));
//     }
//     // frq_push(&rq,1);
//     // frq_push(&rq,1);
//     // frq_push(&rq,1);
//     return 0;
// }


// ======================== Test printf =============================

// #include "my_printf.h"

// void main()
// {   
//     my_printf("aa%c\n",'c');
//     my_printf("%s\n","afdsf");
//     my_printf("%d\n",123213);
//     my_printf("%x\n",0x234);

//     my_printf("%f\n",2234325344.435345);

// }


// ======================== Test printf =============================

// #include "my_printf.h"

// void main()
// {   
//     my_printf("aa%c\n",'c');
//     my_printf("%s\n","afdsf");
//     my_printf("%d\n",123213);
//     my_printf("%x\n",0x234);

//     my_printf("%f\n",2234325344.435345);
// }


// =========================== Test list =================================

#include "xlist.h"





// int main()
// {
//     // struct list_head head;
//     LIST_NODE(l1);
//     LIST_NODE(l2);
//     LIST_NODE(l3);
//     LIST_NODE(l4);
//     LIST_HEAD(head);


//     xlist_node_t* p = &head;
//     xlist_node_t* p1 = &l1;
//     xlist_node_t* p2 = &l2;
//     xlist_node_t* p3 = &l3;
//     xlist_node_t* p4 = &l4;


//     list_add_end(&l1,&head);
//     list_add_end(&l2,&head);
//     list_add_end(&l3,&head);
//     list_add_end(&l4,&head);
    
//     // printf("%d\n",list_get_idx(&head,&head));
//     // printf("%d\n",list_get_idx(&l1,&head));
//     // printf("%d\n",list_get_idx(&l2,&head));
//     // printf("%d\n",list_get_idx(&l3,&head));
//     // printf("%d\n",list_get_idx(&l4,&head));
//     // printf("%d\n",list_get_total(&head));

//     // list_add_first(&l1,&head);

//     // // printf("%d\n",list_get_total(&head));

//     // list_add_first(&l2,&head);

//     // // printf("%d\n",list_get_total(&head));

//     // list_add_first(&l3,&head);

//     // // printf("%d\n",list_get_total(&head));

//     // list_add_first(&l4,&head);

//     // printf("%d\n",list_get_total(&head));
//     xlist_node_t* p5 = list_get_item(&head, 0);
//     p5 = list_get_item(&head, 1);
//     p5 = list_get_item(&head, 2);
//     p5 = list_get_item(&head, 3);
//     p5 = list_get_item(&head, 4);
//     p5 = list_get_item(&head, 5);




//     // list_remove_end(&head);
//     // list_remove_end(&head);
//     // list_remove_end(&head);
//     // list_remove_end(&head);
//     // printf("%d\n",list_get_idx(&head,&head));
//     // printf("%d\n",list_get_idx(&l1,&head));
//     // printf("%d\n",list_get_idx(&l2,&head));
//     // printf("%d\n",list_get_idx(&l3,&head));
//     // printf("%d\n",list_get_idx(&l4,&head));
    

    

//     list_remove_first(&head);
//     // printf("%d\n",list_get_total(&head));
//     list_remove_first(&head);
//     // printf("%d\n",list_get_total(&head));
//     list_remove_first(&head);
//     // printf("%d\n",list_get_total(&head));
//     list_remove_first(&head);
//     // printf("%d\n",list_get_total(&head));
    

//     // printf("%d\n",p);
    
//     // for(p = p->next; p != &head; p = p->next)
//     // {
//     //     printf("%d\n",p);
//     // }
// }

// struct xlist_test
// {
//     uint32_t data;
//     xlist_node_t list;
// };

// typedef struct{
//     uint8_t byte[3];
// }Chinese_t;



// int main()
// {
//     struct xlist_test t1;
//     struct xlist_test t2;
//     struct xlist_test t3;
//     struct xlist_test t4;
    
//     t1.data = 0;
//     t2.data = 1;
//     t3.data = 2;
//     t4.data = 3;

// 	xlist_node_t *p0 = &t1.list;
//     INIT_LIST_HEAD(t1.list);
//     INIT_LIST_NODE(t2.list);
//     INIT_LIST_NODE(t3.list);
//     INIT_LIST_NODE(t4.list);

//     list_add_end(&(t2.list),&(t1.list));
//     list_add_end(&(t3.list),&(t1.list));
//     list_add_end(&(t4.list),&(t1.list));

//     struct xlist_test *p = list_entry(list_get_item(&(t1.list), 0),struct xlist_test,list);
//     p = list_entry(list_get_item(&(t1.list), 1),struct xlist_test,list);
//     p = list_entry(list_get_item(&(t1.list), 2),struct xlist_test,list);
//     p = list_entry(list_get_item(&(t1.list), 3),struct xlist_test,list);




    // char data[10] = "你好";
    // for(int i = 0;i < 10;i++)
    // printf("%d\n",data[i]);
    // #include "dataManager.h"
    // static mqtt_report_t repo;
    // INIT_LIST_HEAD(repo.head_service);

    // mqtt_add_service(&repo,"IMU", NULL);
    // mqtt_add_service(&repo,"HeartBlood", NULL);
    // mqtt_add_service(&repo,"GPS", NULL);
    // int dataint = 8;
    // float datafloat = 345.6;
    // char datastring[20] = "data";

    // mqtt_add_proprety(&repo,"IMU","coord_x",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);
    // mqtt_add_proprety(&repo,"IMU","coord_y",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);
    // mqtt_add_proprety(&repo,"IMU","coord_z",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);
    // mqtt_add_proprety(&repo,"IMU","times_fall_down",EN_OC_MQTT_PROFILE_VALUE_INT,&dataint);
    // mqtt_add_proprety(&repo,"IMU","step_counting",EN_OC_MQTT_PROFILE_VALUE_INT,&dataint);
    

    // mqtt_add_proprety(&repo,"HeartBlood","heart_rate",EN_OC_MQTT_PROFILE_VALUE_INT,&dataint);
    // mqtt_add_proprety(&repo,"HeartBlood","bloot_oxygen",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);
    // mqtt_add_proprety(&repo,"HeartBlood","health_index",EN_OC_MQTT_PROFILE_VALUE_INT,&dataint);

    // mqtt_add_proprety(&repo,"GPS","longitude",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);
    // mqtt_add_proprety(&repo,"GPS","latitude",EN_OC_MQTT_PROFILE_VALUE_FLOAT,&datafloat);

    // mqtt_reportinfo_print(&repo);

    // xlist_node_t *first_sev = repo.head_service.next;
    // mqtt_service_t* first = list_entry(first_sev,mqtt_service_t,list);
    // oc_mqtt_profile_service_t *service = &(first->sev);
    // oc_mqtt_profile_service_t *tmp = service;
    // for(;tmp != NULL; tmp = tmp->nxt)
    // {
    //     oc_mqtt_profile_kv_t *tmp2 = tmp->service_property;
    //     printf("service name:   %s\n",tmp->service_id);
    //     for(;tmp2 != NULL; tmp2 = tmp2->nxt)
    //     {
    //         printf("    proprety name:   %s\n",tmp2->key);
    //     }
    // }
    
    // mqtt_report_free(&repo);

   // 再次创建qmtt_report
    
// }




// =========================== Test CJson =================================
#include "cJSON.h"

/*

data1

{"status":0,"result":{"location":{"lng":121.50989077799084,"lat":31.22932842411674},"formatted_address":"上海市黄浦区中山南路187","business":"外滩,陆家嘴,董家渡","addressComponent":{"country":"中国","country_code":0,"country_code_iso":"CHN","country_code_iso2":"CN","province":"上海市","city":"上海市","city_level":2,"district":"黄浦区","town":"","town_code":"","distance":"91","direction":"东北","adcode":"310101","street":"中山南路","street_number":"187"},"pois":[],"roads":[],"poiRegions":[],"sematic_description":"","cityCode":289}}

{
	"status": 0,
	"result": {
		"location": {
			"lng": 121.50989077799084,
			"lat": 31.22932842411674
		},
		"formatted_address": "上海市黄浦区中山南路187",
		"business": "外滩,陆家嘴,董家渡",
		"addressComponent": {
			"country": "中国",
			"country_code": 0,
			"country_code_iso": "CHN",
			"country_code_iso2": "CN",
			"province": "上海市",
			"city": "上海市",
			"city_level": 2,
			"district": "黄浦区",
			"town": "",
			"town_code": "",
			"distance": "91",
			"direction": "东北",
			"adcode": "310101",
			"street": "中山南路",
			"street_number": "187"
		},
		"pois": [],
		"roads": [],
		"poiRegions": [],
		"sematic_description": "",
		"cityCode": 289
	}
}




*/

// typedef struct{
//     cJSON *root;
//     cJSON *status;
//     cJSON *result;
//     cJSON *formatted_address;
//     cJSON *business;
//     cJSON *addressComponent;
//     cJSON *adcode;
// }location_t;



// int main()
// {
//     cJSON_Hooks hooks;
//     hooks.free_fn = free;
//     hooks.malloc_fn = malloc;
//     cJSON_InitHooks(&hooks);
    
//     char loc_data[] = "{\"status\":0,\"result\":{\"location\":{\"lng\":121.50989077799084,\"lat\":31.22932842411674},\"formatted_address\":\"上海市黄浦区中山南路187\",\"business\":\"外滩,陆家嘴,董家渡\",\"addressComponent\":{\"country\":\"中国\",\"country_code\":0,\"country_code_iso\":\"CHN\",\"country_code_iso2\":\"CN\",\"province\":\"上海市\",\"city\":\"上海市\",\"city_level\":2,\"district\":\"黄浦区\",\"town\":\"\",\"town_code\":\"\",\"distance\":\"91\",\"direction\":\"东北\",\"adcode\":\"310101\",\"street\":\"中山南路\",\"street_number\":\"187\"},\"pois\":[],\"roads\":[],\"poiRegions\":[],\"sematic_description\":\"\",\"cityCode\":289}}";
//     printf("data length: %d\n",strlen(loc_data));
//     location_t loc;
//     loc.root = cJSON_Parse(loc_data);
//     loc.status = cJSON_GetObjectItem(loc.root,"status");
//     printf("status: %d\n",loc.status->valueint);
//     if(loc.status->valueint != 0)return -1;
//     loc.result = cJSON_GetObjectItem(loc.root,"result");
//     if(loc.result == NULL)return -1;
//     loc.formatted_address = cJSON_GetObjectItem(loc.result,"formatted_address");
//     loc.business = cJSON_GetObjectItem(loc.result,"business");
//     loc.addressComponent = cJSON_GetObjectItem(loc.result,"addressComponent");
//     if(loc.addressComponent == NULL) return -1;

//     loc.adcode = cJSON_GetObjectItem(loc.addressComponent,"adcode");

    
//     printf("formatted_address:%s\n",loc.formatted_address->valuestring);
//     printf("business:%s\n",loc.business->valuestring);
//     printf("adcode:%s\n",loc.adcode->valuestring);
    
//     cJSON_Delete(loc.root);


// /*
// {"status":0,"result":{"location":{"country":"中国","province":"上海市","city":"上海市","name":"黄浦","id":"310101"},"now":{"text":"多云","temp":6,"feels_like":5,"rh":54,"wind_class":"1级","wind_dir":"西北风","uptime":"20230214124500"},"forecasts":[{"text_day":"多云","text_night":"多云","high":7,"low":2,"wc_day":"<3级","wd_day":"北风","wc_night":"<3级","wd_night":"西北风","date":"2023-02-14","week":"星期二"},{"text_day":"晴","text_night":"晴","high":8,"low":1,"wc_day":"<3级","wd_day":"北风","wc_night":"<3级","wd_night":"东北风","date":"2023-02-15","week":"星期三"},{"text_day":"晴","text_night":"多云","high":10,"low":5,"wc_day":"<3级","wd_day":"东风","wc_night":"<3级","wd_night":"东南风","date":"2023-02-16","week":"星期四"},{"text_day":"阴","text_night":"阴","high":14,"low":8,"wc_day":"<3级","wd_day":"南风","wc_night":"<3级","wd_night":"南风","date":"2023-02-17","week":"星期五"},{"text_day":"阴","text_night":"阴","high":19,"low":8,"wc_day":"<3级","wd_day":"北风","wc_night":"<3级","wd_night":"北风","date":"2023-02-18","week":"星期六"}]},"message":"success"}

// {
// 	"status": 0,
// 	"result": {
// 		"location": {
// 			"country": "中国",
// 			"province": "上海市",
// 			"city": "上海市",
// 			"name": "黄浦",
// 			"id": "310101"
// 		},
// 		"now": {
// 			"text": "多云",
// 			"temp": 6,
// 			"feels_like": 5,
// 			"rh": 54,
// 			"wind_class": "1级",
// 			"wind_dir": "西北风",
// 			"uptime": "20230214124500"
// 		},
// 		"forecasts": [{
// 			"text_day": "多云",
// 			"text_night": "多云",
// 			"high": 7,
// 			"low": 2,
// 			"wc_day": "<3级",
// 			"wd_day": "北风",
// 			"wc_night": "<3级",
// 			"wd_night": "西北风",
// 			"date": "2023-02-14",
// 			"week": "星期二"
// 		}, {
// 			"text_day": "晴",
// 			"text_night": "晴",
// 			"high": 8,
// 			"low": 1,
// 			"wc_day": "<3级",
// 			"wd_day": "北风",
// 			"wc_night": "<3级",
// 			"wd_night": "东北风",
// 			"date": "2023-02-15",
// 			"week": "星期三"
// 		}, {
// 			"text_day": "晴",
// 			"text_night": "多云",
// 			"high": 10,
// 			"low": 5,
// 			"wc_day": "<3级",
// 			"wd_day": "东风",
// 			"wc_night": "<3级",
// 			"wd_night": "东南风",
// 			"date": "2023-02-16",
// 			"week": "星期四"
// 		}, {
// 			"text_day": "阴",
// 			"text_night": "阴",
// 			"high": 14,
// 			"low": 8,
// 			"wc_day": "<3级",
// 			"wd_day": "南风",
// 			"wc_night": "<3级",
// 			"wd_night": "南风",
// 			"date": "2023-02-17",
// 			"week": "星期五"
// 		}, {
// 			"text_day": "阴",
// 			"text_night": "阴",
// 			"high": 19,
// 			"low": 8,
// 			"wc_day": "<3级",
// 			"wd_day": "北风",
// 			"wc_night": "<3级",
// 			"wd_night": "北风",
// 			"date": "2023-02-18",
// 			"week": "星期六"
// 		}]
// 	},
// 	"message": "success"
// }


// */
//     typedef struct{
//         cJSON *root;
//         cJSON *status;
//         cJSON *result;
//         cJSON *now;
//         cJSON *forecasts;

//     }weather_t;

//     char wea_data[] = "{\"status\":0,\"result\":{\"location\":{\"country\":\"中国\",\"province\":\"上海市\",\"city\":\"上海市\",\"name\":\"黄浦\",\"id\":\"310101\"},\"now\":{\"text\":\"多云\",\"temp\":6,\"feels_like\":5,\"rh\":54,\"wind_class\":\"1级\",\"wind_dir\":\"西北风\",\"uptime\":\"20230214124500\"},\"forecasts\":[{\"text_day\":\"多云\",\"text_night\":\"多云\",\"high\":7,\"low\":2,\"wc_day\":\"<3级\",\"wd_day\":\"北风\",\"wc_night\":\"<3级\",\"wd_night\":\"西北风\",\"date\":\"2023-02-14\",\"week\":\"星期二\"},{\"text_day\":\"晴\",\"text_night\":\"晴\",\"high\":8,\"low\":1,\"wc_day\":\"<3级\",\"wd_day\":\"北风\",\"wc_night\":\"<3级\",\"wd_night\":\"东北风\",\"date\":\"2023-02-15\",\"week\":\"星期三\"},{\"text_day\":\"晴\",\"text_night\":\"多云\",\"high\":10,\"low\":5,\"wc_day\":\"<3级\",\"wd_day\":\"东风\",\"wc_night\":\"<3级\",\"wd_night\":\"东南风\",\"date\":\"2023-02-16\",\"week\":\"星期四\"},{\"text_day\":\"阴\",\"text_night\":\"阴\",\"high\":14,\"low\":8,\"wc_day\":\"<3级\",\"wd_day\":\"南风\",\"wc_night\":\"<3级\",\"wd_night\":\"南风\",\"date\":\"2023-02-17\",\"week\":\"星期五\"},{\"text_day\":\"阴\",\"text_night\":\"阴\",\"high\":19,\"low\":8,\"wc_day\":\"<3级\",\"wd_day\":\"北风\",\"wc_night\":\"<3级\",\"wd_night\":\"北风\",\"date\":\"2023-02-18\",\"week\":\"星期六\"}]},\"message\":\"success\"}";
//     printf("\n===========================================================\n");
//     printf("json length: %d\n",strlen(wea_data));
//     weather_t wea;
//     wea.root = cJSON_Parse(wea_data);
//     wea.status = cJSON_GetObjectItem(wea.root,"status");
//     printf("status: %d\n",wea.status->valueint);
//     if(wea.status->valueint != 0)return -1;
//     wea.result = cJSON_GetObjectItem(wea.root,"result");
//     if(wea.result == NULL)return -1;

//     wea.now = cJSON_GetObjectItem(wea.result,"now");

//     char forecaset[1500];
//     memset(forecaset,0,sizeof(forecaset));
//     cJSON *text = cJSON_GetObjectItem(wea.now,"text");
//     cJSON *temp = cJSON_GetObjectItem(wea.now,"temp");
//     cJSON *feels_like = cJSON_GetObjectItem(wea.now,"feels_like");
//     cJSON *rh = cJSON_GetObjectItem(wea.now,"rh");
//     cJSON *wind_class = cJSON_GetObjectItem(wea.now,"wind_class");
//     cJSON *wind_dir = cJSON_GetObjectItem(wea.now,"wind_dir");

//     char tmp[20];
//     sprintf(forecaset,"现在: %s", cJSON_GetStringValue(text));
    
//     sprintf(tmp,"温度: %d   ", temp->valueint);
//     strcat(forecaset,tmp);
//     sprintf(tmp,"体感温度: %d   ", temp->valueint);
//     strcat(forecaset,tmp);
//     sprintf(tmp,"相对湿度: %d   ", rh->valueint);
//     strcat(forecaset,tmp);
//     sprintf(tmp,"风力: %s   ", cJSON_GetStringValue(wind_class));
//     strcat(forecaset,tmp);
//     sprintf(tmp,"风向: %d\n", cJSON_GetStringValue(wind_dir));
//     strcat(forecaset,tmp);

//     wea.forecasts = cJSON_GetObjectItem(wea.result,"forecasts");

//     for(int i = 0;i < 5; i++)
//     {

//         cJSON *text_day = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"text_day");
//         cJSON *text_night = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"text_night");
//         cJSON *high = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"high");
//         cJSON *low = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"low");
//         cJSON *wc_day = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"wc_day");
//         cJSON *wd_day = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"wd_day");
//         cJSON *wc_night = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"wc_night");
//         cJSON *wd_night = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"wd_night");
//         cJSON *date = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"date");
//         cJSON *week = cJSON_GetObjectItem(cJSON_GetArrayItem(wea.forecasts,i),"week");
        
//         sprintf(tmp,"日期: %s  ", cJSON_GetStringValue(date));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"星期: %s\n", cJSON_GetStringValue(week));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    白天: %s\n", cJSON_GetStringValue(text_day));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    晚上: %s\n", cJSON_GetStringValue(text_night));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    最高气温: %d\n", high->valueint);
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    最低气温: %d\n", low->valueint);
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    白天风力: %s\n", cJSON_GetStringValue(wc_day));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    白天风向: %s\n", cJSON_GetStringValue(wd_day));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    夜间风力: %s\n", cJSON_GetStringValue(wc_night));
//         strcat(forecaset,tmp);
//         sprintf(tmp,"    夜间风向: %s\n", cJSON_GetStringValue(wd_night));
//         strcat(forecaset,tmp);
//     }

//     printf("forecast length: %d\nforecast:\n%s\n",strlen(forecaset),forecaset);
//     cJSON_Delete(wea.root);
// #define LINK_LOG_ERROR(format) printf("%s",format)
// 	char receiveBuf[] = "{\"status\":\"1\",\"regeocode\":{\"addressComponent\":{\"city\":[],\"province\":\"[?:e4]浸�海市\",\"adcode\":\"310101\",\"district\":\"黄浦区\",\"towncode\":\"310101015000\",\"streetNumber\":{\"number\":\"1820号\",\"location\":\"121.490543,31.202507\",\"direction\":\"东北\",\"distance\":\"15.2493\",\"street\":\"中山南[?:e8]��\"},\"country\":\"中国\",\"township\":\"半淞园[?:e8]衷�街道\",\"businessAreas\":[{\"location\":\"121.479925,31.198367\",\"name\":\"五里桥\",\"id\":\"310101\"}],\"building\":{\"name\":\"德高青[?:e5]儰�儿英语\",\"type\":\"科教文化[?:e6]劜�务;培训机构;培[?:e8]朮�机构\"},\"neighborhood\":{\"name\":\"弘辉名苑(西藏南[?:e8]��)\",\"type\":\"商务住[?:e5]䮅;住宅区;住宅小[?:e5]��\"},\"citycode\":\"021\"},\"formatted_address\":\"上海市黄[?:e6]匵�区半淞[?:e5]跛�路街道德高青少儿英语弘辉名苑\"},\"info\":\"OK\",\"infocode\":\"10000\"}";
// 	cJSON* root = cJSON_Parse(receiveBuf);
// 	if(root == NULL){
// 		LINK_LOG_ERROR("No data received!");
// 		goto ret;
// 	}
// 	cJSON* regeocode = cJSON_GetObjectItem(root,"regeocode");
// 	if(NULL == regeocode){
// 		LINK_LOG_ERROR("No regeocode received!");
// 		goto ret;
// 	}
// 	cJSON* formatted_address = cJSON_GetObjectItem(regeocode,"formatted_address");
// 	if(NULL == formatted_address){
// 		LINK_LOG_ERROR("No formatted_address received!");
// 		goto ret;
// 	}
// 	cJSON* addressComponent = cJSON_GetObjectItem(regeocode,"addressComponent");
// 	if(NULL == addressComponent){
// 		LINK_LOG_ERROR("No addressComponent received!");
// 		goto ret;
// 	}
// 	cJSON* adcode = cJSON_GetObjectItem(addressComponent,"adcode");
// 	if(NULL == adcode){
// 		LINK_LOG_ERROR("No adcode received!");
// 		goto ret;
// 	}

// 	// strcpy(loc->adcode,adcode->valuestring);
// 	// strcpy(loc->location, formatted_address->valuestring);
// 	printf("location:%s\n",formatted_address->valuestring);
// 	printf("adcode:%s\n",adcode->valuestring);
// 	cJSON_Delete(root);
// 	printf("=========================================================================================\n");
// 	return 0;
// ret:
// 	cJSON_Delete(root);
// 	printf("=========================================================================================\n");
// 	return -1;

// }


int main()
{
    char data[3];
    chinese_font_map("天气",data);
    printf("%d\n",data[0]);
    printf("%d\n",data[1]);
}

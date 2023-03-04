#ifndef XUI_H
#define XUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tlsf.h"
#include "xui_config.h"
#include "stdint.h"

typedef void* xui_obj_img_t;


typedef enum{
    XUI_SCROLL_HORIZON = 1 << 0,
    XUI_SCROLL_VERTICAL = 1 << 1,
    XUI_SCROLL_BOTH = 3,
}xui_scroll_flat_t;

typedef uint16_t xui_color_t;
#define xui_frame_data_t(px)    uint16_t top_px;\
                                uint16_t left_px;\
                                uint16_t bottom_px;\
                                uint16_t right_px;\
                                xui_color_t color;
typedef struct{
    xui_frame_data_t(5);
}xui_outline_t;

typedef struct{
    xui_frame_data_t(20);
}xui_padding_t;

typedef struct{
    xui_frame_data_t(5);
}xui_border_t;

typedef struct 
{
    xui_obj_img_t bg_img;
    xui_outline_t outline;
    xui_border_t border;
    xui_padding_t padding;
    
}xui_style_t;

typedef struct xui_attr
{
    uint8_t xui_attr_opa;       // range: (0, 100)[%]
    
    uint16_t xui_attr_frame_visiable_mode;       // 0X0f00: paddinng 0X00f0:border 0X000f:outline
}xui_attr_t;



enum {
    XUI_STATE_DEFAULT     =  0x0000,
    XUI_STATE_CHECKED     =  0x0001,
    XUI_STATE_FOCUSED     =  0x0002,
    XUI_STATE_FOCUS_KEY   =  0x0004,
    XUI_STATE_EDITED      =  0x0008,
    XUI_STATE_HOVERED     =  0x0010,
    XUI_STATE_PRESSED     =  0x0020,
    XUI_STATE_SCROLLED    =  0x0040,
    XUI_STATE_DISABLED    =  0x0080,

    XUI_STATE_USER_1      =  0x1000,
    XUI_STATE_USER_2      =  0x2000,
    XUI_STATE_USER_3      =  0x4000,
    XUI_STATE_USER_4      =  0x8000,

    XUI_STATE_ANY = 0xFFFF,   
};

typedef uint16_t xui_state_t;


/**
 * On/Off features controlling the object's behavior.
 * OR-ed values are possible
 */
enum {
    XUI_OBJ_FLAG_HIDDEN          = (1L << 0),  /**< Make the object hidden. (Like it wasn't there at all)*/
    XUI_OBJ_FLAG_CLICKABLE       = (1L << 1),  /**< Make the object clickable by the input devices*/
    XUI_OBJ_FLAG_CLICK_FOCUSABLE = (1L << 2),  /**< Add focused state to the object when clicked*/
    XUI_OBJ_FLAG_CHECKABLE       = (1L << 3),  /**< Toggle checked state when the object is clicked*/
    XUI_OBJ_FLAG_SCROLLABLE      = (1L << 4),  /**< Make the object scrollable*/
    XUI_OBJ_FLAG_SCROLL_ELASTIC  = (1L << 5),  /**< Allow scrolling inside but with slower speed*/
    XUI_OBJ_FLAG_SCROLL_MOMENTUM = (1L << 6),  /**< Make the object scroll further when "thrown"*/
    XUI_OBJ_FLAG_SCROLL_ONE      = (1L << 7),  /**< Allow scrolling only one snappable children*/
    XUI_OBJ_FLAG_SCROLL_CHAIN_HOR = (1L << 8), /**< Allow propagating the horizontal scroll to a parent*/
    XUI_OBJ_FLAG_SCROLL_CHAIN_VER = (1L << 9), /**< Allow propagating the vertical scroll to a parent*/
    XUI_OBJ_FLAG_SCROLL_CHAIN     = (XUI_OBJ_FLAG_SCROLL_CHAIN_HOR | XUI_OBJ_FLAG_SCROLL_CHAIN_VER),
    XUI_OBJ_FLAG_SCROLL_ON_FOCUS = (1L << 10),  /**< Automatically scroll object to make it visible when focused*/
    XUI_OBJ_FLAG_SCROLL_WITH_ARROW  = (1L << 11), /**< Allow scrolling the focused object with arrow keys*/
    XUI_OBJ_FLAG_SNAPPABLE       = (1L << 12), /**< If scroll snap is enabled on the parent it can snap to this object*/
    XUI_OBJ_FLAG_PRESS_LOCK      = (1L << 13), /**< Keep the object pressed even if the press slid from the object*/
    XUI_OBJ_FLAG_EVENT_BUBBLE    = (1L << 14), /**< Propagate the events to the parent too*/
    XUI_OBJ_FLAG_GESTURE_BUBBLE  = (1L << 15), /**< Propagate the gestures to the parent*/
    XUI_OBJ_FLAG_ADV_HITTEST     = (1L << 16), /**< Allow performing more accurate hit (click) test. E.g. consider rounded corners.*/
    XUI_OBJ_FLAG_IGNORE_LAYOUT   = (1L << 17), /**< Make the object position-able by the layouts*/
    XUI_OBJ_FLAG_FLOATING        = (1L << 18), /**< Do not scroll the object when the parent scrolls and ignore layout*/
    XUI_OBJ_FLAG_OVERFLOW_VISIBLE = (1L << 19), /**< Do not clip the children's content to the parent's boundary*/

    XUI_OBJ_FLAG_LAYOUT_1        = (1L << 23), /**< Custom flag, free to use by layouts*/
    XUI_OBJ_FLAG_LAYOUT_2        = (1L << 24), /**< Custom flag, free to use by layouts*/

    XUI_OBJ_FLAG_WIDGET_1        = (1L << 25), /**< Custom flag, free to use by widget*/
    XUI_OBJ_FLAG_WIDGET_2        = (1L << 26), /**< Custom flag, free to use by widget*/
    XUI_OBJ_FLAG_USER_1          = (1L << 27), /**< Custom flag, free to use by user*/
    XUI_OBJ_FLAG_USER_2          = (1L << 28), /**< Custom flag, free to use by user*/
    XUI_OBJ_FLAG_USER_3          = (1L << 29), /**< Custom flag, free to use by user*/
    XUI_OBJ_FLAG_USER_4          = (1L << 30), /**< Custom flag, free to use by user*/

};


typedef uint32_t xui_obj_flag_t;

typedef struct xui_obj{
    uint16_t x, y;
    uint16_t weight : 10 ,height : 10;

    xui_style_t style;
    xui_attr_t attr;
    xui_obj_flag_t flag;
    xui_state_t state;
    struct xui_obj* child;
    struct xui_obj* parent;
}xui_obj_t;




#ifdef __cplusplus
}
#endif

#endif

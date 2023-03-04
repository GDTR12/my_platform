#include "xui_tick.h"

static uint32_t xui_systick = 0;

void xui_tick_inc(uint16_t period)
{
    xui_systick += period;
}

uint32_t xui_systick_get()
{
    return xui_systick;
}


uint32_t xui_systick_elaps(uint32_t prev_tick)
{
    if(prev_tick <= xui_systick)return xui_systick - prev_tick;
    else return 0;
}




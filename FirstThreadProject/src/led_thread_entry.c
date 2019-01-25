#include "led_thread.h"

void led_thread_entry(void);

bsp_leds_t LEDS;

/* LED Thread entry function */
void led_thread_entry(void)
{
    /* TODO: add your own code here */

    ioport_level_t led_level = IOPORT_LEVEL_HIGH;

    R_BSP_LedsGet(&LEDS);

    g_external_irq11.p_api->open(g_external_irq11.p_ctrl,g_external_irq11.p_cfg);

    while (1)
    {
        g_ioport.p_api->pinWrite(LEDS.p_leds[BSP_LED_LED1],led_level);
        if(led_level == IOPORT_LEVEL_HIGH)
        {
            led_level = IOPORT_LEVEL_LOW;
        }
        else
        {
            led_level = IOPORT_LEVEL_HIGH;
        }
        tx_semaphore_get(&g_sw4_semaphore, TX_WAIT_FOREVER);

    }
}

void external_irq11_callback(external_irq_callback_args_t * p_args)
{
    tx_semaphore_put(&g_sw4_semaphore);
}

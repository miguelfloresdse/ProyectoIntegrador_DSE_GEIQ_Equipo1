#include "led_thread.h"

void led_thread_entry(void);

bsp_leds_t LEDS;
ssp_err_t status;

/* LED Thread entry function */
void led_thread_entry(void)
{
    /* TODO: add your own code here */

    ioport_level_t led_level = IOPORT_LEVEL_LOW;

    R_BSP_LedsGet(&LEDS);

    //g_external_irq11.p_api->open(g_external_irq11.p_ctrl,g_external_irq11.p_cfg);
    //g_external_irq10.p_api->open(g_external_irq10.p_ctrl,g_external_irq10.p_cfg);

    while (1)
    {

        status = g_external_irq11.p_api->open(g_external_irq11.p_ctrl,g_external_irq11.p_cfg);

        if (SSP_SUCCESS == status)
                {
                    tx_semaphore_get(&g_sw4_semaphore, TX_WAIT_FOREVER);
                    g_ioport.p_api->pinWrite(LEDS.p_leds[BSP_LED_LED1],led_level);

                    if(led_level == IOPORT_LEVEL_LOW)
                       {
                           led_level = IOPORT_LEVEL_HIGH;
                       }
                    else
                    {
                        led_level = IOPORT_LEVEL_HIGH;
                    }
                    g_external_irq11.p_api->close(g_external_irq11.p_ctrl);
                }

        status = g_external_irq10.p_api->open(g_external_irq10.p_ctrl,g_external_irq10.p_cfg);

                if (SSP_SUCCESS == status)
                        {
                            tx_semaphore_get(&g_sw5_semaphore, TX_WAIT_FOREVER);
                            g_ioport.p_api->pinWrite(LEDS.p_leds[BSP_LED_LED1],led_level);

                            if(led_level == IOPORT_LEVEL_HIGH)
                               {
                                   led_level = IOPORT_LEVEL_LOW;
                               }
                            else
                               {
                                   led_level = IOPORT_LEVEL_LOW;
                               }
                            g_external_irq10.p_api->close(g_external_irq10.p_ctrl);
                        }

    }
}

void external_irq11_callback(external_irq_callback_args_t * p_args)
{
    tx_semaphore_put(&g_sw4_semaphore);
}

void external_irq10_callback(external_irq_callback_args_t * p_args)
{
    tx_semaphore_put(&g_sw5_semaphore);
}

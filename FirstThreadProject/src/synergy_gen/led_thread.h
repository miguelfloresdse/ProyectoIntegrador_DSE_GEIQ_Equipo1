/* generated thread header file - do not edit */
#ifndef LED_THREAD_H_
#define LED_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void led_thread_entry(void);
#else 
extern void led_thread_entry(void);
#endif
#include "r_icu.h"
#include "r_external_irq_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq11;
#ifndef external_irq11_callback
void external_irq11_callback(external_irq_callback_args_t * p_args);
#endif
extern TX_SEMAPHORE g_sw4_semaphore;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* LED_THREAD_H_ */

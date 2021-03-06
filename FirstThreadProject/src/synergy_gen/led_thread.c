/* generated thread source file - do not edit */
#include "led_thread.h"

TX_THREAD led_thread;
void led_thread_create(void);
static void led_thread_func(ULONG thread_input);
/** Alignment requires using pragma for IAR. GCC is done through attribute. */
#if defined(__ICCARM__)
#pragma data_alignment = BSP_STACK_ALIGNMENT
#endif
static uint8_t led_thread_stack[1024] BSP_PLACE_IN_SECTION(".stack.led_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
#if (8) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq11) && !defined(SSP_SUPPRESS_ISR_ICU11)
SSP_VECTOR_DEFINE( icu_irq_isr, ICU, IRQ11);
#endif
#endif
static icu_instance_ctrl_t g_external_irq11_ctrl;
static const external_irq_cfg_t g_external_irq11_cfg =
{ .channel = 11, .trigger = EXTERNAL_IRQ_TRIG_FALLING, .filter_enable = true, .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true, .p_callback = external_irq11_callback, .p_context = &g_external_irq11, .p_extend = NULL, .irq_ipl =
          (8), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq11 =
{ .p_ctrl = &g_external_irq11_ctrl, .p_cfg = &g_external_irq11_cfg, .p_api = &g_external_irq_on_icu };
TX_SEMAPHORE g_sw4_semaphore;
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;
void g_hal_init(void);

void led_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    tx_semaphore_create (&g_sw4_semaphore, (CHAR *) "SW4 Semaphore", 0);

    tx_thread_create (&led_thread, (CHAR *) "LED Thread", led_thread_func, (ULONG) NULL, &led_thread_stack, 1024, 1, 1,
                      1, TX_AUTO_START);
}

static void led_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* First thread will take care of common initialization. */
    UINT err;
    err = tx_semaphore_get (&g_ssp_common_initialized_semaphore, TX_WAIT_FOREVER);

    while (TX_SUCCESS != err)
    {
        /* Check err, problem occurred. */
        BSP_CFG_HANDLE_UNRECOVERABLE_ERROR (0);
    }

    /* Only perform common initialization if this is the first thread to execute. */
    if (false == g_ssp_common_initialized)
    {
        /* Later threads will not run this code. */
        g_ssp_common_initialized = true;

        /* Perform common module initialization. */
        g_hal_init ();

        /* Now that common initialization is done, let other threads through. */
        /* First decrement by 1 since 1 thread has already come through. */
        g_ssp_common_thread_count--;
        while (g_ssp_common_thread_count > 0)
        {
            err = tx_semaphore_put (&g_ssp_common_initialized_semaphore);

            while (TX_SUCCESS != err)
            {
                /* Check err, problem occurred. */
                BSP_CFG_HANDLE_UNRECOVERABLE_ERROR (0);
            }

            g_ssp_common_thread_count--;
        }
    }

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    led_thread_entry ();
}

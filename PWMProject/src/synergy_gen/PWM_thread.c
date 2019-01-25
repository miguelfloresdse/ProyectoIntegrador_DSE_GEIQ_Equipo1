/* generated thread source file - do not edit */
#include "PWM_thread.h"

TX_THREAD PWM_thread;
void PWM_thread_create(void);
static void PWM_thread_func(ULONG thread_input);
/** Alignment requires using pragma for IAR. GCC is done through attribute. */
#if defined(__ICCARM__)
#pragma data_alignment = BSP_STACK_ALIGNMENT
#endif
static uint8_t PWM_thread_stack[1024] BSP_PLACE_IN_SECTION(".stack.PWM_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;
void g_hal_init(void);

void PWM_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    tx_thread_create (&PWM_thread, (CHAR *) "LED Thread", PWM_thread_func, (ULONG) NULL, &PWM_thread_stack, 1024, 10,
                      10, 1, TX_AUTO_START);
}

static void PWM_thread_func(ULONG thread_input)
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
    PWM_thread_entry ();
}

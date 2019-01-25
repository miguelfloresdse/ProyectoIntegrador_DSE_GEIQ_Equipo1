#include "PWM_thread.h"

#define CLOCK_A         0
  #define CLOCK_B         1

  /* LED Control entry function */
  void PWM_thread_entry(void)
  {
       //open timer object
       g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);

       //Change Duty cycle around 30% i.e. overriding properties
       g_timer0.p_api->dutyCycleSet(g_timer0.p_ctrl, (30 %100), TIMER_PWM_UNIT_PERCENT, CLOCK_B);

       //start the timer which will product PWM
       g_timer0.p_api->start(g_timer0.p_ctrl);

      uint8_t dutycycle = 0;
      while (1) {
            tx_thread_sleep (150);
            dutycycle = (dutycycle  + 5) % 100; // Every iteration change Duty Cycle 5% more
            g_timer0.p_api->dutyCycleSet(g_timer0.p_ctrl, dutycycle, TIMER_PWM_UNIT_PERCENT, CLOCK_B);
      }
}

/* generated HAL source file - do not edit */
#include "hal_data.h"
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer1) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI3_RXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI3_RXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer1_ctrl;
transfer_info_t g_transfer1_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED, .repeat_area = TRANSFER_REPEAT_AREA_DESTINATION, .irq =
          TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, .size = TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL, .p_dest = (void *) NULL, .p_src = (void const *) NULL, .num_blocks = 0, .length = 0, };
const transfer_cfg_t g_transfer1_cfg =
{ .p_info = &g_transfer1_info, .activation_source = ELC_EVENT_SCI3_RXI, .auto_enable = false, .p_callback = NULL,
  .p_context = &g_transfer1, .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 =
{ .p_ctrl = &g_transfer1_ctrl, .p_cfg = &g_transfer1_cfg, .p_api = &g_transfer_on_dtc };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer0) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI3_TXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI3_TXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer0_ctrl;
transfer_info_t g_transfer0_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED, .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, .irq = TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED, .size =
          TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL, .p_dest = (void *) NULL, .p_src = (void const *) NULL, .num_blocks = 0, .length = 0, };
const transfer_cfg_t g_transfer0_cfg =
{ .p_info = &g_transfer0_info, .activation_source = ELC_EVENT_SCI3_TXI, .auto_enable = false, .p_callback = NULL,
  .p_context = &g_transfer0, .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 =
{ .p_ctrl = &g_transfer0_ctrl, .p_cfg = &g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart3) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_rxi_isr, SCI, RXI, 3);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart3) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_txi_isr, SCI, TXI, 3);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart3) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_tei_isr, SCI, TEI, 3);
#endif
#endif
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart3) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_eri_isr, SCI, ERI, 3);
#endif
#endif
sci_uart_instance_ctrl_t g_uart3_ctrl;

/** UART extended configuration for UARTonSCI HAL driver */
const uart_on_sci_cfg_t g_uart3_cfg_extend =
{ .clk_src = SCI_CLK_SRC_INT, .baudclk_out = false, .rx_edge_start = true, .noisecancel_en = false, .p_extpin_ctrl =
          NULL,
  .bitrate_modulation = true, .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX };

/** UART interface configuration */
const uart_cfg_t g_uart3_cfg =
{ .channel = 3, .baud_rate = 9600, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits =
          UART_STOP_BITS_1,
  .ctsrts_en = false, .p_callback = NULL, .p_context = &g_uart3, .p_extend = &g_uart3_cfg_extend,
#define SYNERGY_NOT_DEFINED (1)                        
#if (SYNERGY_NOT_DEFINED == g_transfer0)
  .p_transfer_tx = NULL,
#else
  .p_transfer_tx = &g_transfer0,
#endif            
#if (SYNERGY_NOT_DEFINED == g_transfer1)
  .p_transfer_rx = NULL,
#else
  .p_transfer_rx = &g_transfer1,
#endif   
#undef SYNERGY_NOT_DEFINED            
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (BSP_IRQ_DISABLED), };

/* Instance structure to use this module. */
const uart_instance_t g_uart3 =
{ .p_ctrl = &g_uart3_ctrl, .p_cfg = &g_uart3_cfg, .p_api = &g_uart_on_sci };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_isr, ADC, SCAN_END, 0);
#endif
#endif
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_b_isr, ADC, SCAN_END_B, 0);
#endif
#endif
adc_instance_ctrl_t g_adc0_ctrl;
const adc_cfg_t g_adc0_cfg =
{ .unit = 0, .mode = ADC_MODE_CONTINUOUS_SCAN, .resolution = ADC_RESOLUTION_10_BIT, .alignment = ADC_ALIGNMENT_RIGHT,
  .add_average_count = ADC_ADD_OFF, .clearing = ADC_CLEAR_AFTER_READ_ON, .trigger = ADC_TRIGGER_SOFTWARE,
  .trigger_group_b = ADC_TRIGGER_SYNC_ELC, .p_callback = NULL, .p_context = &g_adc0, .scan_end_ipl = (BSP_IRQ_DISABLED),
  .scan_end_b_ipl = (BSP_IRQ_DISABLED), };
const adc_channel_cfg_t g_adc0_channel_cfg =
{ .scan_mask = (uint32_t) (
        ((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | (0)),
  /** Group B channel mask is right shifted by 32 at the end to form the proper mask */
  .scan_mask_group_b = (uint32_t) (
          (((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | (0)) >> 32),
  .priority_group_a = ADC_GROUP_A_PRIORITY_OFF, .add_mask = (uint32_t) (
          (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)
                  | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)),
  .sample_hold_mask = (uint32_t) ((0) | (0) | (0)), .sample_hold_states = 24, };
/* Instance structure to use this module. */
const adc_instance_t g_adc0 =
{ .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg, .p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer0) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 0);
#endif
#endif
static gpt_instance_ctrl_t g_timer0_ctrl;
static const timer_on_gpt_cfg_t g_timer0_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW } };
static const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 500, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 0, .autostart = true, .p_callback = NULL, .p_context = &g_timer0, .p_extend = &g_timer0_extend, .irq_ipl =
          (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_gpt };
void g_hal_init(void)
{
    g_common_init ();
}

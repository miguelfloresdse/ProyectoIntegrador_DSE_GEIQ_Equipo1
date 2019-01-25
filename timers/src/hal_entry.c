
/* HAL-only entry function */
/*
#include "hal_data.h"

// Define the number of counts per millisecond (1 count per clock tick, clock rate is 120MHz)
// So there are 120E6 ticks per second.
// Divide by 1000 to get ticks / millisecond
#define COUNTS_PER_MILLISECOND  (120E6 / 1000)

void hal_entry(void)
{
    // Boolean to hold LED state
    bool isOn = true;

    // Variable to hold counts
    timer_size_t counts = 0;

    // Open the timer using the configured options from the configurator
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->start (g_timer0.p_ctrl);

    // Main Loop
    while(1)
    {
        // Turn LED
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, isOn);

        // Toggle LED State
        isOn = !isOn;

        // Wait for timer loop
        while (1)
        {
            // Get current counts
            g_timer0.p_api->counterGet(g_timer0.p_ctrl, &counts);

            // Check if 500ms has elapsed => This should be a helper function at some point
            // Need to look if the PBCLK settings are stored in a define somewhere...
            if (counts > (250*COUNTS_PER_MILLISECOND))
            {
                // Reset the timer to 0
                g_timer0.p_api->reset(g_timer0.p_ctrl);
                break;
            }
        }
    }
}

*/
/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 *
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

/* HAL-only entry function */
/*
#include "hal_data.h"

// Define the number of counts per millisecond (1 count per clock tick, clock rate is 120MHz)
// So there are 120E6 ticks per second.
// Divide by 1000 to get ticks / millisecond
#define COUNTS_PER_MILLISECOND  (120E6 / 1000)

ioport_level_t P0_05Status;
ioport_level_t P0_06Status;
ioport_level_t P6_14Status;

bool bfRedOnFlag = false;
bool bfRedOffFlag = false;

void hal_entry(void)
{
    // Boolean to hold LED state
    bool isOn = true;

    // Variable to hold counts
    timer_size_t counts = 0;

    // Open the timer using the configured options from the configurator
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->start (g_timer0.p_ctrl);

    // Main Loop
    while(1)
    {
        while (1)
        {
            // Get current counts
            g_timer0.p_api->counterGet(g_timer0.p_ctrl, &counts);

            if (counts > (50*COUNTS_PER_MILLISECOND))
            {
                // Reset the timer to 0
                g_timer0.p_api->reset(g_timer0.p_ctrl);
                break;
            }
        }

        g_ioport.p_api->pinRead(IOPORT_PORT_06_PIN_14, &P6_14Status);
        g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_05, &P0_05Status);
        g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_06, &P0_06Status);

        if(P0_05Status == IOPORT_LEVEL_LOW)
            {
                bfRedOnFlag = true;
            }
        else if(P0_06Status == IOPORT_LEVEL_LOW)
            {
                bfRedOffFlag = true;
            }


        isOn = !isOn;

        // Wait for timer loop

        // Turn LED
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, isOn);
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, P6_14Status);

        if(bfRedOnFlag == true)
            {
              bfRedOnFlag = false;
              g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
            }
        else if(bfRedOffFlag == true)
            {
              bfRedOffFlag = false;
              g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_LOW);
            }
    }
}
*/

/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 *
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

#include "hal_data.h"

#define C_FILTER_ORDER (int)128
uint16_t u16ADC_Data;
uint16_t u16ADC_FilteredData;


ssp_err_t openResult;
ssp_err_t writeResult;

uint8_t dato = 165;

char            cifra[5];

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 * Only references two other modules including the BSP, IOPORT.
 *
 **********************************************************************************************************************/
void hal_entry(void) {

    /* Define the units to be used with the software delay function */
    const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;
    /* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 2;
    /* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units/freq_in_hz;
    /* LED state variable */
    ioport_level_t P6_14Status;


    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);


    openResult = g_uart3.p_api->open(g_uart3.p_ctrl,g_uart3.p_cfg);

    while(1)
    {
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &u16ADC_Data);

        u16ADC_FilteredData = (u16ADC_Data + (C_FILTER_ORDER - 1)*u16ADC_FilteredData) / C_FILTER_ORDER;
        if(u16ADC_Data > 800)
        {
            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
        }
        else
        {
            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
        }

        snprintf(cifra, sizeof(cifra), "%4d", u16ADC_FilteredData);
        writeResult = g_uart3.p_api->write(g_uart3.p_ctrl,&cifra,5);
               /* Delay */
               //R_BSP_SoftwareDelay(delay, bsp_delay_units);
    }
}

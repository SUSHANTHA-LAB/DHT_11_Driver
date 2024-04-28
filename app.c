/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/


#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "sl_udelay.h"
#include "printf.h"

#define BSP_GPIO_BUTTONS
#define BSP_NO_OF_BUTTONS       2
#define BSP_GPIO_PB0_PORT       gpioPortB
#define BSP_GPIO_PB0_PIN        0
#define BSP_GPIO_PB1_PORT       gpioPortB
#define BSP_GPIO_PB1_PIN        1

// Needs to be volatile so compiler does not optimize it away
#define BUFFER_SIZE 42
static volatile uint32_t buffer[BUFFER_SIZE];
static volatile uint32_t buffer2[BUFFER_SIZE];
static uint8_t temp[5];

/**************************************************************************//**
 * @brief
 *    CMU initialization
 *****************************************************************************/
void initCMU(void)
{
  /*
   * Enable the GPIO and TIMER0 bus clocks.
   *
   * Note: On EFR32xG21 devices, calls to CMU_ClockEnable() have no
   * effect as clocks are automatically turned on/off in response to
   * on-demand requests from the peripherals.  CMU_ClockEnable() is
   * a dummy function on EFR32xG21 present for software compatibility.
   */
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_TIMER0, true);
}

/**************************************************************************//**
 * @brief
 *    GPIO initialization
 *****************************************************************************/
void initGPIO(void)
{
  // Configure PB0 pin as input with the pull-up and filter enabled.
  GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN,
                  gpioModePushPull, 0);
  sl_udelay_wait(18000);

  GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN,
                  gpioModeInputPullFilter, 1);

  // Route the PB0 pin to TIMER0 capture/compare channel 0 and enable
  GPIO->TIMERROUTE[0].CC0ROUTE = (BSP_GPIO_PB0_PORT << _GPIO_TIMER_CC0ROUTE_PORT_SHIFT)
                               | (BSP_GPIO_PB0_PIN << _GPIO_TIMER_CC0ROUTE_PIN_SHIFT);
  GPIO->TIMERROUTE[0].ROUTEEN  = GPIO_TIMER_ROUTEEN_CC0PEN;
}

/**************************************************************************//**
 * @brief
 *    TIMER initialization
 *
 * @note
 *    Prescaling the TIMER clock may or may not be necessary in a given
 *    application.  Here, prescaling the clock by 1024 (each TIMER tick
 *    is 1024 HFPERLKs) makes it easier to see the difference between
 *    successive capture values.
 *****************************************************************************/
void initTIMER0(void)
{
  // Initialize TIMER0
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  timerInit.prescale = timerPrescale1024;
  timerInit.enable = false;               // Don't start the timer yet

  // Configure TIMER0 capture/compare channel 0 for input capture
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  timerCCInit.edge =  timerEdgeFalling;
  timerCCInit.mode = timerCCModeCapture;

  TIMER_Init(TIMER0, &timerInit);

  TIMER_InitCC(TIMER0, 0, &timerCCInit);

  /**************************************************************************//**
   * POLLED MODE INSTRUCTIONS
   * -------------------------
   *
   * To use this example in polled mode instead of interrupt mode -
   *
   * 1. Remove TIMER_IntEnable(TIMER0, TIMER_IEN_CC0);
   * 2. Remove NVIC_EnableIRQ(TIMER0_IRQn);
   *
   *****************************************************************************/

  // Enable interrupts on capture/compare channel 0
  TIMER_IntEnable(TIMER0, TIMER_IEN_CC0);
  NVIC_EnableIRQ(TIMER0_IRQn);

  // Now start the TIMER
  TIMER_Enable(TIMER0, true);
}

/**************************************************************************//**
 * POLLED MODE INSTRUCTIONS
 * -------------------------
 *
 * To use this example in polled mode instead of interrupt mode, remove
 * the TIMER0_IRQHandler(void) function.
 *
 *****************************************************************************/

/**************************************************************************//**
 * @brief
 *    TIMER 0 handler
 *****************************************************************************/
void TIMER0_IRQHandler(void)
{
  static uint32_t i = 0;

  // Acknowledge the interrupt
  uint32_t flags = TIMER_IntGet(TIMER0);
  TIMER_IntClear(TIMER0, flags);

  printf("edge detected\r\n");
  // Check for capture event on channel 0
  if (flags & TIMER_IF_CC0) {

    // Record input capture value
    buffer[i] = TIMER_CaptureGet(TIMER0, 0);
    TIMER_CounterSet(TIMER0, 0);

    // Increment index and have it wrap around
    i = (i + 1) % BUFFER_SIZE;
  }
}



/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{

  // Chip errata
  CHIP_Init();

  initCMU();
  initGPIO();
  initTIMER0();

  uint8_t indx = 2;
  uint8_t i,j;
  sl_udelay_wait(10000);

if(buffer[1] == (uint32_t)5){

    for(i = 0; i < 5; i++){
        for(j =0; j<8; j++){
            if(buffer[indx] > (uint32_t)3){
                temp[i] |= (1<<(7-j));
            }else {
                temp[i] &= ~(1<<(7-j));
            }
            indx++;
        }
    }
}else{
    printf("Init failed\r\n");
}

printf("Humidity: %u.%u\r\n", temp[0], temp[1]);
printf("Temperature %u.%u\r\n", temp[2], temp[3]);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}

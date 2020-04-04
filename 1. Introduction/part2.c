#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/**
   * @todo Implement
   * You need to do the following to set the green led pin as output
   *  1. Enable GPIOx clock first.
   *  2. Initialize the GPIOx port with the specified pins as output
   * You can get this information either from looking at examples.
   * Try to look for examples of STM32F407xx GPIO initialisation online.
*/
static void _led_pinmode_out() {
  HAL_Init();

  __HAL_RCC_GPIOD_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;

  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

  /*
  * PROBLEMAS
  * - por alguna razon, no funciona si intento hacer exactamente lo mismo pero con el GPIOÄ
  * - es necesario darle un valor al pin en esta funcion, si no, lo de abajo no lo activa y desactiva
  * - estoy teniendo timeouts en la mierda esta del nvc y no puedo ver la placa
  */
}

/**
 * @todo Implement
 * Now you need to toggle the LED pin and wait 750ms after each toggle operation
 */
static void _toggleLED() {
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
  HAL_Delay(750);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
  HAL_Delay(750);
  
}

int main() {
  _led_pinmode_out();
  while(1) { _toggleLED(); }
  return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

static char *MORSE_CODE_TABLE[] = {
    ".-", "-...", "-.-.", "-..",
    ".", "..-.", "--.", "....",
    "..", ".---", ".-.-", ".-..",
    "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

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
}

static void _blinkMorseLetter(int letterIndex){
  // Now we blink the LED according to the string stored at 'letterIndex' position
  // in the MORSE_CODE_TABLE array.

  // Retrieve morseLetter string
  char * morseLetter = MORSE_CODE_TABLE[letterIndex];
  // Traverse each character
  char currentChar = (char) *morseLetter;
  while(currentChar != '\0'){
    switch(currentChar){
      case '.':
        // . = ON > HAL_delay(100) > OFF > HAL_delay(100)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        HAL_Delay(100);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(100);
      break;
      case '-':
        // . = ON > HAL_delay(500) > OFF > HAL_delay(500)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(500);
      break;
      default:
      break;
    }
    // Prepare next iteration
    morseLetter++;
    currentChar = (char) *morseLetter;
  }
}

/**
 * @todo Implement
 * Here you need to output a given string (char array) in morse code.
 * To achieve this you need to do the following:
 *  1. Convert each character of the string into it's morse code equivalent
 *  2. Blink the LED based on whether a dot or dash needs to be transmitted.
 *    2.1. A dot may be  LED ON -> DELAY 100 -> LED OFF -> DELAY 100
 *    2.2. A dash may be LED ON -> DELAY 500 -> LED OFF -> DELAY 500
 */
static void _transmitMorseCode(const char *input) {
  char currentChar = (char) *input;
  while (currentChar != '\0') {
    // Parse character
    switch (currentChar) {
      case 'A':
      _blinkMorseLetter(0);
      break;
      case 'B':
      _blinkMorseLetter(1);
      break;
      case 'C':
      _blinkMorseLetter(2);
      break;
      case 'D':
      _blinkMorseLetter(3);
      break;
      case 'E':
      _blinkMorseLetter(4);
      break;
      case 'F':
      _blinkMorseLetter(5);
      break;
      case 'G':
      _blinkMorseLetter(6);
      break;
      case 'H':
      _blinkMorseLetter(7);
      break;
      case 'I':
      _blinkMorseLetter(8);
      break;
      case 'J':
      _blinkMorseLetter(9);
      break;
      case 'K':
      _blinkMorseLetter(10);
      break;
      case 'L':
      _blinkMorseLetter(11);
      break;
      case 'M':
      _blinkMorseLetter(12);
      break;
      case 'N':
      _blinkMorseLetter(13);
      break;
      case 'O':
      _blinkMorseLetter(14);
      break;
      case 'P':
      _blinkMorseLetter(15);
      break;
      case 'Q':
      _blinkMorseLetter(16);
      break;
      case 'R':
      _blinkMorseLetter(17);
      break;
      case 'S':
      _blinkMorseLetter(18);
      break;
      case 'T':
      _blinkMorseLetter(19);
      break;
      case 'U':
      _blinkMorseLetter(20);
      break;
      case 'V':
      _blinkMorseLetter(21);
      break;
      case 'W':
      _blinkMorseLetter(22);
      break;
      case 'X':
      _blinkMorseLetter(23);
      break;
      case 'Y':
      _blinkMorseLetter(24);
      break;
      case 'Z':
      _blinkMorseLetter(25);
      break;
      default:
      _blinkMorseLetter(-1);
    }
    // Prepare next iteration
    input++;
    currentChar = (char) *input;
  }
}

int main() {
  _led_pinmode_out();
  while(1) { _transmitMorseCode("HELLO"); }
  return 1;
}

/*
*   LED.h
*
*   Created on: 28.12.2023
*   Author: Stefan Zott
*   
*   Beschreibung:
*   Dieser Task ist für die Konfiguration und Steuerung der LEDs verantwortlich
*/

#ifndef LED_H_
#define LED_H_

#define LED_BLUE                "blue"
#define LED_YELLOW              "yellow"
#define LED_GREEN               "green"
#define LED_RED                 "red"

#define LED_GPIO_BLUE           GPIO_NUM_23
#define LED_GPIO_YELLOW         GPIO_NUM_22
#define LED_GPIO_GREEN          GPIO_NUM_19
#define LED_GPIO_RED            GPIO_NUM_18

#define ON                      "on"
#define OFF                     "off"
#define BLINK                   "blink"
#define NORMAL                  "normal"
#define test                    "test"

#define BLINK_INTERVALL         1000
#define BLINK_FREQ              200

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL_BLUE       LEDC_CHANNEL_0
#define LEDC_CHANNEL_YELLOW     LEDC_CHANNEL_1
#define LEDC_CHANNEL_GREEN      LEDC_CHANNEL_2
#define LEDC_CHANNEL_RED        LEDC_CHANNEL_3
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#define LEDC_DUTY_ON            (4096) // Set duty to 50%. (2 ** 13) * 50% = 4096
#define LEDC_DUTY_OFF           (0) // Set duty to 0%. (2 ** 13) * 0% = 0
#define LEDC_FREQUENCY          (4000) // Frequency in Hertz. Set frequency at 4 kHz

typedef struct ledState_t {
   char led[10];
   char state[10];
   char mode[10];
} ledStateMessage;

typedef struct ledProfil_t {
   char state[10]; // ON - OFF
   char mode[10]; // TEST - NORMAL - BLINK
} ledProfil;

extern QueueHandle_t xLedStateQueue;

void ledControlTask( void *pvParameters );

#endif /* LED_H_ */
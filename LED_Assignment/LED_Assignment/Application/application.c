/*
 * application.c
 *
 * Created: 8/24/2023 1:51:49 AM
 *  Author: HP
 */
#include "application.h"

int currentLed = 0;

uint8_t buttonState = LOW;
uint8_t ledState = LOW;

uint8_t led_pin_tst = LED_1_PIN;
uint8_t btn_pin_tst = BUTTON_1_PIN;

EN_appError_t APP_init(void) {
  if (LED_init(LED_1_PORT, led_pin_tst) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_2_PORT, LED_2_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_3_PORT, LED_3_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_4_PORT, LED_4_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (BUTTON_init(BUTTON_1_PORT, btn_pin_tst) != BTN_OK) {
    return APP_BTN_ERROR;
  } else {
	  
	   /* Enabling global interrupts */
enable_Global_interrupt();
  /* Choose the external interrupt sense - sense on rising edge */
  extInt_rising();
  /*enable external interrupt 0- INT0 */
  enable_external_interrupt0();

    return APP_OK;
  }
  
 
}

EN_appError_t APP_start(void) {

 while(1)
 {
	 switch (currentLed)
	 {
		 case CASE0:
		 if(LED_off(LED_1_PORT, led_pin_tst)!=LED_OK){
			 return APP_LED_ERROR;
		 }
		else if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
			 return APP_LED_ERROR;
			 
		}
		else if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}else if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
		return APP_LED_ERROR;
	}
		 
		 
		 break;
		 case CASE1:
		 if(LED_on(LED_1_PORT, LED_1_PIN)!= LED_OK)
		 {
			 return APP_LED_ERROR;
		 }
		 break;
			
		 case CASE2:
		 if(LED_on(LED_2_PORT, LED_2_PIN) != LED_OK)
		 {
			 return APP_LED_ERROR;
		 }
		 break;
			
		 case CASE3:
		 	 if(LED_on(LED_3_PORT, LED_3_PIN) != LED_OK)
		 	 {
			 	 return APP_LED_ERROR;
		 	 }
		 break;
			
		 case CASE4:
		 if(LED_on(LED_4_PORT, LED_4_PIN) != LED_OK)
		 {
			 return APP_LED_ERROR;
		 }
			break;
		 case CASE5:
		 if(LED_off(LED_1_PORT, LED_1_PIN)!=LED_OK){
			 return APP_LED_ERROR;
		 }
			break;
		 case CASE6:
		 if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
			 return APP_LED_ERROR;
			 
		 }
			break;
		 case CASE7:
		 if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
			 return APP_LED_ERROR;
			 
		 }
			break;
			
		 case CASE8:
		 if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
			 return APP_LED_ERROR;
		 }
			break;
		 default:
		 // Do nothing
		 break;
		 
	 }
		 //}
 }

}

ISR(EXT_INT_0)
{
		 
		 if (currentLed < LED_NUMBERS)
		 {
			 currentLed++;
		 }
		 else
		 {
			 currentLed = CASE1;
		 }
	
}

	

void test_app(void) {

  /* initializing test cases */
  /* test case 1.. returns APP_LED_ERROR */
  led_pin_tst = testFail;
  APP_init();

  /* test case 2.. returns APP_BTN_ERROR */
    led_pin_tst = LED_1_PIN;
	btn_pin_tst = testFail;
  APP_init();
  btn_pin_tst = BUTTON_1_PIN;

  /* APP_start test cases   */
  /* test case 3.. returns APP_LED_ERROR*/
  APP_init();
    led_pin_tst = testFail;
  APP_start();
  
 
 /*test case 4 [HAPPY Case scenario]*/
    led_pin_tst = LED_1_PIN;
  btn_pin_tst = BUTTON_1_PIN;
 APP_init();
 APP_start();

}





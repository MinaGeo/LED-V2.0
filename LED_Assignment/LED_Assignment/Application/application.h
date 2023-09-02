/*
 * application.h
 *
 * Created: 8/24/2023 1:51:41 AM
 *  Author: HP
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#define F_CPU 1000000UL  // 1 MH
#include <util/delay.h>
#define  LED_NUMBERS 8
//define cases
#define CASE0 0
#define CASE1 1
#define CASE2 2
#define CASE3 3
#define CASE4 4
#define CASE5 5
#define CASE6 6
#define CASE7 7
#define CASE8 8
//define fail test
#define testFail 10

#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"

typedef enum EN_appError_t{
	APP_OK, APP_LED_ERROR, APP_BTN_ERROR,APP_INT_ERROR,APP_ERROR_EXIT
}EN_appError_t;

EN_appError_t APP_init(void);
EN_appError_t APP_start(void);


void test_app(void);
#endif /* APPLICATION_H_ */
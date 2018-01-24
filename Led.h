
// Header: prototypes for led.c
// File Name: Led.h
// Author: Jagadish
// Date:23-01-2018

#ifndef _LED_H
#define _LED_H

#include "stdint.h"

uint32_t led_initialize(void);
		
uint32_t led_on(uint8_t);

uint32_t led_off(uint8_t);

uint32_t led_toggle(uint8_t);

#endif




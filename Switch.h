
// Header: prototypes for Switch.c
// File Name: Switch.h
// Author: Jagadish
// Date:23-01-2018

#ifndef _SWITCH_H
#define _SWITCH_H

#include "stdint.h"

uint32_t switch_initialize(uint8_t);
		
uint32_t switch_getstate(uint32_t);

uint32_t switch_getcount(void);
#endif




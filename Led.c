#include "MK60D10.h"
#include "led.h"

#define LED_NUM 4
const uint32_t led_mask[] = {1UL << 11,1UL << 28,1UL<<29,1UL<<10};

uint32_t 
led_initialize(void){

	SIM->SCGC5 |= (1UL << 9);
	
	PORTA->PCR[11] = (1UL << 8);
	PORTA->PCR[28] = (1UL << 8);
	PORTA->PCR[29] = (1UL << 8);
	PORTA->PCR[10] = (1UL << 8);
	PTA->PDOR = (led_mask[0]|
					led_mask[1]|
					led_mask[2]|
					led_mask[3]);
	
	PTA->PDDR = (led_mask[0]|
					led_mask[1]|
					led_mask[2]|
					led_mask[3]);
	return 0;
}



uint32_t  
led_on(uint8_t val){
	if(val<LED_NUM)
	{
		PTA->PCOR |= led_mask[val];
		return 0;
	}
	else
	{
		return 1; 
	}
}

uint32_t  
led_off(uint8_t val){
	if(val<LED_NUM)
	{
		PTA->PSOR |= led_mask[val];
		return 0;
	}
	else
	{
		return 1; 
	}
}



uint32_t  
led_toggle(uint8_t val){
	if(val<LED_NUM)
	{
		PTA->PTOR |= led_mask[val];
		return 0;
	}
	else
	{
		return 1; 
	}
}
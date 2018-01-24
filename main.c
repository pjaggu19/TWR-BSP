#include "MK60D10.h"
#include "led.h"
#include "switch.h"
uint32_t count=0;
void PORTA_IRQHandler(void)
{
	PORTA->ISFR |=0xffffffff;
	
	if(PTA->PDIR&(1UL<<19))
		{
	//RISING EDGE
	//release
	led_off(0);
		}
	else if(!(PTA->PDIR&(1UL << 19)))
	{
		//FALLING EDGE
		//Press
		led_on(0);
	
	}


}

void PORTE_IRQHandler(void)
{
	PORTE->ISFR |=0xffffffff;
	
	if(PTE->PDIR&(1UL<<26))
		{
	//RISING EDGE
	//release
	led_off(1);
		}
	else if(!(PTA->PDIR&(1UL << 26)))
	{
		//FALLING EDGE
		//Press
		led_on(1);
	
	}


}

int main()
	{
	
	SystemCoreClockUpdate();
	led_initialize();
	switch_initialize(0);
	switch_initialize(1);
	__NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_EnableIRQ(PORTE_IRQn);
		while(1);
	
	
	return 0;
 }


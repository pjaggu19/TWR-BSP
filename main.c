#include "MK60D10.h"
#include "led.h"
#include "switch.h"


int main()
	{
	
	SystemCoreClockUpdate();
	led_initialize();
	switch_initialize(0);
	switch_initialize(1);
	while(1){
	
	if(switch_getstate(0)) led_on(0);
		else led_off(0);
	 if(switch_getstate(1)) led_on(1);
		else led_off(1);
	}
return 0;
 }


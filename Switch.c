#include "MK60D10.h"
#include "Switch.h"

#define SWITCH_COUNT 2
#define SW1 1
#define SW2 1
uint32_t switch_mask[] = {1UL << 19,1UL << 26};


uint32_t 
switch_initialize(uint8_t val){
if(val<SWITCH_COUNT)
{
	if(val == 0)
	{
			//SW1 PORTA
		SIM->SCGC5 |= (1UL << 9);
		PORTA->PCR[19] |= (1UL << 8); // GPIO
		PORTA->PCR[19] |= (3UL << 0); //PE|PS
	}
	else if(val == 1)
	{
		SIM->SCGC5 |= (1UL << 13);
		PORTE->PCR[26] |=(1UL << 8);
		PORTE->PCR[26] |= (3UL << 0);
	}
return 0;
}
else
{
	return 1;
}

}



uint32_t
switch_getstate(uint32_t val){
uint32_t flag = 0;
if(val < SWITCH_COUNT){
  if(val == 0 )
		{
			if ((PTA->PDIR  & (1UL << 19)) == 0) 
			{
				/*sw1 button */
				flag = SW1;
			}

		}
		else if (val == 1)
		{
			if ((PTE->PDIR  & (1UL << 26)) == 0) 
			{
				/*sw2 button */
				flag = SW2;
			}
		
		}
  return (flag);

}
else return 0;

}



uint32_t 
switch_getcount(void)
{
return SWITCH_COUNT;


}
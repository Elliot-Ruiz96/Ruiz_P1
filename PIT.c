#include "PIT.h"

volatile bool pitIsrFlag = false;

uint8_t PIT_Flag_get_PIT(void){
	return (pitIsrFlag);
}

void PIT0_IRQHandler(void){
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	pitIsrFlag = true;
	__DSB();
}

void PIT_Flag_Set_PIT(void){
	pitIsrFlag = false;
}

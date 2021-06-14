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

void PIT_Initialize(){

	pit_config_t pitConfig;
	uint32_t FREQ = 0;
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	FREQ = CLOCK_GetFreq(kCLOCK_BusClk);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000U, FREQ));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}

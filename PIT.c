#include "PIT.h"

volatile bool pitIsrFlag = false;
volatile bool pitIsrFlag1 = false;
uint32_t PIT_Value = 1000000;

uint8_t PIT_Flag_get_PIT(void){
	return (pitIsrFlag);
}

void PIT_Flag_Set_PIT(void){
	pitIsrFlag = false;
}

void PIT0_IRQHandler(void){
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	pitIsrFlag = true;
	__DSB();
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

uint8_t PIT_Flag_get_PIT1(void){
	return (pitIsrFlag1);
}

void PIT_Flag_Set_PIT1(void){
	pitIsrFlag1 = false;
}

void PIT1_IRQHandler(void){
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
	pitIsrFlag = true;
	__DSB();
}

void PIT1_Initialize(){
	pit_config_t pitConfig;
	uint32_t FREQ1 = 0;
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	FREQ1 = CLOCK_GetFreq(kCLOCK_BusClk);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_1, USEC_TO_COUNT(PIT_Value, FREQ1));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_1, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT1_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_1);
}

void PIT_Start(total){
	PIT_Value = total;
}

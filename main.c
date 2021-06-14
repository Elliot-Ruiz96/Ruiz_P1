#include <stdio.h>
#include "fsl_dac.h"
#include "Config.h"
#include "Keyboard_Matrix.h"
#include "PIT.h"
#include "RGB.h"

typedef enum {
	START,
	PERIOD,
	AMPLITUDE,
	EDIT,

}State_name_t;

State_name_t current_state = START;

uint8_t g_Button2 = 0;
uint8_t g_Button3 = 0;

void PORTA_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOA, 1U << PIN4);
    g_Button2 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOC, 1U << PIN6);
    g_Button3 = true;
    SDK_ISR_EXIT_BARRIER;
}

int main(void) {

	uint8_t flag;
	pit_config_t pitConfig;
	uint32_t FREQ = 0;

	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	FREQ = CLOCK_GetFreq(kCLOCK_BusClk);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000U, FREQ));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);

	GPIO_Config();

	PORT_SetPinInterruptConfig(PORTC, PIN6, kPORT_InterruptFallingEdge);
	PORT_SetPinInterruptConfig(PORTA, PIN4, kPORT_InterruptFallingEdge);

	NVIC_EnableIRQ(PORTC_IRQn);
	NVIC_SetPriority(PORTC_IRQn, 1);

	NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_SetPriority(PORTA_IRQn, 1);

	while(1) {

		if(PIT_Flag_get_PIT() == true){
			switch(current_state){
				case START:
					RED_RGB();
					if(g_Button2){
						current_state = PERIOD;
					}
					if(g_Button3){
						current_state = AMPLITUDE;
					}
					break;
				case PERIOD:
					g_Button2 = false;
					flag = true;
					while(flag == true){
						if(PIT_Flag_get_PIT() == true){
							GREEN_RGB();
							Read_KeyPad();
							if(g_Button2 == 1){
								current_state = EDIT;
								flag = false;
							}
							PIT_Flag_Set_PIT();
						}
					}
					break;
				case AMPLITUDE:
					g_Button2 = false;
					flag = true;
					while(flag == true){
						if(PIT_Flag_get_PIT() == true){
							BLUE_RGB();
							Read_KeyPad();
							if(g_Button2 == 1){
								current_state = EDIT;
								flag = false;
							}
							PIT_Flag_Set_PIT();
						}
					}
					break;
				case EDIT:
					g_Button2 = false;
					g_Button3 = false;
					flag = true;
					while(flag == true){
						if(PIT_Flag_get_PIT() == true){
							PURPLE_RGB();
							if(g_Button2 == 1){
								current_state = PERIOD;
								flag = false;
							}
							if(g_Button3 == 1){
								current_state = AMPLITUDE;
								flag = false;
							}
							PIT_Flag_Set_PIT();
						}
					}
					break;
				default:
					break;
			}
			PIT_Flag_Set_PIT();
		}
    }
    return 0;
}

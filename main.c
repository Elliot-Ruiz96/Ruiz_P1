#include <stdio.h>
#include "clock_config.h"
#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "Keyboard_Matrix.h"
#include "RGB.h"
#include "PIT.h"

#define PIN4        4u
#define PIN6        6u

typedef enum {
	START,
	PERIOD,
	AMPLITUDE,
	EDIT,

}State_name_t;

State_name_t current_state = START;

uint8_t g_Button2 = 0;
uint8_t g_Button3 = 0;

gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
    };

gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        1,
    };

gpio_pin_config_t line_config = {
        kGPIO_DigitalOutput,
        0,
    };

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

	const port_pin_config_t sw_pin_config = {
	    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
	    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
	    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
	    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
	    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
	    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
	    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	  };

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

	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	PORT_SetPinMux(PORTB, PIN21, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN22, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, PIN26, kPORT_MuxAsGpio);

	PORT_SetPinConfig(PORTA, PIN4, &sw_pin_config);

	PORT_SetPinMux(PORTB, PIN2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN10, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN11, kPORT_MuxAsGpio);

	PORT_SetPinConfig(PORTC, PIN6, &sw_pin_config);

	PORT_SetPinConfig(PORTD, PIN0, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN1, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN2, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN3, &sw_pin_config);

	GPIO_PinInit(GPIOA, PIN4, &sw_config);

	GPIO_PinInit(GPIOB, PIN2, &line_config);
	GPIO_PinInit(GPIOB, PIN3, &line_config);
	GPIO_PinInit(GPIOB, PIN10, &line_config);
	GPIO_PinInit(GPIOB, PIN11, &line_config);

	GPIO_PinInit(GPIOC, PIN6, &sw_config);

	GPIO_PinInit(GPIOD, PIN0, &sw_config);
	GPIO_PinInit(GPIOD, PIN1, &sw_config);
	GPIO_PinInit(GPIOD, PIN2, &sw_config);
	GPIO_PinInit(GPIOD, PIN3, &sw_config);

	GPIO_PinInit(GPIOB, PIN22, &led_config);
	GPIO_PinInit(GPIOB, PIN21, &led_config);
	GPIO_PinInit(GPIOE, PIN26, &led_config);

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

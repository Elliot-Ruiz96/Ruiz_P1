#include <stdio.h>
#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "Keyboard_Matrix.h"
#include "RGB.h"

#define PIN4        4u
#define PIN6        6u

uint8_t g_Button2 = 0;
uint8_t g_Button3 = 0;
uint8_t g_Column1 = 0;
uint8_t g_Column2 = 0;
uint8_t g_Column3 = 0;
uint8_t g_Column4 = 0;

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
    g_Button3 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOC, 1U << PIN6);
    g_Button2 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC1_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOD, 1U << PIN0);
    g_Column1 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC2_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOD, 1U << PIN2);
    g_Column2 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC3_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOD, 1U << PIN3);
    g_Column3 = true;
    SDK_ISR_EXIT_BARRIER;
}
void PORTC4_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOD, 1U << PIN1);
    g_Column4 = true;
    SDK_ISR_EXIT_BARRIER;
}

int main(void) {

	uint8_t L1, L2, L3, L4;

	const port_pin_config_t sw_pin_config = {
	    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
	    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
	    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
	    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
	    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
	    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
	    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	  };

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

	PORT_SetPinInterruptConfig(PORTA, PIN4, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_SetPriority(PORTA_IRQn, 1);

	PORT_SetPinInterruptConfig(PORTC, PIN6, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTC_IRQn);
	NVIC_SetPriority(PORTC_IRQn, 1);

	PORT_SetPinInterruptConfig(PORTD, PIN0, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTD_IRQn);
	NVIC_SetPriority(PORTD_IRQn, 2);

	PORT_SetPinInterruptConfig(PORTD, PIN2, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTD_IRQn);
	NVIC_SetPriority(PORTD_IRQn, 2);

	PORT_SetPinInterruptConfig(PORTD, PIN3, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTD_IRQn);
	NVIC_SetPriority(PORTD_IRQn, 2);

	PORT_SetPinInterruptConfig(PORTD, PIN1, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTD_IRQn);
	NVIC_SetPriority(PORTD_IRQn, 2);


	while(1) {

		L1 = GPIO_PinRead(GPIOB, PIN2);
    	L2 = GPIO_PinRead(GPIOB, PIN3);
    	L3 = GPIO_PinRead(GPIOB, PIN10);
    	L4 = GPIO_PinRead(GPIOB, PIN11);
    	Read_KeyPad(L1, L2, L3, L4, g_Column1, g_Column2, g_Column3, g_Column4);
    	printf("C1: %d \n", g_Column1);
    	printf("C2: %d \n", g_Column2);
    	printf("C3: %d \n", g_Column3);
    	printf("C4: %d \n", g_Column4);
    	printf("B2: %d \n", g_Button2);
    	printf("B3: %d \n", g_Button3);
    	if(g_Button2){
    		g_Button2 = false;
    	}
    	if(g_Button3){
    		g_Button3 = false;
    	}
    	if(g_Column1){
    		g_Column1 = false;
    	}
    	if(g_Column2){
    		g_Column2 = false;
    	}
    	if(g_Column3){
    		g_Column3 = false;
    	}
    	if(g_Column4){
    		g_Column4 = false;
    	}
    	SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
    }
    return 0;
}

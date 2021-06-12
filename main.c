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

void PORTA_IRQHandler(void)
{

    GPIO_PortClearInterruptFlags(GPIOA, 1U << PIN4);
    g_Button3 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC_IRQHandler(void)
{

    GPIO_PortClearInterruptFlags(GPIOC, 1U << PIN6);
    g_Button2 = true;
    SDK_ISR_EXIT_BARRIER;
}

int main(void) {

	uint8_t L1, L2, L3, L4, C1, C2, C3, C4;

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

	while(1) {

		L1 = GPIO_PinRead(GPIOB, PIN2);
    	L2 = GPIO_PinRead(GPIOB, PIN3);
    	L3 = GPIO_PinRead(GPIOB, PIN10);
    	L4 = GPIO_PinRead(GPIOB, PIN11);
    	C1 = GPIO_PinRead(GPIOD, PIN0);
    	C2 = GPIO_PinRead(GPIOD, PIN2);
    	C3 = GPIO_PinRead(GPIOD, PIN3);
    	C4 = GPIO_PinRead(GPIOD, PIN1);
    	Read_KeyPad(L1, L2, L3, L4, C1, C2, C3, C4);
    	GREEN_RGB();
    	if(g_Button2)
    	{
    		g_Button2 = false;
    		RED_RGB();
    	}
    	if(g_Button3)
    	{
    		g_Button3 = false;
    		BLUE_RGB();
    	}
    	SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
    }
    return 0;
}

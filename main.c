#include <stdio.h>
#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "Keyboard_Matrix.h"

#define PIN0       	0u
#define PIN1       	1u
#define PIN2		2u
#define PIN3		3u
#define PIN10		10u
#define PIN11		11u
#define PIN6        6u
#define PIN4        4u
#define CORE_FREQ	21000000u
#define DELAY		1000000u

 gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
    };

int main(void) {

	uint32_t L1, L2, L3, L4, C1, C2, C3, C4, B1, B2;

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
	PORT_SetPinConfig(PORTA, PIN4, &sw_pin_config);
	PORT_SetPinConfig(PORTB, PIN2, &sw_pin_config);
	PORT_SetPinConfig(PORTB, PIN3, &sw_pin_config);
	PORT_SetPinConfig(PORTB, PIN10, &sw_pin_config);
	PORT_SetPinConfig(PORTB, PIN11, &sw_pin_config);
	PORT_SetPinConfig(PORTC, PIN6, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN0, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN1, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN2, &sw_pin_config);
	PORT_SetPinConfig(PORTD, PIN3, &sw_pin_config);
	GPIO_PinInit(GPIOA, PIN4, &sw_config);
	GPIO_PinInit(GPIOB, PIN2, &sw_config);
	GPIO_PinInit(GPIOB, PIN3, &sw_config);
	GPIO_PinInit(GPIOB, PIN10, &sw_config);
	GPIO_PinInit(GPIOB, PIN11, &sw_config);
	GPIO_PinInit(GPIOC, PIN6, &sw_config);
	GPIO_PinInit(GPIOD, PIN0, &sw_config);
	GPIO_PinInit(GPIOD, PIN1, &sw_config);
	GPIO_PinInit(GPIOD, PIN2, &sw_config);
	GPIO_PinInit(GPIOD, PIN3, &sw_config);

	while(1) {

		L1 = GPIO_PinRead(GPIOB, PIN2);
    	L2 = GPIO_PinRead(GPIOB, PIN3);
    	L3 = GPIO_PinRead(GPIOB, PIN10);
    	L4 = GPIO_PinRead(GPIOB, PIN11);
    	C1 = GPIO_PinRead(GPIOD, PIN0);
    	C2 = GPIO_PinRead(GPIOD, PIN2);
    	C3 = GPIO_PinRead(GPIOD, PIN3);
    	C4 = GPIO_PinRead(GPIOD, PIN1);
    	B1 = GPIO_PinRead(GPIOA, PIN4);
    	B2 = GPIO_PinRead(GPIOC, PIN6);

    	Read_KeyPad(L1, L2, L3, L4, C1, C2, C3, C4, B1, B2);

    	SDK_DelayAtLeastUs(DELAY, CORE_FREQ);

    }
    return 0 ;
}

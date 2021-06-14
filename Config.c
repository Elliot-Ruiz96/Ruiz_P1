#include "Config.h"

void GPIO_Config(){

	gpio_pin_config_t led_config = {
	        kGPIO_DigitalOutput,
	        1,
	    };

	gpio_pin_config_t line_config = {
	        kGPIO_DigitalOutput,
	        0,
	    };

	gpio_pin_config_t sw_config = {
	        kGPIO_DigitalInput,
	        0,
	    };

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
}

#include "RGB.h"

void RED_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOB, 1u << PIN22);					// RED
}

void GREEN_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOE, 1u << PIN26);					// GREEN
}

void BLUE_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOB, 1u << PIN21);					// BLUE
}

void PURPLE_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOB, 1u << PIN21);					// PURPLE
	GPIO_PortSet(GPIOB, 1u << PIN22);
}

void YELLOW_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOB, 1u << PIN22);					// YELLOW
	GPIO_PortSet(GPIOE, 1u << PIN26);
}

void LIGHTBLUE_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOE, 1u << PIN26);
	GPIO_PortSet(GPIOB, 1u << PIN21);					// LIGHT BLUE

}

void WHITE_RGB(){
	OFF_RGB();
	GPIO_PortSet(GPIOB, 1u << PIN21);					// WHITE
	GPIO_PortSet(GPIOB, 1u << PIN22);
	GPIO_PortSet(GPIOE, 1u << PIN26);
}

void OFF_RGB(){
	GPIO_PortClear(GPIOB, 1u << PIN21);
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
}

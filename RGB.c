#include "RGB.h"

void RED_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOB, 1u << PIN22);					// RED
		PIT_Flag_Set_PIT();
	}

}

void GREEN_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOE, 1u << PIN26);					// GREEN
		PIT_Flag_Set_PIT();
	}
}

void BLUE_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOB, 1u << PIN21);					// BLUE
		PIT_Flag_Set_PIT();
	}
}

void PURPLE_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOB, 1u << PIN21);					// PURPLE
		GPIO_PortClear(GPIOB, 1u << PIN22);
		PIT_Flag_Set_PIT();
	}
}

void YELLOW_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOB, 1u << PIN22);					// YELLOW
		GPIO_PortClear(GPIOE, 1u << PIN26);
		PIT_Flag_Set_PIT();
	}
}

void LIGHTBLUE_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOE, 1u << PIN26);
		GPIO_PortClear(GPIOB, 1u << PIN21);					// LIGHT BLUE
		PIT_Flag_Set_PIT();
	}

}

void WHITE_RGB(){
	if(PIT_Flag_get_PIT() == true){
		OFF_RGB();
		GPIO_PortClear(GPIOB, 1u << PIN21);					// WHITE
		GPIO_PortClear(GPIOB, 1u << PIN22);
		GPIO_PortClear(GPIOE, 1u << PIN26);
		PIT_Flag_Set_PIT();
	}
}

void OFF_RGB(){
	GPIO_PortSet(GPIOB, 1u << PIN21);
	GPIO_PortSet(GPIOB, 1u << PIN22);
	GPIO_PortSet(GPIOE, 1u << PIN26);
}

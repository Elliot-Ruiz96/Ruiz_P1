#include "Keyboard_Matrix.h"

State_name_t1 current_line = FIRST;
uint8_t dot = false;
uint32_t input = 0, input2 = 0, total = 0;

uint32_t Get_Num(){
	return total;
}

void Read_KeyPad(){

	uint8_t L1, L2, L3, L4, C1, C2, C3 ,C4, flag1, flag2 = true;

	L1 = GPIO_PinRead(GPIOB, PIN2);
	L2 = GPIO_PinRead(GPIOB, PIN3);
	L3 = GPIO_PinRead(GPIOB, PIN10);
	L4 = GPIO_PinRead(GPIOB, PIN11);
	C1 = GPIO_PinRead(GPIOD, PIN0);
	C2 = GPIO_PinRead(GPIOD, PIN2);
	C3 = GPIO_PinRead(GPIOD, PIN3);
	C4 = GPIO_PinRead(GPIOD, PIN1);

	switch(current_line){
	case FIRST:
		if(flag2 == true){
				GPIO_PortSet(GPIOB, 1u << PIN2);
				flag1 = true;
				while(flag1 == true){
					YELLOW_RGB();
					if(C1 == 0){
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 1;
						if (dot == true){
							input2 = (input / 10) + 1;
						}
						total = input + input2;
					}
					else if (C2 == 0){
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 2;
						if (dot == true){
							input2 = (input / 10) + 2;
						}
						total = input + input2;
					}
					else if (C3 == 0){
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 3;
						if (dot == true){
							input2 = (input / 10) + 3;
						}
						total = input + input2;
					}
					else if (C4 == 0){
						flag1 = false;
						flag2 = false;
					}
					if(flag1 == true && flag2 == true){
						current_line = SECOND;
						flag1 = false;
					}
				}
				GPIO_PortClear(GPIOB, 1u << PIN2);
			}
		break;
	case SECOND:
		if(flag2 == true){
		GPIO_PortSet(GPIOB, 1u << PIN3);
		flag1 = true;
		while(flag1 == true){
			LIGHTBLUE_RGB();
			if(C1 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 4;
				if (dot == true){
					input2 = (input / 10) + 4;
				}
				total = input + input2;
			}
			else if (C2 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 5;
				if (dot == true){
					input2 = (input / 10) + 5;
				}
				total = input + input2;
			}
			else if (C3 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 6;
				if (dot == true){
					input2 = (input / 10) + 6;
				}
				total = input + input2;
			}
			else if (C4 == 0){
				flag1 = false;
				flag2 = false;
			}
			if(flag1 == true && flag2 == true){
				current_line = THIRD;
				flag1 = false;
			}
		}
		GPIO_PortClear(GPIOB, 1u << PIN3);
		}
		break;
	case THIRD:
		if(flag2 == true){
		GPIO_PortSet(GPIOB, 1u << PIN10);
		flag1 = true;
		while(flag1 == true){
			WHITE_RGB();
			if(C1 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 7;
				if (dot == true){
					input2 = (input / 10) + 7;
				}
				total = input + input2;
			}
			else if (C2 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 8;
				if (dot == true){
					input2 = (input / 10) + 8;
				}
				total = input + input2;
			}
			else if (C3 == 0){
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 9;
				if (dot == true){
					input2 = (input / 10) + 9;
				}
				total = input + input2;
			}
			else if (C4 == 0){
				flag1 = false;
				flag2 = false;
			}
			if(flag1 == true && flag2 == true){
				current_line = FOURTH;
				flag1 = false;
			}
		}
		GPIO_PortClear(GPIOB, 1u << PIN10);
		}
		break;
	case FOURTH:
		if(flag2 == true){
				GPIO_PortSet(GPIOB, 1u << PIN11);
				flag1 = true;
				while(flag1 == true){
					GREEN_RGB();
					if(C1 == 0){
						flag1 = false;
						flag2 = false;
						dot = true;
					}
					else if (C2 == 0){
						flag1 = false;
						flag2 = false;
						input = input * 10;
						if (dot == true){
							input2 = (input / 10);
						}
						total = input + input2;
					}
					else if (C3 == 0){
						flag1 = false;
						flag2 = false;
					}
					else if (C4 == 0){
						flag1 = false;
						flag2 = false;
					}
					if(flag1 == true && flag2 == true){
						current_line = FIRST;
						flag1 = false;
					}
				}
				GPIO_PortClear(GPIOB, 1u << PIN11);
				}
		break;
	}
}

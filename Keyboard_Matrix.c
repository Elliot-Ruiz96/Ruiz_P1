#include "Keyboard_Matrix.h"

State_name_t1 current_line = FIRST;
uint8_t dot = false;
uint32_t input = 0, input2 = 0, total = 0;

int Read_KeyPad(){

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
					printf("Linea 1:\n");
					if(C1 == 0){
						printf("1\n");
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 1;
						if (dot == true){
							input2 = (input / 10) + 1;
						}
						total = input + input2;
					}
					else if (C2 == 0){
						printf("2\n");
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 2;
						if (dot == true){
							input2 = (input / 10) + 2;
						}
						total = input + input2;
					}
					else if (C3 == 0){
						printf("3\n");
						flag1 = false;
						flag2 = false;
						input = (input * 10) + 3;
						if (dot == true){
							input2 = (input / 10) + 3;
						}
						total = input + input2;
					}
					else if (C4 == 0){
						printf("A\n");
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
			printf("Linea 2:\n");
			if(C1 == 0){
				printf("4\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 4;
				if (dot == true){
					input2 = (input / 10) + 4;
				}
				total = input + input2;
			}
			else if (C2 == 0){
				printf("5\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 5;
				if (dot == true){
					input2 = (input / 10) + 5;
				}
				total = input + input2;
			}
			else if (C3 == 0){
				printf("6\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 6;
				if (dot == true){
					input2 = (input / 10) + 6;
				}
				total = input + input2;
			}
			else if (C4 == 0){
				printf("B\n");
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
			printf("Linea 3:\n");
			if(C1 == 0){
				printf("7\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 7;
				if (dot == true){
					input2 = (input / 10) + 7;
				}
				total = input + input2;
			}
			else if (C2 == 0){
				printf("8\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 8;
				if (dot == true){
					input2 = (input / 10) + 8;
				}
				total = input + input2;
			}
			else if (C3 == 0){
				printf("9\n");
				flag1 = false;
				flag2 = false;
				input = (input * 10) + 9;
				if (dot == true){
					input2 = (input / 10) + 9;
				}
				total = input + input2;
			}
			else if (C4 == 0){
				printf("C\n");
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
					printf("Linea 4:\n");
					if(C1 == 0){
						printf("*\n");
						flag1 = false;
						flag2 = false;
						dot = true;
					}
					else if (C2 == 0){
						printf("0\n");
						flag1 = false;
						flag2 = false;
						input = input * 10;
						if (dot == true){
							input2 = (input / 10);
						}
						total = input + input2;
					}
					else if (C3 == 0){
						printf("#\n");
						flag1 = false;
						flag2 = false;
					}
					else if (C4 == 0){
						printf("D\n");
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
	return total;
}

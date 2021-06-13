#include "Keyboard_Matrix.h"

void Read_KeyPad(){

	uint8_t L1, L2, L3, L4, C1, C2, C3 ,C4, flag1;

	L1 = GPIO_PinRead(GPIOB, PIN2);
	L2 = GPIO_PinRead(GPIOB, PIN3);
	L3 = GPIO_PinRead(GPIOB, PIN10);
	L4 = GPIO_PinRead(GPIOB, PIN11);
	C1 = GPIO_PinRead(GPIOD, PIN0);
	C2 = GPIO_PinRead(GPIOD, PIN2);
	C3 = GPIO_PinRead(GPIOD, PIN3);
	C4 = GPIO_PinRead(GPIOD, PIN1);

	if(PIT_Flag_get_PIT() == true){
		GPIO_PortSet(GPIOB, 1u << PIN2);
		flag1 = true;
		while(flag1 == true){
			printf("L1: %d",L1);
			printf("C1: %d",C1);
			printf("C2: %d",C2);
			printf("C3: %d",C3);
			printf("C4: %d",C4);
			if(C1 == 0){
				printf("1\n");
				flag1 = false;
			}
			else if (C2 == 0){
				printf("2\n");
				flag1 = false;
			}
			else if (C3 == 0){
				printf("3\n");
				flag1 = false;
			}
			else if (C4 == 0){
				printf("A\n");
				flag1 = false;
			}
		}
		PIT_Flag_Set_PIT();
		GPIO_PortClear(GPIOB, 1u << PIN2);
		printf("L1: %d",L1);
		printf("C1: %d",C1);
		printf("C2: %d",C2);
		printf("C3: %d",C3);
		printf("C4: %d",C4);
	}

	if(PIT_Flag_get_PIT() == true){
		GPIO_PortSet(GPIOB, 1u << PIN3);
		flag1 = true;
		while(flag1 == true){
			printf("L2: %d",L2);
			printf("C1: %d",C1);
			printf("C2: %d",C2);
			printf("C3: %d",C3);
			printf("C4: %d",C4);
			if(C1 == 0){
				printf("4\n");
				flag1 = false;
			}
			else if (C2 == 0){
				printf("5\n");
				flag1 = false;
			}
			else if (C3 == 0){
				printf("6\n");
				flag1 = false;
			}
			else if (C4 == 0){
				printf("B\n");
				flag1 = false;
			}
		}
		PIT_Flag_Set_PIT();
		GPIO_PortClear(GPIOB, 1u << PIN3);
		printf("L2: %d",L2);
		printf("C1: %d",C1);
		printf("C2: %d",C2);
		printf("C3: %d",C3);
		printf("C4: %d",C4);
	}

	if(PIT_Flag_get_PIT() == true){
		GPIO_PortSet(GPIOB, 1u << PIN10);
		flag1 = true;
		while(flag1 == true){
			printf("L3: %d",L3);
			printf("C1: %d",C1);
			printf("C2: %d",C2);
			printf("C3: %d",C3);
			printf("C4: %d",C4);
			if(C1 == 0){
				printf("4\n");
				flag1 = false;
			}
			else if (C2 == 0){
				printf("5\n");
				flag1 = false;
			}
			else if (C3 == 0){
				printf("6\n");
				flag1 = false;
			}
			else if (C4 == 0){
				printf("B\n");
				flag1 = false;
			}
		}
		PIT_Flag_Set_PIT();
		GPIO_PortClear(GPIOB, 1u << PIN10);
		printf("L3: %d",L3);
		printf("C1: %d",C1);
		printf("C2: %d",C2);
		printf("C3: %d",C3);
		printf("C4: %d",C4);
	}

	if(PIT_Flag_get_PIT() == true){
		GPIO_PortSet(GPIOB, 1u << PIN11);
		flag1 = true;
		while(flag1 == true){
			printf("L4: %d",L4);
			printf("C1: %d",C1);
			printf("C2: %d",C2);
			printf("C3: %d",C3);
			printf("C4: %d",C4);
			if(C1 == 0){
				printf("4\n");
				flag1 = false;
			}
			else if (C2 == 0){
				printf("5\n");
				flag1 = false;
			}
			else if (C3 == 0){
				printf("6\n");
				flag1 = false;
			}
			else if (C4 == 0){
				printf("B\n");
				flag1 = false;
			}
		}
		PIT_Flag_Set_PIT();
		GPIO_PortClear(GPIOB, 1u << PIN11);
		printf("L4: %d",L4);
		printf("C1: %d",C1);
		printf("C2: %d",C2);
		printf("C3: %d",C3);
		printf("C4: %d",C4);
	}
}

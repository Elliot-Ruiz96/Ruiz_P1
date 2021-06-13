#include "Keyboard_Matrix.h"

void Read_KeyPad(L1, L2, L3, L4, C1, C2, C3, C4){

	GPIO_PortSet(GPIOB, 1u << PIN2);
	if(C1 == 0){
		printf("1\n");
	}
	else if(C2 == 0){
		printf("2\n");
	}
	else if(C3 == 0){
		printf("3\n");
	}
	else if(C4 == 0){
		printf("A\n");
	}
	GPIO_PortClear(GPIOB, 1u << PIN2);

	GPIO_PortSet(GPIOB, 1u << PIN3);
	if(C1 == 0){
		printf("4\n");
	}
	else if(C2 == 0){
		printf("5\n");
	}
	else if(C3 == 0){
		printf("6\n");
	}
	else if(C4 == 0){
		printf("B\n");
	}
	GPIO_PortClear(GPIOB, 1u << PIN3);

	GPIO_PortSet(GPIOB, 1u << PIN10);
	if(C1 == 0){
		printf("7\n");
	}
	else if(C2 == 0){
		printf("8\n");
	}
	else if(C3 == 0){
		printf("9\n");
	}
	else if(C4 == 0){
		printf("C\n");
	}
	GPIO_PortClear(GPIOB, 1u << PIN10);

	GPIO_PortSet(GPIOB, 1u << PIN11);
	if(C1 == 0){
		printf("*\n");
	}
	else if(C2 == 0){
		printf("0\n");
	}
	else if(C3 == 0){
		printf("#\n");
	}
	else if(C4 == 0){
		printf("D\n");
	}
	GPIO_PortClear(GPIOB, 1u << PIN11);

}

#include "Keyboard_Matrix.h"

void Read_KeyPad(L1, L2, L3, L4, C1, C2, C3, C4, B1, B2){
	printf("L1: %d \n", L1);
	printf("L2: %d \n", L2);
	printf("L3: %d \n", L3);
	printf("L4: %d \n", L4);
	printf("C1: %d \n", C1);
	printf("C2: %d \n", C2);
	printf("C3: %d \n", C3);
	printf("C4: %d \n", C4);
	printf("B1: %d \n", B1);
	printf("B2: %d \n", B2);

	 if(L1 == 0 && C1 == 0){
		 printf("1\n");
	 }
	 else if(L1 == 0 && C2 == 0){
		 printf("2\n");
	 }
	 else if(L1 == 0 && C3 == 0){
		 printf("3\n");
	 }
	 else if(L1 == 0 && C4 == 0){
		 printf("A\n");
	 }
	 else if(L2 == 0 && C1 == 0){
		 printf("4\n");
	 }
	 else if(L2 == 0 && C2 == 0){
		 printf("5\n");
	 }
	 else if(L2 == 0 && C3 == 0){
		 printf("6\n");
	 }
	 else if(L2 == 0 && C4 == 0){
		 printf("B\n");
	 }
	 else if(L3 == 0 && C1 == 0){
		 printf("7\n");
	 }
	 else if(L3 == 0 && C2 == 0){
		 printf("8\n");
	 }
	 else if(L3 == 0 && C3 == 0){
		 printf("9\n");
	 }
	 else if(L3 == 0 && C4 == 0){
		 printf("C\n");
	 }
	 else if(L4 == 0 && C1 == 0){
		 printf("*\n");
	 }
	 else if(L4 == 0 && C2 == 0){
		 printf("0\n");
	 }
	 else if(L4 == 0 && C3 == 0){
		 printf("#\n");
	 }
	 else if (L4 == 0 && C4 == 0){
		 printf("D\n");
	 }
	 else
	{
		 printf("Hello World!\n");
	}

}

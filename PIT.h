
#ifndef PIT_H_
#define PIT_H_

#include "fsl_pit.h"

uint8_t PIT_Flag_get_PIT(void);
void PIT0_IRQHandler(void);
void PIT_Flag_Set_PIT(void);
void PIT_Initialize();

uint8_t PIT_Flag_get_PIT1(void);
void PIT1_IRQHandler(void);
void PIT_Flag_Set_PIT1(void);
void PIT1_Initialize();

void PIT_Start(total);

#endif /* PIT_H_ */

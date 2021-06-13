
#ifndef PIT_H_
#define PIT_H_

#include "fsl_pit.h"

uint8_t PIT_Flag_get_PIT(void);

void PIT0_IRQHandler(void);

void PIT_Flag_Set_PIT(void);

#endif /* PIT_H_ */

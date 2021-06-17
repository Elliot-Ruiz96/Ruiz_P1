#include "DAC.h"

uint32_t dacValue;

void DAC_Config(){
	dac_config_t dacConfigStruct;
	DAC_GetDefaultConfig(&dacConfigStruct);
	DAC_Init(DAC_BASEADDR, &dacConfigStruct);
    DAC_Enable(DAC_BASEADDR, true);
    DAC_SetBufferReadPointer(DAC_BASEADDR, 0U);
}

void DAC_Start(value){
	dacValue = value;
    if (dacValue > 4095)
    {
        printf("Valor fuera de rango\n");
    }
    DAC_SetBufferValue(DAC_BASEADDR, 0U, dacValue);
    /*
     * The value in the first item would be converted. User can measure the output voltage from DAC_OUTx pin.
     */
}

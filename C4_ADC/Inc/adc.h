/*
 * adc.h
 *
 *  Created on: Jan 7, 2026
 *      Author: naman
 */


#include "adc.h"

/* Configure PC2 as analog pin */
void PC2_analog_init()
{
    /* Enable GPIOC clock */
    RCC->AHB1ENR |= (1 << 2);

    /* Set PC2 to analog mode (MODER = 11) */
    GPIOC->MODER |= (3 << (2 * 2));
}

/* ADC initialization */
void ADC_init()
{
    /* Enable ADC1 clock */
    RCC->APB2ENR |= (1 << 8);

    /* ADC ON */
    ADC1->CR2 |= (1 << 0);
}

/* Start ADC conversion */
void ADC_start_conversion()
{
    /* Select channel 12 (PC2) */
    ADC1->SQR3 = 12;

    /* Start conversion */
    ADC1->CR2 |= (1 << 30);
}

/* Read ADC value */
uint32_t ADC_read()
{
    /* Wait until conversion complete */
    while (!(ADC1->SR & (1 << 1)));

    /* Return ADC data */
    return ADC1->DR;
}

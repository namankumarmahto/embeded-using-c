#include <stdint.h>
#include "stm32f4xx.h"

/* =============== Macros =============== */
#define Vref        3.3f
#define ADC_Max     4095.0f
#define V25         0.76f
#define Avg_Slope   0.0025f

/* ========== Function Prototypes ========= */
void ADC_init(void);
void ADC_read(void);
void read_temp(void);

/* ========== Global Variables ============ */
float temp;
uint32_t ADC_val;

/* ================= main ================= */
int main(void)
{
    uint32_t lp;

    ADC_init();

    while (1)
    {
        ADC_read();

        for (lp = 0; lp < 50000; lp++);   // delay (MUST be there)

        read_temp();
    }
}

/* ============ ADC Initialization ========= */
void ADC_init(void)
{
    /* Enable clock access to ADC1 */
    RCC->APB2ENR |= (1 << 8);

    /* ADC prescaler = PCLK2 / 2 */
    ADC->CCR &= ~(3 << 16);

    /* Enable temperature sensor */
    ADC->CCR |= (1 << 23);

    /* Select channel 16 */
    ADC1->SQR3 = 16;

    /* Sampling time = 480 cycles (channel 16) */
    ADC1->SMPR1 &= ~(7 << 18);
    ADC1->SMPR1 |=  (7 << 18);

    /* Enable ADC */
    ADC1->CR2 |= (1 << 0);
}

/* =============== ADC Read ================ */
void ADC_read(void)
{
    /* Start conversion */
    ADC1->CR2 |= (1 << 30);

    /* Wait till conversion complete */
    while (!(ADC1->SR & (1 << 1)));

    /* Read ADC value */
    ADC_val = ADC1->DR;
}

/* ========== Temperature Calculation ===== */
void read_temp(void)
{
    float Vsense;

    Vsense = ADC_val * (Vref / ADC_Max);

    temp = ((Vsense - V25) / Avg_Slope) + 25.0f;
}

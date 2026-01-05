#include <stdint.h>
#include "stm32f4xx.h"

/* Function prototypes */
void PC6_PC8_PWM_Config(void);
void TIM3_Config(void);
void TIM3_DutyCycle(uint32_t period, uint8_t DutyCycle);

/* Global */
uint8_t Percentage_DutyCycle_Change = 5;

int main(void)
{
    uint32_t PWM_Period = 1000, count = 0, LC = 0;

    PC6_PC8_PWM_Config();
    TIM3_Config();

    /* Enable TIM3 counter */
    TIM3->CR1 |= (1 << 0);

    while (1)
    {
        /* Increase duty cycle */
        for (LC = 0; LC <= (100 / Percentage_DutyCycle_Change); LC++)
        {
            TIM3_DutyCycle(PWM_Period, LC * Percentage_DutyCycle_Change);
            for (count = 0; count < 100000; count++);
        }

        /* Decrease duty cycle */
        for (LC = (100 / Percentage_DutyCycle_Change); LC > 0; LC--)
        {
            TIM3_DutyCycle(PWM_Period, LC * Percentage_DutyCycle_Change);
            for (count = 0; count < 100000; count++);
        }
    }
}

/* ================= GPIO CONFIG =================
   PC6 → TIM3_CH1
   PC8 → TIM3_CH3
*/
void PC6_PC8_PWM_Config(void)
{
    /* Enable GPIOC clock */
    RCC->AHB1ENR |= (1 << 2);

    /* Set PC6 & PC8 to Alternate Function mode */
    GPIOC->MODER &= ~((3 << 12) | (3 << 16));
    GPIOC->MODER |=  ((2 << 12) | (2 << 16));

    /* Select AF2 (TIM3) */
    GPIOC->AFR[0] |= (2 << 24);   // PC6
    GPIOC->AFR[1] |= (2 << 0);    // PC8
}

/* ================= TIM3 PWM CONFIG ================= */
void TIM3_Config(void)
{
    /* Enable TIM3 clock */
    RCC->APB1ENR |= (1 << 1);

    TIM3->PSC = 0;

    /* PWM Mode 1 */
    TIM3->CCMR1 |= (6 << 4);    // CH1
    TIM3->CCMR2 |= (6 << 4);    // CH3

    /* Preload enable */
    TIM3->CCMR1 |= (1 << 3);
    TIM3->CCMR2 |= (1 << 3);

    /* Enable outputs */
    TIM3->CCER |= (1 << 0);     // CH1 enable
    TIM3->CCER |= (1 << 8);     // CH3 enable
}

/* ================= DUTY CYCLE ================= */
void TIM3_DutyCycle(uint32_t period, uint8_t DutyCycle)
{
    TIM3->ARR  = 16000000U / period;
    TIM3->CCR1 = (DutyCycle * TIM3->ARR) / 100U;   // PC6
    TIM3->CCR3 = (DutyCycle * TIM3->ARR) / 100U;   // PC8
}

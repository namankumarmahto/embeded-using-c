#include <stdint.h>
#include "stm32f4xx.h"

/* Function prototyping */
void PA5_PWM_Config(GPIO_TypeDef *GPIO, uint8_t PIN);
void TIM2_Config(void);
void TIM2_DutyCycle(uint32_t count, uint8_t DutyCycle);

/* Global declarations */
uint8_t Percentage_DutyCycle_Change = 5;

int main(void)
{
    uint32_t PWM_Period = 1000, count = 0, LC = 0;

    PA5_PWM_Config(GPIOA, 5);
    TIM2_Config();

    /* Enable TIM2 counter */
    TIM2->CR1 |= (1 << 0);

    while (1)
    {
        /* Increase duty cycle */
        for (LC = 0; LC < (100 / Percentage_DutyCycle_Change); LC++)
        {
            TIM2_DutyCycle(PWM_Period, (uint8_t)(LC * Percentage_DutyCycle_Change));
            for (count = 0; count < 100000; count++);   // small delay
        }

        /* Decrease duty cycle */
        for (LC = (100 / Percentage_DutyCycle_Change); LC > 0; LC--)
        {
            TIM2_DutyCycle(PWM_Period, (uint8_t)(LC * Percentage_DutyCycle_Change));
            for (count = 0; count < 100000; count++);   // small delay
        }
    }
}

/* GPIO Config for PWM (PA5 -> AF1 -> TIM2_CH1) */
void PA5_PWM_Config(GPIO_TypeDef *GPIO, uint8_t PIN)
{
    /* Enable GPIOA clock */
    RCC->AHB1ENR |= (1 << 0);

    /* Set PA5 to Alternate Function mode (MODER5 = 10) */
    GPIO->MODER &= ~(3U << (PIN * 2));
    GPIO->MODER |=  (2U << (PIN * 2));   // 10

    /* Select AF1 for PA5 (TIM2) -> AFRL5 = 0001 */
    GPIO->AFR[0] &= ~(0xFU << (PIN * 4));
    GPIO->AFR[0] |=  (1U   << (PIN * 4));
}

/* TIM2 Configuration for PWM on CH1 */
void TIM2_Config(void)
{
    /* Enable TIM2 clock */
    RCC->APB1ENR |= (1 << 0);

    TIM2->PSC = 0;

    /* OC1 preload enable */
    TIM2->CCMR1 |= (1 << 3);

    /* PWM Mode 1 on CH1 (OC1M = 110 -> bits 6:4) */
    TIM2->CCMR1 |= (6 << 4);

    /* Enable capture/compare 1 output */
    TIM2->CCER |= (1 << 0);
}

/* Duty cycle calculation */
void TIM2_DutyCycle(uint32_t count, uint8_t DutyCycle)
{
    TIM2->ARR  = 16000000U / count;
    TIM2->CCR1 = (DutyCycle * TIM2->ARR) / 100U;
}

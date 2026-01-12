#include <stdint.h>
#include "stm32f4xx.h"

/* ================= Macros ================= */
#define INPUT   1
#define OUTPUT  0

/* ========== Function Prototypes ========== */
void GPIO_init(GPIO_TypeDef *GPIO, uint8_t PIN_No, uint8_t Mode);
void TIM2_init(void);

/* ===== NVIC Register Pointer ===== */
uint32_t volatile *pNVICIRQEnReg = (uint32_t*)0xE000E100;

/* ================= main ================= */
int main(void)
{
    GPIO_init(GPIOA, 5, OUTPUT);   // PA5 LED
    TIM2_init();                  // Timer init

    *pNVICIRQEnReg |= (1 << 28);   // Enable TIM2 interrupt in NVIC
    TIM2->CR1 |= (1 << 0);         // Start TIM2

    while (1);                     // Infinite loop
}

/* ============= GPIO Init ============== */
void GPIO_init(GPIO_TypeDef *GPIO, uint8_t PIN_No, uint8_t Mode)
{
    RCC->AHB1ENR |= (1 << 0);      // Enable GPIOA clock

    if (Mode == OUTPUT)
    {
        GPIO->MODER |= (1 << (2 * PIN_No));
    }
}

/* ============= TIM2 Init ============== */
void TIM2_init(void)
{
    RCC->APB1ENR |= (1 << 0);      // Enable TIM2 clock

    TIM2->PSC = 16000 - 1;         // Prescaler
    TIM2->ARR = 1000 - 1;          // Auto reload
    TIM2->CNT = 0;

    TIM2->DIER |= (1 << 0);        // Update interrupt enable
}

/* ========== TIM2 Interrupt Handler ========== */
void TIM2_IRQHandler(void)
{
    TIM2->SR &= ~(1 << 0);         // Clear interrupt flag
    GPIOA->ODR ^= (1 << 5);        // Toggle LED
}

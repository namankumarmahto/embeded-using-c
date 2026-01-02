
#include <stdint.h>
#include <stm32f4xx.h>

//Function prototyping
void GPIO_init();
void Timer_init();
void Timer_delay();

int main(void)
{
    GPIO_init();
    Timer_init();
    /* Loop forever */
}

//GPIO Initialization
void GPIO_init()
{
    RCC->AHB1ENR |= (1<<0); //Enable GPIOA clock
    GPIOA->MODER &= ~(3<<10); //Reset both bits of GPIOA.5
    GPIOA->MODER |= (1<<10); //Configure GPIOA.5 as output
}


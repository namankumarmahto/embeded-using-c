

#include <stdint.h>
#include "stm32f4xx_hal.h"

//Global declarations
uint8_t Percentage_DutyCycle_Change = 5;
int main(void)
{
    uint32_t PWM_Period = 1000,count=0,LC=0;
    PA5_PWM_Config(GPIOA,5);
    TIM2_Config();
    TIM2->CR1 |= (1<<0);

    /* Loop forever */
    while(1){
        for (LC=0;LC<100/Percentage_DutyCycle_Change;LC++)
        {
            TIM2_DutyCycle(PWM_Period,LC*Percentage_DutyCycle_Change);
            for (count=0;count)
        }
    }
}

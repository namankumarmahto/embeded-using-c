#include <stdint.h>

// Base addresses
#define RCC_Base     0x40023800
#define GPIOA_Base   0x40020000
#define GPIOC_Base   0x40020800

// Register pointers
uint32_t *RCCAHB1     = (uint32_t*)(RCC_Base + 0x30);
uint32_t *GPIOA_Moder = (uint32_t*)(GPIOA_Base + 0x00);
uint32_t *GPIOC_Moder = (uint32_t*)(GPIOC_Base + 0x00);
uint32_t *GPIOA_ODR   = (uint32_t*)(GPIOA_Base + 0x14);
uint32_t *GPIOC_IDR   = (uint32_t*)(GPIOC_Base + 0x10);

// Function prototype
void GPIO_init();

int main(void)
{
	GPIO_init();

/*	while(1)
	{
		if(*GPIOC_IDR & (1<<13))   // Button pressed
		{
			*GPIOA_ODR |= (1<<5); // LED ON
		}
		else
		{
			*GPIOA_ODR &= ~(1<<5); // LED OFF
		}
	}
*/
	while(1)
	{
	    if( !(*GPIOC_IDR & (1<<13)) )   // Button PRESSED (active low)
	    {
	        *GPIOA_ODR |= (1<<5);       // LED ON
	    }
	    else
	    {
	        *GPIOA_ODR &= ~(1<<5);      // LED OFF
	    }
	}

}

// GPIO initialization
void GPIO_init()
{
	// Enable clocks
	*RCCAHB1 |= (1<<0); // GPIOA clock
	*RCCAHB1 |= (1<<2); // GPIOC clock

	// GPIOA pin 5 → OUTPUT
	*GPIOA_Moder &= ~(1<<11);
	*GPIOA_Moder |=  (1<<10);

	// GPIOC pin 13 → INPUT
	*GPIOC_Moder &= ~(1<<26);
	*GPIOC_Moder &= ~(1<<27);
}

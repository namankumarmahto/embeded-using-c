#include <stdint.h>

//Macro Definition
#define RCC_Base 0x40023800
#define GPIOC_Base 0x40020800

//Declaration of pointers
uint32_t  *AHB1ENR = (uint32_t*)(RCC_Base + 0x30);
uint32_t *GPIOC_Moder = (uint32_t*) (GPIOC_Base + 0x00);
uint32_t *GPIOC_IDR = (uint32_t*) (GPIOC_Base + 0x10);
uint32_t *GPIOC_ODR = (uint32_t*) (GPIOC_Base + 0x14);


//Function prototyping
void GPIO_init();
void unpack(uint8_t);
void bit_porting();

//Global variable declarations
uint8_t b0=0, b1=0, b2=0, b3=0;
uint8_t mod = 16;


int main(void)
{
	uint32_t count = 0;
	GPIO_init();
	//Infinite loopif
	while(1)
	{
		if(!(*GPIOC_IDR & (1<<13)))
		{
			while(!(*GPIOC_IDR & (1<<13)));
			if(count < (mod - 1))
			{
				count++;
			}
			else
			{
				count=0;
			}
		}
		unpack(count);
		bit_porting();
	}
}

//GPIO initialization function
void GPIO_init()
{
	*AHB1ENR |= (1<<2);
	*GPIOC_Moder &= ~(1<<26);
	*GPIOC_Moder &= ~(1<<27);
	*GPIOC_Moder = (1<<0) | (1<<2) | (1<<4) | (1<<6);
}

//Unpacking digits into bits
void unpack(uint8_t val)
{
	b0 = val & 0x1;
	b1 = val & 0x2;
	b2 = val & 0x4;
	b3 = val & 0x8;
}

void bit_porting()
{
	if(b0)
	{
		*GPIOC_ODR |= (1<<0);
	}
	else
	{
		*GPIOC_ODR &= ~(1<<0);
	}
	if(b1)
	{
		*GPIOC_ODR |= (1<<1);
	}
	else
	{
		*GPIOC_ODR &= ~(1<<1);
	}
	if(b2)
	{
		*GPIOC_ODR |= (1<<2);
	}
	else
	{
		*GPIOC_ODR &= ~(1<<2);
	}
	if(b3)
	{
		*GPIOC_ODR |= (1<<3);
	}
	else
	{
		*GPIOC_ODR &= ~(1<<3);
	}
}

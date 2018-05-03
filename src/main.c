#include <LED.H>
#include "stm32f10x.h"
void delay2();
int main()
{
	LedInit();
	while(1){
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
		GPIO_SetBits(GPIOE, GPIO_Pin_4);

		delay2();
		GPIO_ResetBits(GPIOE,  GPIO_Pin_3);

		GPIO_ResetBits(GPIOE,  GPIO_Pin_4);
	delay2();

	}

}
void delay2(void)
{
	u32 cnt;
	for(cnt=6000000;cnt>0;cnt--);
}

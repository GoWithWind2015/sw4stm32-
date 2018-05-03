#include "LED.H"

void LedInit(void)//LED相关IO初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE |  RCC_APB2Periph_GPIOC, ENABLE);//使能GPIOA时钟

	IsLed1On(NO);//关LED1
	IsLed2On(NO);
	IsLed3On(NO);
	IsLed4On(NO);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速率50M
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_10;
	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化
}

void delay(void)
{
	u32 cnt;
	for(cnt=6000000;cnt>0;cnt--);
}

void LedTest(void)
{
	IsLed1On(YES);//开LED1
	delay();
	IsLed2On(YES);
	delay();
	IsLed3On(YES);
	delay();
	IsLed4On(YES);
	delay();
	IsLed1On(NO);//关LED1
	delay();
	IsLed2On(NO);
	delay();
	IsLed3On(NO);
	delay();
	IsLed4On(NO);
	delay();
}

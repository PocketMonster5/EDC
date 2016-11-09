#include "sys.h"
#include "delay.h"
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TimOCInitStructure;
int main(void)
{
      
 delay_init();
 
 void rcc_cfg();
 void gpio_cfg();
 void tim2_cfg();
 void pwm_cfg();
	
  while (1)
  {
   
    GPIO_WriteBit(GPIOA, GPIO_Pin_8, Bit_SET);
 
		delay_ms(1);
   
    GPIO_WriteBit(GPIOA, GPIO_Pin_8, Bit_RESET);
 
    delay_ms(1);
  }
}
 
void gpio_cfg()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void tim2_cfg()
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  TIM_DeInit(TIM2);
  TIM_InternalClockConfig(TIM2);
  TIM_TimeBaseStructure.TIM_Prescaler = 72;
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 1000-1;
  TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
  TIM_ARRPreloadConfig(TIM2, DISABLE);
 
  TIM_Cmd(TIM2, ENABLE); 
}
 
void pwm_cfg()
{
       TIM_OCStructInit(&TimOCInitStructure);
       TimOCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
       TimOCInitStructure.TIM_Pulse = 400-1;
       TimOCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
       TimOCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
       TIM_OC2Init(TIM2, &TimOCInitStructure);
       TIM_CtrlPWMOutputs(TIM2,ENABLE);
}

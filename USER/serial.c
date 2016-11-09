
#include <stm32f10x.h> 


	
void RCC_Config(void);
void GPIO_Config(void);
void USART_Config(void);
void NVIC_Config(void);
void RCC_Init();

int main(void)
{   
	
  GPIO_InitTypeDef GPIO_InitStructure;	
  USART_InitTypeDef USART_InitStructure;  

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);  
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(GPIOD, &GPIO_InitStructure);  
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;  
	GPIO_Init(GPIOD, &GPIO_InitStructure);  
		
	GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  

	USART_InitStructure.USART_BaudRate = 9600;  
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  
	USART_InitStructure.USART_StopBits = USART_StopBits_1;  
	USART_InitStructure.USART_Parity = USART_Parity_No;  
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  
	USART_Init(USART2, &USART_InitStructure );   

	USART_Cmd(USART2, ENABLE); 
	USART_Init(USART2, &USART_InitStructure);
    RCC_Init();
    GPIO_Config();
    NVIC_Config();
    USART_Config();

     while(1){
			 if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)//????????????
   {


     USART_SendData(USART1,'s');

     while (USART_GetFlagStatus (USART1,USART_FLAG_TXE)!=RESET);//???????
     USART_ClearITPendingBit(USART1,USART_IT_RXNE);//???????
   }
 }
}
void RCC_Init()
{   

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); 
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
}
void GPIO_Config(void)
{
    //configure USARTx_Tx as alternate function push-pull//
    GPIO_InitTypeDef GPIO_InitStructure; 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);



    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
   void NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
void USART_Config (void)
{
  USART_InitTypeDef USART_InitStructure;
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //?????????
  USART_Cmd(USART1,ENABLE);
  USART_Init(USART1, &USART_InitStructure);

}

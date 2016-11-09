#include "delay.h"
#include "move.h"
#include "sensor.h"
#include "function.h"
#include "data.h"

static short int isout=0;

int main(){
	
 GPIO_InitTypeDef GPIO_InitStructure;	
		
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //A for motor
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//B for sensor
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);		//D for test
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //PD02, test LED
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //OUTPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOD, &GPIO_InitStructure);					 //
 GPIO_SetBits(GPIOD,GPIO_Pin_2);						 //LOW
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //PA00, OUT1
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //OUTPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //
 GPIO_SetBits(GPIOA,GPIO_Pin_0);						 //HIGH

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //PA01, OUT2
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //OUTPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //
 GPIO_SetBits(GPIOA,GPIO_Pin_1);						 //HIGH

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //PA02, OUT3
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //OUTPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //
 GPIO_SetBits(GPIOA,GPIO_Pin_2);						 //HIGH
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				 //PA03, OUT4
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //OUTPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //
 GPIO_SetBits(GPIOA,GPIO_Pin_3);						 //HIGH
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //PB00, SENSOR1
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //INPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //PB01, SENSOR2
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //INPUT
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO 50Hz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //

	delay_init();
	status=4;
	delay_ms(3000);
	 while(status--){
		 Forward();
		 delay_ms(5000);
		 Right();
     delay_ms(320);
	 }
	 status=4;
	 Right();
	 delay_ms(400);
	 while(status--){
		 Forward();
		 delay_ms(5000);
		 Left();
     delay_ms(320);
	 }
	 Stop();
 }

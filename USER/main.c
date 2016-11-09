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
	status=1;
	delay_ms(3000);
 while(status){
	 GetData();
	 isout=IsBorder(x_now,y_now);
	 if(isout){
		 switch(isout){
			 case 1:
				 To(5,y_now);
			 break;
			 case 2:
				 To(250,y_now);
			 break;
			 case 3:
				 To(x_now,5);
			 break;
			 default:
				 To(x_now,250);
		 }
	 }
	 else if(is_destination)
		 To(x_destination, y_destination);
	 else if(is_item)
		 To(x_item, y_item);
	 else
		 To(128,128);
	 delay_ms(100);
	 }
 }


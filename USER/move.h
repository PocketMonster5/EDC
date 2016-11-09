#ifndef _MOVE_H
#define _MOVE_H
#include "sys.h"
#include "data.h"
#include "function.h"
#include "delay.h"

short int delta=5;

void Backward(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void Forward(){
	 GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void Stop(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void Left(){
	 GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void Right(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void LeftForward(){
	 GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void RightForward(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void LeftBackward(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_SetBits(GPIOA,GPIO_Pin_1);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void RightBackward(){
	 GPIO_SetBits(GPIOA,GPIO_Pin_0);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	 GPIO_SetBits(GPIOA,GPIO_Pin_2);
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);
}

void Move(short int x, short int y){
	short int dx=x_now-x_previous;
	short int dy=y_now-y_previous;
	short int r=(Abs(dx)>Abs(dy)?Abs(dx):Abs(dy));
 	static short int flag=1;
	flag*=((Dx*Dx+Dy*Dy)<(Dx_previous*Dx_previous+Dy_previous*Dy_previous)?1:-1);
	switch((x<<=2)*flag+y*flag){
		case 4:
			Right();
		break;
		case 5:
			RightForward();
		break;
		case 1:
			Forward();
		break;
		case -3:
			LeftForward();
		break;
		case -4:
			Left();
		break;
		case -5:
			LeftBackward();
		break;
		case -1:
			Backward();
			delay_ms(100);
		break;
		case 3:
			RightBackward();
		break;
		default:
			Stop();
	}
	x_previous=x_now;
	y_previous=y_now;
	x_now+=(dx*y+dy*x)/r;
	y_now+=(dy*y-dx*x)/r;
}
		
void To(short int x, short int y){		//move to x, y
	short int dx, dy, Dx1, Dy1, k1;
	dx=x_now-x_previous;
	dy=y_now-y_previous;
	if((++count)%2==0){
		Dx_previous=Dx;
		Dy_previous=Dy;
	}
	Dx=x-x_now;
	Dy=y-y_now;
	if(dx==0 && dy==0){
		if(Dx==0 && Dy==0){
			Move(0,0);
			return;
		}
		else
			To(x_now+5, y_now+5);		//stops when not arrive at the destination; needs to be improved
	}
	Dx1=Dx*dy-Dy*dx;
	Dy1=Dx*dx+Dy*dy;		//Dx1==0!
	if(Dx1==0)
		Move(0,(Dy1>0?1:-1));
	else{
		k1=Dy1/Dx1;		//it won't exceed if short
		Dx1>0?Dx1=1:(Dx1==0?Dx1=0:(Dx1=-1));
		Dy1>0?Dy1=1:(Dy1==0?Dy1=0:(Dy1=-1));
		if((k1>delta)||(k1<-delta))		//if the deviation is not so bad, go straight
			Move(0,Dy1);
		else
			Move(Dx1,Dy1);
	}
}

#endif

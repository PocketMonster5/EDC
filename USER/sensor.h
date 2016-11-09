#ifndef _SENSOR_H
#define _SENSOR_H
#include "sys.h"
#include "move.h"

int IsBlack(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){		//1 for black
	return GPIO_ReadInputDataBit(GPIOx,GPIO_Pin);
}

//Make a choice based on several Isblack()
	
int IsDetected(short int flag1, short int flag2, short int flag3){
	//the function needs to be polished; first, when to move and turn and when to turn only; second, how to make use of the map
	if(flag1==1 && flag2==1 && flag3==1)
		return 1;
	else
		return 0;
}

#endif

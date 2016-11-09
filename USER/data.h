#ifndef _Data_H
#define _Data_H
#include "sys.h"

static short int status=1, 
 color_destination, is_destination,
 x_now=0x90, y_now=0x83, x_previous=-1, y_previous=-1,
 x_rival, y_rival, 
 x_destination=128, y_destination=128, 
 Dx, Dy, 
 Dx_previous=255, Dy_previous=255, count=0, 
 hp, hp_rival, 
 is_item,
 x_item, y_item,
 list[18][8];

void GetData(){		//get and analyze the data
	//list
	is_destination=1;
	is_item=0;
/*	status=list[0][1]*2+list[0][0];
	is_destination=list[1][1];
	is_item=list[15][7]*2+list[15][6];
	x_now=0, y_now=0;
	x_destination=0, y_destination=0;
	x_item=0, y_item=0;
	for(int i=0;i<8;i++){
		x_now+=list[2][i]<<i;
		y_now+=list[3][i]<<i;
		x_destination+=list[6][i]<<i;
		y_destination+=list[7][i]<<i;
		x_item+=list[12][i]<<i;
		y_item+=list[13][i]<<i;
	};
		
	x_previous=x_now;
	y_previous=y_now;
	
	*/
}

void SendData(){
	
}

#endif

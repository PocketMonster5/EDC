#ifndef _FUNCTION_H
#define _FUNCTION_H


short int Abs(short int x){
	return x>0?x:-x;
}

int IsBorder(unsigned short int x, unsigned short int y){
	//judge if in border. left for 1, right for 2, down for 3 and up for 4
	if(x<1)
		return 1;		//case 1: left
	else if(254<x)
		return 2;		//case 2: right
	else if(y<1)
		return 3;		//case3: down
	else if(254<y)
		return 4;		//case4: up
	else
		return 0;
}

int JudgeAim(int x, int y, int x_rival, int y_rival, int x_destination, int y_destination,int x_item, int y_item){
	//here we need to make a decision which aim should we focus on based on the 4 pairs of coordinates
	//the infomation of the map can also be included if necessary
	return 0;
}

#endif

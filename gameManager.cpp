//
// Created by Elaina on 2024/5/16.
//
#include <iomanip>
#include "gameManager.h"
void warCraft::gameStart() {
	while (1){
		if(!red.stop) {
			std::cout<<std::setw(3)<<std::setfill('0')<<(event-1)%1000<<" ";
			red.produce(event);
		}
		if(!blue.stop) {
			std::cout<<std::setw(3)<<std::setfill('0')<<(event-1)%1000<<" ";
			blue.produce(event);
		}
		if(red.stop&&blue.stop)
			break;
		event++;
	}


}
warCraft::warCraft(int sp):
red(sp,"red",redOrder),
blue(sp,"blue",blueOrder)
{


}
void warCraft::hpSet(int dragon, int ninja, int iceman, int lion, int wolf) {
	dragon::preHp = dragon;
	ninja::preHp = ninja;
	iceman::preHp = iceman;
	lion::preHp = lion;
	wolf::preHp = wolf;
}

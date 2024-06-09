//
// Created by Elaina on 2024/5/16.
//
#include <iomanip>
#include "gameManager.h"
void warCraft::gameStart() {
	while (1){
		if(!red.stop) {
			std::cout << std::setw(3) << std::setfill('0') << Time%1000 << " ";
			red.produce(Time);
		}
		if(!blue.stop) {
			std::cout << std::setw(3) << std::setfill('0') << Time%1000 << " ";
			blue.produce(Time);
		}
		if(red.stop&&blue.stop)
			break;
		Time++;
	}


}
warCraft::warCraft(int sp):
red(sp,0,"red",redOrder,cityList),
blue(sp,cityNum+1,"blue",blueOrder,cityList)
{


}
void warCraft::hpSet(int dragon, int ninja, int iceman, int lion, int wolf) {
	dragon::preHp = dragon;
	ninja::preHp = ninja;
	iceman::preHp = iceman;
	lion::preHp = lion;
	wolf::preHp = wolf;
}
void warCraft::firstSet(int cityNum, int loyaltyDecrease) {
	cityList.resize(cityNum+2);
	for(int i=0;i<cityNum+2;i++){
		cityList[i].resize(2);
	}
}
void warCraft::eventControl() {
	//每个小时的第0分， 双方的司令部中各有一个武士降生
	red.produce(Time);
	blue.produce(Time);
	//在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
	red.lionRun(Time);
	blue.lionRun(Time);
	//在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
	//在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。
	//在每个小时的第40分：在有两个武士的城市，会发生战斗。
	//在每个小时的第50分，司令部报告它拥有的生命元数量。
	red.reportSp(Time);
	blue.reportSp(Time);
	//在每个小时的第55分，每个武士报告其拥有的武器情况。
	red.reportWeapon(Time);
	blue.reportWeapon(Time);
	//武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
	//任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
	//任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

}

//
// Created by Elaina on 2024/5/16.
//
#include <iomanip>
#include "gameManager.h"
#include "sstream"
void warCraft::gameStart() {

}
warCraft::warCraft(int sp,int cityNum,int loyaltyDecrease,int timeLimit)://这里的城市数量不包括司令部
cityNum(cityNum),
red(sp,0,cityNum+2,"red",redOrder,cityList,eventManager),
blue(sp,cityNum+1,cityNum+2,"blue",blueOrder,cityList,eventManager),
eventManager(cityNum,timeLimit)
{
	lion::setLoyaltyDecrease(loyaltyDecrease);

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
	while (1){
		//每个小时的第0分， 双方的司令部中各有一个武士降生
		red.produce(Time);
		blue.produce(Time);
		//在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
		red.lionRun(Time);
		blue.lionRun(Time);
		//在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
		if(red.warriorMove(Time) + blue.warriorMove(Time)){
			break;
		}

		//在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。
		red.wolfRob(Time);
		//在每个小时的第40分：在有两个武士的城市，会发生战斗。
		warriorTTK();
		//在每个小时的第50分，司令部报告它拥有的生命元数量。
		red.reportSp(Time);
		blue.reportSp(Time);
		//在每个小时的第55分，每个武士报告其拥有的武器情况。
		red.reportWeapon(Time);
		blue.reportWeapon(Time);
		//武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
		//任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
		//任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
		Time++;
	}
}
void warCraft::warriorTTK() {
	for(int i =1;i<cityNum+1;i++) {
		if(cityList[i][0]&&cityList[i][1]){//这个城市有两个武士
			auto redw = cityList[i][0];
			auto bluew = cityList[i][1];
			redw->sortWeapon();
			redw->backup();
			bluew->sortWeapon();
			if(i%2==1){//奇数城市红先攻击
				bool flag = 0;//这里的flag用来判断是否二者都至少进行了一次攻击
				while(1){
					redw->ttk(*bluew);
					if(judgeTTK(redw,bluew,flag))
						break;
					bluew->ttk(*redw);
					if(judgeTTK(redw,bluew,flag))
						break;
					flag = 1;
				}
			}
			else{
				bool flag = 0;
				while(1){
					bluew->ttk(*redw);
					if(judgeTTK(redw,bluew,flag))
						break;
					redw->ttk(*bluew);
					if(judgeTTK(redw,bluew,flag))
						break;
					flag = 1;
				}
			}//TODO:现在你大概写完了武士打架，检查一下有没有bug

		}
	}
}
bool warCraft::judgeTTK(warrior* redw, warrior* bluew,bool flag) {//结束了返回true
	if(redw->isDead()&&bluew->isDead()){
		//两败俱伤
		std::stringstream oss;
		oss << "both red" << redw->getName() << " " << redw->getId() << " and blue " << bluew->getName() << " " << bluew->getId() << " died in city " << redw->getCity() << std::endl;
		Event eve(Time,redw->getCity(),0,TTK,oss.str());
		eventManager.addEvent(eve);
		red.warriorDie(redw);
		blue.warriorDie(bluew);
		return 1;
	}
	else if(redw->isDead()){
		//red死了
		std::stringstream oss;
		oss << "blue " << bluew->getName() << " " << bluew->getId() << " killed red " << redw->getName() << " " << redw->getId() << " in city " << redw->getCity() << " remaining " << bluew->getHp() << " elements" << std::endl;
		Event eve(Time,redw->getCity(),0,TTK,oss.str());
		eventManager.addEvent(eve);
		red.warriorDie(redw);
		return 1;
	}
	else if(bluew->isDead()){
		//blue死了
		std::stringstream oss;
		oss << "red " << redw->getName() << " " << redw->getId() << " killed blue " << bluew->getName() << " " << bluew->getId() << " in city " << redw->getCity() << " remaining " << redw->getHp() << " elements" << std::endl;
		Event eve(Time,redw->getCity(),0,TTK,oss.str());
		eventManager.addEvent(eve);
		blue.warriorDie(bluew);
		return 1;
	}
	else{
		//都没死
		if(!redw->isInfluenced()&&!bluew->isInfluenced()&&flag){//无变化
			std::stringstream oss;
			oss << "both red " << redw->getName() << " " << redw->getId() << " and blue " << bluew->getName() << " " << bluew->getId() << " were alive in city " << redw->getCity() << std::endl;
			Event eve(Time,redw->getCity(),0,TTK,oss.str());
			eventManager.addEvent(eve);
			return 1;
		}
		return 0;
	}

}


//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__GAMEMANAGER_H_
#define WARCRAFT__GAMEMANAGER_H_
#include "iostream"
#include "warrior.h"
#include "headquarter.h"
#include "Event.h"
class warCraft {
 private:
	int Time = 0;
	int timeLimitHour;
	int cityNum;
	EventControl eventManager;//事件管理器
	std::vector<std::vector<warrior*>> cityList;//城市列表,2维数组,0代表红方,1代表蓝方
	std::vector<std::string> eventList;//事件列表,存储同一时间的事件,输出后清空
	const std::vector<warriorType> redOrder = {ICEMAN, LION, WOLF, NINJA, DRAGON};
	const std::vector<warriorType> blueOrder = {LION, DRAGON, NINJA, ICEMAN, WOLF};
	headquarter red;
	headquarter blue;
	void warriorTTK();//武士打架

	bool judgeTTK(warrior *redw,warrior*bluew,bool flag);//判断每次攻击后的结果,有人死了就输出处理,结束战斗了返回true
 public:
	void eventControl();//负责处理每个小时的事件
	void haha(){std::cout<<"haha"<<std::endl;}
	warCraft(int sp,int cityNum,int loyaltyDecrease,int timeLimit);
	void hpSet(int dragon, int ninja, int iceman, int lion, int wolf);
	void atkSet(int dragon, int ninja, int iceman, int lion, int wolf);
	void gameStart();
	void outputEvent();

};

#endif //WARCRAFT__GAMEMANAGER_H_

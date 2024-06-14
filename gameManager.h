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
	int cityNum;
	EventControl eventManager;//事件管理器
	std::vector<std::vector<warrior*>> cityList;//城市列表,2维数组,0代表红方,1代表蓝方
	std::vector<std::string> eventList;//事件列表,存储同一时间的事件,输出后清空
	const std::vector<warriorType> redOrder = {ICEMAN, LION, WOLF, NINJA, DRAGON};
	const std::vector<warriorType> blueOrder = {LION, DRAGON, NINJA, ICEMAN, WOLF};
	headquarter red;
	headquarter blue;
	void eventControl();//负责处理每个小时的事件
	void warriorTTK();//武士打架
	bool judgeTTK(warrior *redw,warrior*bluew,bool flag);//判断每次攻击后的结果,有人死了就输出处理,结束战斗了返回true
 public:
	warCraft(int sp,int cityNum,int loyaltyDecrease,int timeLimit);
	void firstSet(int cityNum, int loyaltyDecrease);
	void hpSet(int dragon, int ninja, int iceman, int lion, int wolf);
	void gameStart();
	//TODO:现在你写了几个输出的函数，但是没有处理在同一时间的事件，需要重新写，然后写武士移动和对战
	//TODO:需要写一个event管理的新类来管理每一个时间的事件，注意传递事件的方式，每一个事件都有它的类型，考虑使用引用
};

#endif //WARCRAFT__GAMEMANAGER_H_

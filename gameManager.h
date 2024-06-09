//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__GAMEMANAGER_H_
#define WARCRAFT__GAMEMANAGER_H_
#include "iostream"
#include "warrior.h"
#include "headquarter.h"

class warCraft {
 private:
	int Time = 0;
	int cityNum;
	int loyaltyDecrease;
	std::vector<std::vector<warrior*>> cityList;//城市列表,2维数组,0代表红方,1代表蓝方
	std::vector<std::string> eventList;//事件列表,存储同一时间的事件,输出后清空
	const std::vector<warriorType> redOrder = {ICEMAN, LION, WOLF, NINJA, DRAGON};
	const std::vector<warriorType> blueOrder = {LION, DRAGON, NINJA, ICEMAN, WOLF};
	headquarter red;
	headquarter blue;
 public:
	warCraft(int sp);
	void firstSet(int cityNum, int loyaltyDecrease);
	void hpSet(int dragon, int ninja, int iceman, int lion, int wolf);
	void gameStart();
	void eventControl();//负责处理每个小时的事件
	void outputAdd(int city,bool color,const std::string& event);//输出同一时间的事件,需要深拷贝
	//TODO:现在你写了几个输出的函数，但是没有处理在同一时间的事件，需要重新写，然后写武士移动和对战
	//TODO:需要写一个event管理的新类来管理每一个时间的事件，注意传递事件的方式，每一个事件都有它的类型，考虑使用引用
	void event();
	void move();
};

#endif //WARCRAFT__GAMEMANAGER_H_

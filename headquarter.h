//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__HEADQUARTER_H_
#define WARCRAFT__HEADQUARTER_H_
#include "warrior.h"
#include "map"
#include "vector"
#include "Event.h"
class headquarter {
 private:
	int sp;//生命元
	std::string color;//阵营
	bool colorFlag;//0代表红方,1代表蓝方
	int city;//所在城市
	const int cityNum;//城市数量
	int roll = 0;//当前生产的武士
	int id = 1;//生产的武士编号
	bool isStop = false;//是否停止生产

	std::vector<std::vector<warrior*>> & cityList;//城市列表引用
	EventControl& eventManager;//事件管理器引用
	const std::vector<warriorType> produceOrder;//生产顺序
	std::vector<warrior*> warriorList;//武士列表
	std::map<warriorType,int> warriorNum;//各种武士的数量
 public:
	bool stop = false;//是否停止生产
	headquarter(int sp,int city,int cityNum, const std::string& color, std::vector<warriorType> produceOrder,std::vector<std::vector<warrior*>> & cityList,EventControl& eventManager);
	void reportSp(int Time) const;
	void reportWeapon(int Time) const;
	void lionRun(int Time);
	void wolfRob(int Time);
	bool warriorMove(int Time);
	void warriorDie(warrior * w);//这里不输出
	int getSp() const{return sp;}
	void produce(int Time);
	bool isStopped(){return isStop;}
};

#endif //WARCRAFT__HEADQUARTER_H_

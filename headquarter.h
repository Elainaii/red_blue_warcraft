//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__HEADQUARTER_H_
#define WARCRAFT__HEADQUARTER_H_
#include "warrior.h"
#include "map"
#include "vector"
class headquarter {
 private:
	int sp;//生命元
	std::string color;//阵营
	int city;//所在城市
	int roll = 0;//当前生产的武士
	int id = 1;//生产的武士编号
	std::vector<std::vector<warrior*>> & cityList;//城市列表引用
	const std::vector<warriorType> produceOrder;//生产顺序
	std::vector<warrior*> warriorList;//武士列表
	std::map<warriorType,int> warriorNum;//各种武士的数量
 public:
	bool stop = false;//是否停止生产
	headquarter(int sp,int city, const std::string& color, std::vector<warriorType> produceOrder,std::vector<std::vector<warrior*>> & cityList);
	void reportSp(int Time) const{std::cout<<std::setw(3)<<std::setfill('0')<<Time%1000<<":"<<"50 "<<sp<<" elements in "<<color<<" headquarter"<<std::endl;}
	void reportWeapon(int Time) const;
	void lionRun(int Time);
	void warriorMove(int Time);
	void warriorDie(int Time);
	int getSp() const{return sp;}
	void produce(int Time);
};

#endif //WARCRAFT__HEADQUARTER_H_

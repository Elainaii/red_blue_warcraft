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
	int roll = 0;//当前生产的武士
	const std::vector<warriorType> produceOrder;//生产顺序
	std::vector<warrior*> warriorList;
	std::map<warriorType,int> warriorNum;//各种武士的数量
 public:
	bool stop = false;//是否停止生产
	headquarter(int sp, const std::string& color, std::vector<warriorType> produceOrder);
	void produce(int id);
};

#endif //WARCRAFT__HEADQUARTER_H_

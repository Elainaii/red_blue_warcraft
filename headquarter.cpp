//
// Created by Elaina on 2024/5/16.
//

#include "headquarter.h"
headquarter::headquarter(int sp, const std::string& color, std::vector<knightType> produceOrder) : sp(sp), color(color), produceOrder(produceOrder), roll(0) {
	for (int i = 0; i < produceOrder.size(); i++) {
		knightNum[produceOrder[i]] = 0;
	}
}
void headquarter::produce(int id) {
	int time = 5;
	while (time--) {//循环5次
		knightType k = produceOrder[roll%5];//获取现在该生产的武士
		knight * t;
		bool flag = false;//这一轮是否生产成功
		switch (k) {
		case DRAGON:
			if(sp>=dragon::preHp){
				t = new dragon(id);
				sp -= dragon::preHp;
				flag = true;
				knightNum[DRAGON]++;
				std::cout<<color<<" dragon "<<id<<" born with strength "<<dragon::preHp<<","<<knightNum[DRAGON]<<" dragon in "<<color<<" headquarter"<<std::endl;
			}
			break;
		case NINJA:
			if(sp>=ninja::preHp){
				t = new ninja(id);
				sp -= ninja::preHp;
				flag = true;
				knightNum[NINJA]++;
				std::cout<<color<<" ninja "<<id<<" born with strength "<<ninja::preHp<<","<<knightNum[NINJA]<<" ninja in "<<color<<" headquarter"<<std::endl;
			}
			break;
		case ICEMAN:
			if(sp>=iceman::preHp){
				t = new iceman(id);
				sp -= iceman::preHp;
				flag = true;
				knightNum[ICEMAN]++;
				std::cout<<color<<" iceman "<<id<<" born with strength "<<iceman::preHp<<","<<knightNum[ICEMAN]<<" iceman in "<<color<<" headquarter"<<std::endl;
			}
			break;
		case LION:
			if(sp>=lion::preHp){
				t = new lion(id);
				sp -= lion::preHp;
				flag = true;
				knightNum[LION]++;
				std::cout<<color<<" lion "<<id<<" born with strength "<<lion::preHp<<","<<knightNum[LION]<<" lion in "<<color<<" headquarter"<<std::endl;
			}
			break;
		case WOLF:
			if(sp>=wolf::preHp){
				t = new wolf(id);
				sp -= wolf::preHp;
				flag = true;
				knightNum[WOLF]++;
				std::cout<<color<<" wolf "<<id<<" born with strength "<<wolf::preHp<<","<<knightNum[WOLF]<<" wolf in "<<color<<" headquarter"<<std::endl;
			}
			break;
		}
		roll++;
		if(flag){
			knightList.push_back(t);//加入武士列表
			//knightNum[k]++;//该武士数量加1
			return;
		}
	}
	if(time == -1){
		stop = true;
		std::cout << color << " headquarter" << " stops making warriors" << std::endl;
	}
}

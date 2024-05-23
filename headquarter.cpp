//
// Created by Elaina on 2024/5/16.
//

#include <iomanip>
#include "headquarter.h"
headquarter::headquarter(int sp, const std::string& color, std::vector<warriorType> produceOrder) : sp(sp), color(color), produceOrder(produceOrder), roll(0) {
	for (int i = 0; i < produceOrder.size(); i++) {
		warriorNum[produceOrder[i]] = 0;
	}
}
void headquarter::produce(int id) {
	int time = 5;
	while (time--) {//循环5次
		warriorType k = produceOrder[roll%5];//获取现在该生产的武士
		warrior * t;
		bool flag = false;//这一轮是否生产成功
		switch (k) {
		case DRAGON:
			if(sp>=dragon::preHp){
				sp -= dragon::preHp;
				t = new dragon(id, (double)sp / dragon::preHp);
				auto temp = dynamic_cast<dragon*>(t);
				flag = true;
				warriorNum[DRAGON]++;
				std::cout<<color<<" dragon "<<id<<" born with strength "<<dragon::preHp<<","<<warriorNum[DRAGON]<<" dragon in "<<color<<" headquarter"<<std::endl;
				std::cout<<"It has a "<<temp->getWeapon().getType()<<" and it's morale is "<<std::fixed<<std::setprecision(2)<<temp->getMorale()<<std::endl;
			}
			break;
		case NINJA:
			if(sp>=ninja::preHp){
				t = new ninja(id);
				auto temp = dynamic_cast<ninja*>(t);
				sp -= ninja::preHp;
				flag = true;
				warriorNum[NINJA]++;
				std::cout<<color<<" ninja "<<id<<" born with strength "<<ninja::preHp<<","<<warriorNum[NINJA]<<" ninja in "<<color<<" headquarter"<<std::endl;
				std::cout<<"It has a "<<temp->getWeapon().getType()<<" and a "<<temp->getWeapon2().getType()<<std::endl;
			}
			break;
		case ICEMAN:
			if(sp>=iceman::preHp){
				t = new iceman(id);
				auto temp = dynamic_cast<iceman*>(t);
				sp -= iceman::preHp;
				flag = true;
				warriorNum[ICEMAN]++;
				std::cout<<color<<" iceman "<<id<<" born with strength "<<iceman::preHp<<","<<warriorNum[ICEMAN]<<" iceman in "<<color<<" headquarter"<<std::endl;
				std::cout<<"It has a "<<temp->getWeapon().getType()<<std::endl;
			}
			break;
		case LION:
			if(sp>=lion::preHp){
				sp -= lion::preHp;
				t = new lion(id,sp);
				flag = true;
				warriorNum[LION]++;
				std::cout<<color<<" lion "<<id<<" born with strength "<<lion::preHp<<","<<warriorNum[LION]<<" lion in "<<color<<" headquarter"<<std::endl;
				std::cout<<"It's loyalty is "<<sp<<std::endl;
			}
			break;
		case WOLF:
			if(sp>=wolf::preHp){
				t = new wolf(id);
				sp -= wolf::preHp;
				flag = true;
				warriorNum[WOLF]++;
				std::cout<<color<<" wolf "<<id<<" born with strength "<<wolf::preHp<<","<<warriorNum[WOLF]<<" wolf in "<<color<<" headquarter"<<std::endl;
			}
			break;
		}
		roll++;
		if(flag){
			warriorList.push_back(t);//加入武士列表
			warriorNum[k]++;//该武士数量加1
			return;
		}
	}
	if(time == -1){
		stop = true;
		std::cout << color << " headquarter" << " stops making warriors" << std::endl;
	}
}

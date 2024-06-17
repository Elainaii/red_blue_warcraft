//
// Created by Elaina on 2024/5/16.
//

#include <iomanip>
#include "headquarter.h"
#include "sstream"
headquarter::headquarter(int sp,
	int city,
	int cityNum,
	const std::string& color,
	std::vector<warriorType> produceOrder,
	std::vector<std::vector<warrior*>>& cityList,
	EventControl& eventManager)
	: sp(sp),
	  color(color),
	  produceOrder(produceOrder),
	  roll(0),
	  city(city),
	  cityNum(cityNum),
	  cityList(cityList),
	  eventManager(eventManager) {
	for (int i = 0; i < produceOrder.size(); i++) {
		warriorNum[produceOrder[i]] = 0;
	}
	if (color == "red") {
		colorFlag = 0;
	}
	else {
		colorFlag = 1;
	}
}
void headquarter::produce(int Time) {//你，为什么改了生产规则？？？？！！！！！
	//代码有点烂，但是我懒得改了
	if (isStop) {
		return;
	}
	warriorType k = produceOrder[roll % 5];//获取现在该生产的武士
	warrior* t;
	bool flag = false;//这一轮是否生产成功
	switch (k) {
	case DRAGON:
		if (sp >= dragon::preHp) {
			std::ostringstream oss;//用于存储事件字符串
			sp -= dragon::preHp;//生命元减少
			t = new dragon(id, colorFlag, (double)sp / dragon::preHp, city);//new一个dragon
			cityList[city][colorFlag] = t;//将dragon放入司令部所在城市
			auto temp = dynamic_cast<dragon*>(t);//转换成dragon类型
			flag = true;//生产成功
			warriorNum[DRAGON]++;//dragon数量加1
			//产生事件字符串
			//尼玛为什么不需要输出武器，白写了这下
			oss << color << " dragon " << id << " born"<< std::endl;// with strength " << dragon::preHp << "," << warriorNum[DRAGON]
//				<< " dragon in " << color << " headquarter" << std::endl;
//			oss << "It has a " << temp->getWeapon(0).getType() << " and it's morale is " << std::fixed
//				<< std::setprecision(2) << temp->getMorale() << std::endl;
			Event eve(Time, city, colorFlag, BORN, oss.str());
			//添加事件
			eventManager.addEvent(eve);
		}
		break;
	case NINJA:
		if (sp >= ninja::preHp) {
			std::ostringstream oss;
			t = new ninja(id, colorFlag, city);
			cityList[city][colorFlag] = t;
			auto temp = dynamic_cast<ninja*>(t);
			sp -= ninja::preHp;
			flag = true;
			warriorNum[NINJA]++;
			oss << color << " ninja " << id << " born"<<std::endl;// with strength " << ninja::preHp << "," << warriorNum[NINJA]
//				<< " ninja in " << color << " headquarter" << std::endl;
//			oss << "It has a " << temp->getWeapon(0).getType() << " and a " << temp->getWeapon(1).getType()
//				<< std::endl;
			Event eve(Time, city, colorFlag, BORN, oss.str());
			eventManager.addEvent(eve);
		}
		break;
	case ICEMAN:
		if (sp >= iceman::preHp) {
			std::ostringstream oss;
			t = new iceman(id, colorFlag, city);
			cityList[city][colorFlag] = t;
			auto temp = dynamic_cast<iceman*>(t);
			sp -= iceman::preHp;
			flag = true;
			warriorNum[ICEMAN]++;
			oss << color << " iceman " << id << " born"<<std::endl;// with strength " << iceman::preHp << "," << warriorNum[ICEMAN]
//				<< " iceman in " << color << " headquarter" << std::endl;
//			oss << "It has a " << temp->getWeapon(0).getType() << std::endl;
			Event eve(Time, city, colorFlag, BORN, oss.str());
			eventManager.addEvent(eve);
		}
		break;
	case LION:
		if (sp >= lion::preHp) {
			std::stringstream oss;
			sp -= lion::preHp;
			t = new lion(id, colorFlag, sp, city);
			cityList[city][colorFlag] = t;
			flag = true;
			warriorNum[LION]++;
			oss << color << " lion " << id << " born"<<std::endl;// with strength " << lion::preHp << "," << warriorNum[LION]
//				<< " lion in " << color << " headquarter" << std::endl;
			oss << "Its loyalty is " << sp << std::endl;
			Event eve(Time, city, colorFlag, BORN, oss.str());
			eventManager.addEvent(eve);
		}
		break;
	case WOLF:
		if (sp >= wolf::preHp) {
			std::stringstream oss;
			t = new wolf(id, colorFlag, city);
			cityList[city][colorFlag] = t;
			sp -= wolf::preHp;
			flag = true;
			warriorNum[WOLF]++;
			oss << color << " wolf " << id << " born"<<std::endl;// with strength " << wolf::preHp << "," << warriorNum[WOLF]
//				<< " wolf in " << color << " headquarter" << std::endl;
			Event eve(Time, city, colorFlag, BORN, oss.str());
			eventManager.addEvent(eve);
		}
		break;
	}
	roll++;
	if (flag) {
		warriorList.push_back(t);//加入武士列表
		//warriorNum[k]++;//该武士数量加1
		id++;
		return;
	}
	else{
//		Event eve(Time, city, colorFlag, BORN, color + " headquarter stops making warriors");
//		eventManager.addEvent(eve);
		isStop = true;
		return;
	}

}
void headquarter::reportWeapon(int Time) const {//接收每个武士报告的字符串并打包成事件添加
	for (auto i : warriorList) {
		Event eve(Time, i->getCity(), colorFlag, REPORT, i->reportWeapon());
		eventManager.addEvent(eve);
	}
}
void headquarter::lionRun(int Time) {
	for (int i = 0; i < warriorList.size(); i++) {
		if (warriorList[i]->getType() == LION) {
			auto temp = dynamic_cast<lion*>(warriorList[i]);
			if (temp->getLoyalty() <= 0) {
//				std::cout<<std::setw(3)<<std::setfill('0')<<Time%1000<<":"<<"05 ";
//				std::cout<<color<<" lion "<<warriorList[i]->getId()<<" ran away"<<std::endl;//lion润了
				Event eve(Time,city,colorFlag,RUNAWAY,color + " lion " + std::to_string(warriorList[i]->getId()) + " ran away\n");
				eventManager.addEvent(eve);
				warriorNum[LION]--;
				cityList[warriorList[i]->getCity()][colorFlag] = nullptr;
				warriorList.erase(warriorList.begin() + i);//删掉lion
			}
		}
	}

}
void headquarter::reportSp(int Time) const {
	std::stringstream oss;
	oss << sp << " elements in " << color << " headquarter" << std::endl;
	Event eve(Time, city, colorFlag, ELEMENTS, oss.str());
	eventManager.addEvent(eve);
}
bool headquarter::warriorMove(int Time) {//移动到了敌方司令部返回true
	bool flag = false;
	for (int i = 0; i < warriorList.size(); i++) {//武士序号在前面的肯定走在前面
		if (colorFlag == 0) {//红队向右走
			if (warriorList[i]->getType() == ICEMAN) {//iceman
				auto temp = dynamic_cast<iceman*>(warriorList[i]);
				temp->moveSuffer();
			}
			if (warriorList[i]->getType() == LION) {
				auto temp = dynamic_cast<lion*>(warriorList[i]);
				temp->reduceLoyalty();
			}
			std::stringstream oss;
			cityList[warriorList[i]->getCity() + 1][colorFlag] = warriorList[i];
			cityList[warriorList[i]->getCity()][colorFlag] = nullptr;
			warriorList[i]->changeCity(warriorList[i]->getCity() + 1);
			if (warriorList[i]->getCity() == cityNum - 1) {//到达敌方司令部
				oss.str("");
				oss << "red " << warriorList[i]->getName() << " " << warriorList[i]->getId()
					<< " reached blue headquarter with " << warriorList[i]->getHp() << " elements and force "
					<< warriorList[i]->getAtk() << std::endl;
				Event eve(Time, warriorList[i]->getCity(), colorFlag, REACH, oss.str());
				eventManager.addEvent(eve);
				Event taken(Time, warriorList[i]->getCity(), colorFlag, TAKEN, "blue headquarter was taken\n");
				eventManager.addEvent(taken);
				flag = true;
				continue;
			}
			oss << color << " " << warriorList[i]->getName() << " " << warriorList[i]->getId() << " marched to city "
				<< warriorList[i]->getCity() << " with " << warriorList[i]->getHp() << " elements and force "
				<< warriorList[i]->getAtk() << std::endl;
			Event eve(Time, warriorList[i]->getCity(), colorFlag, MOVE, oss.str());
			eventManager.addEvent(eve);

		}
		else {//两段几乎完全一样的代码
			if (warriorList[i]->getType() == ICEMAN) {//iceman
				auto temp = dynamic_cast<iceman*>(warriorList[i]);
				temp->moveSuffer();
			}
			if (warriorList[i]->getType() == LION) {
				auto temp = dynamic_cast<lion*>(warriorList[i]);
				temp->reduceLoyalty();
			}
			std::stringstream oss;
			cityList[warriorList[i]->getCity() - 1][colorFlag] = warriorList[i];
			cityList[warriorList[i]->getCity()][colorFlag] = nullptr;
			warriorList[i]->changeCity(warriorList[i]->getCity() - 1);
			if (warriorList[i]->getCity() == 0) {//到达敌方司令部
				oss.str("");
				oss << "blue " << warriorList[i]->getName() << " " << warriorList[i]->getId()
					<< " reached red headquarter with " << warriorList[i]->getHp() << " elements and force "
					<< warriorList[i]->getAtk()<< std::endl;
				Event eve(Time, warriorList[i]->getCity(), colorFlag, REACH, oss.str());
				eventManager.addEvent(eve);
				Event taken(Time, warriorList[i]->getCity(), colorFlag, TAKEN, "red headquarter was taken\n");
				eventManager.addEvent(taken);
				flag = true;
				continue;
			}
			oss << color << " " << warriorList[i]->getName() << " " << warriorList[i]->getId() << " marched to city "
				<< warriorList[i]->getCity() << " with " << warriorList[i]->getHp() << " elements and force "
				<< warriorList[i]->getAtk() << std::endl;
			Event eve(Time, warriorList[i]->getCity(), colorFlag, MOVE, oss.str());
			eventManager.addEvent(eve);

		}
	}
	return flag;
}
void headquarter::warriorDie(warrior* w) {
	warriorNum[w->getType()]--;
	warriorList.erase(std::find(warriorList.begin(), warriorList.end(), w));
	cityList[w->getCity()][colorFlag] = nullptr;
}
void headquarter::wolfRob(int Time) {
	for (int i = 1; i < cityNum; i++) {
		if (cityList[i][0] && cityList[i][1]) {//这个城市有两个武士
			if (cityList[i][0]->getType() == cityList[i][1]->getType()) {
				continue;
			}
			else if (cityList[i][0]->getType() == WOLF) {
				auto temp = dynamic_cast<wolf*>(cityList[i][0]);
				auto temp2 = cityList[i][1];
				std::string str;
				if (!(str = temp->rob(*temp2)).empty()) {
					std::ostringstream oss;
					oss << "red wolf " << cityList[i][0]->getId() << " took " << str << " from blue "
						<< cityList[i][1]->getName() << " " << cityList[i][1]->getId() << " in city " << i << std::endl;
					Event eve(Time, i, 0, STEAL, oss.str());
					eventManager.addEvent(eve);
				}
			}
			else if (cityList[i][1]->getType() == WOLF) {
				auto temp = dynamic_cast<wolf*>(cityList[i][1]);
				std::string str;
				if (!(str = temp->rob(*cityList[i][0])).empty()) {
					std::ostringstream oss;
					oss << "blue wolf " << cityList[i][1]->getId() << " took " << str << " from red "
						<< cityList[i][0]->getName() << " " << cityList[i][0]->getId() << " in city " << i << std::endl;
					Event eve(Time, i, 1, STEAL, oss.str());
					eventManager.addEvent(eve);
				}
			}
		}
	}

}
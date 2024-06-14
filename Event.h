//
// Created by Elaina on 2024/6/9.
//

#ifndef WARCRAFT__EVENT_H_
#define WARCRAFT__EVENT_H_
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
//事件类型，用于排序
enum eventType{BORN=1,RUNAWAY,MOVE,STEAL,TTK,YELL,REACH,TAKEN,ELEMENTS,REPORT};
//由事件类型值可以确定时间及输出顺序
//分钟 事件
//00 born
//05 runaway
//10 move reach taken
//35 steal
//40 ttk yell
//50 elements
//55 report
class Event{
 private:
 public:
	int Hours;
	bool Color;//0代表红队,1代表蓝队
 	bool isOutputted = false;
	int City;
	eventType Type;
	std::string event;
	Event(int hour,int city,bool color,eventType type,std::string event): Hours(hour),City(city), Color(color), Type(type), event(event){}
};

class EventControl{//现在我改变了想法，事件不再直接输出，而是放到这里等结束后一起输出
 private:
	int cityNum;
	int timeLimit;
	int timeLinitHour;
	int timeLimitMinute;
	//第一层小时，第二层是分钟，第三层是每个城市,第四层是事件列表
	std::vector<std::vector<std::vector<std::vector<Event>>>> eventList;//每个城市的事件列表
//	std::vector<std::vector<Event>> eventList;//每个城市的事件列表
	void outputTime(int Hour,eventType type);
 public:
	EventControl(int cityNum,int timeLimit);
	//TODO:差不多写完了，但是现在要设置一个时间限制，写完时间限制就可以快乐的debug了
	void addEvent(Event event);
	void outputEvent(int Time);
	void clearEvent();
};
EventControl::EventControl(int cityNum,int timeLimit):cityNum(cityNum),timeLimit(timeLimit){
	timeLinitHour = timeLimit/60;
	timeLimitMinute = timeLimit%60;
}
void EventControl::addEvent(Event event) {//根据事件类型添加事件
	if(eventList.size()<event.Hours+1){
		eventList.resize(event.Hours+1);
		eventList[event.Hours].resize(7);
		for(int i =0;i<7;i++){
			eventList[event.Hours][i].resize(cityNum+2);
		}
	}
	eventList[event.Hours][event.Type][event.City].push_back(event);
}
void EventControl::outputEvent(int Time) {
	//对所有事件进行输出
	for(int hour =0;hour<eventList.size();hour++){//这一层是每个小时
		for(int minute =0;minute<eventList[hour].size();minute++){//各分钟
			for(int city =0;city<eventList[hour][minute].size();city++){//同一时间的事件，按城市输出
				if(eventList[hour][minute][city].empty())
					continue;
				else if(eventList[hour][minute][city].size()==1){
					outputTime(hour,eventList[hour][minute][city][0].Type);
					std::cout<<eventList[hour][minute][city][0].event<<std::endl;//只有一个直接输出
				}
				else{
					//对事件排序
					std::sort(eventList[hour][minute][city].begin(),eventList[hour][minute][city].end(),[](Event a,Event b){
					  return a.Type<b.Type;
					});
					//输出红队
					for(int j =0;j<eventList[hour][minute][city].size();j++){
						if(eventList[hour][minute][city][j].Color==0){
							outputTime(hour,eventList[hour][minute][city][j].Type);
							std::cout<<eventList[hour][minute][city][j].event<<std::endl;
						}
					}
					//输出蓝队
					for(int j =0;j<eventList[hour][minute][city].size();j++){
						if(eventList[hour][minute][city][j].Color==1){
							outputTime(hour,eventList[hour][minute][city][j].Type);
							std::cout<<eventList[hour][minute][city][j].event<<std::endl;
						}
					}
				}
			}
		}
	}

	//TODO:现在你写完了事件输出到管理，接下来重构一下之前的输出，把输出的事件都放到这里来
}
void EventControl::outputTime(int Hour, eventType type) {
	std::cout<<std::setw(3)<<std::setfill('0')<<Hour%1000<<":";
	switch (type) {
	case BORN:
		std::cout<<"00 ";
		break;
	case RUNAWAY:
		std::cout<<"05 ";
		break;
	case MOVE:
		std::cout<<"10 ";
		break;
	case STEAL:
		std::cout<<"35 ";
		break;
	case TTK:
		std::cout<<"40 ";
		break;
	case YELL:
		std::cout<<"40 ";
		break;
	case REACH:
		std::cout<<"10 ";
		break;
	case TAKEN:
		std::cout<<"10 ";
		break;
	case ELEMENTS:
		std::cout<<"50 ";
		break;
	case REPORT:
		std::cout<<"55 ";
		break;
	}

}
#endif //WARCRAFT__EVENT_H_

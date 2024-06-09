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
enum eventType{BORN=0,RUNAWAY,MOVE,STEAL,TTK,YELL,REACH,TAKEN,ELEMENTS,REPORT};
class Event{
 private:
 public:
	bool Color;//0代表红队,1代表蓝队
 	bool isOutputted = false;
	int City;
	eventType Type;
	std::string event;
	Event(int city,bool color,eventType type,std::string event): City(city), Color(color), Type(type), event(event){}
};

class EventControl{
 private:
	std::vector<std::vector<Event>> eventList;//每个城市的事件列表
 public:
	EventControl(int cityNum);
	void addEvent(int city,bool color,eventType type,Event event);
	void outputEvent(int Time);
	void clearEvent();
};

EventControl::EventControl(int cityNum) {
	eventList.resize(cityNum+2);
}
void EventControl::addEvent(int city, bool color, eventType type, Event event) {
	eventList[city].push_back(event);
}
void EventControl::outputEvent(int Time) {
	//对每个城市的事件进行输出
	for(int i =0;i<eventList.size();i++){
		if(eventList[i].empty())
			continue;
		else if(eventList[i].size()==1){
			std::cout<<eventList[i][0].event<<std::endl;//只有一个直接输出
		}
		else{
			//对事件排序
			std::sort(eventList[i].begin(),eventList[i].end(),[](Event a,Event b){
				return a.Type<b.Type;
			});
			//输出红队
			for(int j =0;j<eventList[i].size();j++){
				if(eventList[i][j].Color==0){
					std::cout<<eventList[i][j].event<<std::endl;
				}
			}
			//输出蓝队
			for(int j =0;j<eventList[i].size();j++){
				if(eventList[i][j].Color==1){
					std::cout<<eventList[i][j].event<<std::endl;
				}
			}
		}
	}
	//TODO:现在你写完了事件输出到管理，接下来重构一下之前的输出，把输出的事件都放到这里来
}
#endif //WARCRAFT__EVENT_H_

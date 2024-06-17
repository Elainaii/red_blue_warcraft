//
// Created by Elaina on 2024/6/9.
//

#ifndef WARCRAFT__EVENT_H_
#define WARCRAFT__EVENT_H_
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <iomanip>
//事件类型，用于排序
enum eventType{BORN=1,RUNAWAY,MOVE,STEAL,TTK,YELL,REACH,TAKEN,ELEMENTS,REPORT};
const int minuteDex[] = {0,5,10,35,40,50,55,60};
const int minuteTypeDex[] ={0,1,2,3,4,4,2,2,5,6};
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

	void addEvent(Event event);
	void outputEvent();
	void outputEvent(int hour);
	void clearEvent();
};
#endif //WARCRAFT__EVENT_H_

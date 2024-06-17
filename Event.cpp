//
// Created by Elaina on 2024/6/15.
//
#include "Event.h"
EventControl::EventControl(int cityNum, int timeLimit) : cityNum(cityNum), timeLimit(timeLimit) {
	timeLinitHour = timeLimit / 60;
	timeLimitMinute = timeLimit % 60;
}
void EventControl::addEvent(Event event) {//根据事件类型添加事件
	if (eventList.size() < event.Hours + 1) {
		eventList.resize(event.Hours + 1);
		eventList[event.Hours].resize(7);
		for (int i = 0; i < 7; i++) {
			eventList[event.Hours][i].resize(cityNum + 2);
		}
	}
	eventList[event.Hours][minuteTypeDex[event.Type - 1]][event.City].push_back(event);
//	调试用
//	outputTime(event.Hours, event.Type);
//	std::cout << event.event;
}
void EventControl::outputEvent() {
	//对所有事件进行输出
	for (int hour = 0; hour < eventList.size(); hour++) {//这一层是每个小时
		for (int minute = 0; minute < 7; minute++) {//各分钟
			if (hour == eventList.size() - 1 && timeLimitMinute < minuteDex[minute]) {//时间到了
				break;
			}
			for (int city = 0; city < eventList[hour][minute].size(); city++) {//同一时间的事件，按城市输出
				if (eventList[hour][minute][city].empty())
					continue;
				else if (eventList[hour][minute][city].size() == 1) {
					outputTime(hour, eventList[hour][minute][city][0].Type);
					std::cout << eventList[hour][minute][city][0].event;//只有一个直接输出
				}
				else {
					//对事件排序
					std::sort(eventList[hour][minute][city].begin(),
						eventList[hour][minute][city].end(),
						[](Event a, Event b) {
						  return a.Type < b.Type;
						});
					//输出红队
					for (int j = 0; j < eventList[hour][minute][city].size(); j++) {
						if (eventList[hour][minute][city][j].Color == 0) {
							outputTime(hour, eventList[hour][minute][city][j].Type);
							std::cout << eventList[hour][minute][city][j].event;
						}
					}
					//输出蓝队
					for (int j = 0; j < eventList[hour][minute][city].size(); j++) {
						if (eventList[hour][minute][city][j].Color == 1) {
							outputTime(hour, eventList[hour][minute][city][j].Type);
							std::cout << eventList[hour][minute][city][j].event;
						}
					}
				}
			}
		}
	}


}
void EventControl::outputEvent(int hour) {
	//对所有事件进行输出

	for (int minute = 0; minute < 7; minute++) {//各分钟
		for (int city = 0; city < eventList[hour][minute].size(); city++) {//同一时间的事件，按城市输出
			if (eventList[hour][minute][city].empty())
				continue;
			else if (eventList[hour][minute][city].size() == 1) {
				outputTime(hour, eventList[hour][minute][city][0].Type);
				std::cout << eventList[hour][minute][city][0].event;//只有一个直接输出
			}
			else {
				//对事件排序
				std::sort(eventList[hour][minute][city].begin(),
					eventList[hour][minute][city].end(),
					[](Event a, Event b) {
					  return a.Type < b.Type;
					});
				//输出红队
				for (int j = 0; j < eventList[hour][minute][city].size(); j++) {
					if (eventList[hour][minute][city][j].Color == 0) {
						outputTime(hour, eventList[hour][minute][city][j].Type);
						std::cout << eventList[hour][minute][city][j].event;
					}
				}
				//输出蓝队
				for (int j = 0; j < eventList[hour][minute][city].size(); j++) {
					if (eventList[hour][minute][city][j].Color == 1) {
						outputTime(hour, eventList[hour][minute][city][j].Type);
						std::cout << eventList[hour][minute][city][j].event;
					}
				}
			}
		}
	}


}
void EventControl::outputTime(int Hour, eventType type) {
	std::cout << std::setw(3) << std::setfill('0') << Hour % 1000 << ":";
	switch (type) {
	case BORN:
		std::cout << "00 ";
		break;
	case RUNAWAY:
		std::cout << "05 ";
		break;
	case MOVE:
		std::cout << "10 ";
		break;
	case STEAL:
		std::cout << "35 ";
		break;
	case TTK:
		std::cout << "40 ";
		break;
	case YELL:
		std::cout << "40 ";
		break;
	case REACH:
		std::cout << "10 ";
		break;
	case TAKEN:
		std::cout << "10 ";
		break;
	case ELEMENTS:
		std::cout << "50 ";
		break;
	case REPORT:
		std::cout << "55 ";
		break;
	}

}


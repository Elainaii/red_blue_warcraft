//
// Created by Elaina on 2024/5/16.
//

#include <iomanip>
#include "warrior.h"
#include "iostream"
int dragon::preHp = 0;
int ninja::preHp = 0;
int iceman::preHp = 0;
int lion::preHp = 0;
int wolf::preHp = 0;
warrior::warrior(int id, int atk, int hp):id(id), atk(atk), hp(hp) {

}
warrior::~warrior() {

}
int warrior::getId() const {
	return id;
}
int warrior::getAtk() const {
	return atk;
}
int warrior::getHp() const {
	return hp;
}
bool warrior::suffer(int damage) {
	hp -= damage;
	if(hp<=0)
		return true;
	return false;
}
void warrior::reportWeapon(int Time,std::string color) const {
	int sword = 0,bomb = 0,arrow = 0;
	for(auto i:weaponList){
		if(i.getWeaponType()==SWORD)
			sword++;
		else if(i.getWeaponType()==BOMB)
			bomb++;
		else if(i.getWeaponType()==ARROW)
			arrow++;
	}
	std::cout<<std::setw(3)<<std::setfill('0')<<Time%1000<<":"<<"55 "<<color<<" "<<getName()<<" "<<id<<" has ";
	std::cout<<sword<<" sword "<<bomb<<" bomb "<<arrow<<" arrow and "<<hp<<" elements\n";
}

dragon::dragon(int id,double morale) : warrior(id,DRAGON_ATK,dragon::preHp), morale(morale){
	weaponList.push_back(weapon(DRAGON_ATK,weaponType(id%3)));

}
ninja::ninja(int id) : warrior(id,NINJA_ATK,ninja::preHp){
	weaponList.push_back(weapon(NINJA_ATK,weaponType(id%3)));
	weaponList.push_back(weapon(NINJA_ATK,weaponType((id+1)%3)));
}
iceman::iceman(int id) : warrior(id,ICEMAN_ATK,iceman::preHp){
	weaponList.push_back(weapon(ICEMAN_ATK,weaponType(id%3)));
}
lion::lion(int id,int loyalty) : warrior(id,LION_ATK,lion::preHp) , loyalty(loyalty){

}
wolf::wolf(int id) : warrior(id,WOLF_ATK,wolf::preHp) {

}

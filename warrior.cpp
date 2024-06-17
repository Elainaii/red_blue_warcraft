//
// Created by Elaina on 2024/5/16.
//

#include <iomanip>
#include "warrior.h"
#include "iostream"
#include "sstream"
#include "Event.h"
int dragon::preHp = 0;
int ninja::preHp = 0;
int iceman::preHp = 0;
int lion::preHp = 0;
int wolf::preHp = 0;
int lion::loyaltyDecrease = 0;
int warrior::DRAGON_ATK = 0;
int warrior::NINJA_ATK = 0;
int warrior::ICEMAN_ATK = 0;
int warrior::LION_ATK = 0;
int warrior::WOLF_ATK = 0;
warrior::warrior(int id,bool color ,int atk, int hp,int city):id(id), atk(atk), hp(hp), city(city),color(color){

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


std::string warrior::reportWeapon() const {//武士只要返回字符串就行了，而headquarter要考虑的就多了
	int sword = 0,bomb = 0,arrow = 0;
	std::stringstream oss;
	for(auto i:weaponList){
		if(i.getWeaponType()==SWORD)
			sword++;
		else if(i.getWeaponType()==BOMB)
			bomb++;
		else if(i.getWeaponType()==ARROW)
			arrow++;
	}
//	ans += color+" "+getName()+" "+std::to_string(id)+" has "+std::to_string(sword)
//		+" sword "+std::to_string(bomb)+" bomb "+std::to_string(arrow)+" arrow and "
//		+std::to_string(hp)+" elements\n";
	oss<<(color==0?"red":"blue")<<" "<<getName()<<" "<<id<<" has "<<sword<<" sword "<<bomb<<" bomb "<<arrow<<" arrow and "<<hp<<" elements\n";
	return oss.str();

}
void warrior::sortWeapon() {
	std::sort(weaponList.begin(),weaponList.end(),[](const weapon &a,const weapon &b){
		if(a.getWeaponType()==b.getWeaponType()&&a.getWeaponType()==ARROW)
			return a.getDurability()<b.getDurability();//用过的排在前面
		return a.getWeaponType()<b.getWeaponType();
	});
}

void warrior::sortWeapon2() {
	std::sort(weaponList.begin(),weaponList.end(),[](const weapon &a,const weapon &b){
	  if(a.getWeaponType()==b.getWeaponType()&&a.getWeaponType()==ARROW)
		  return a.getDurability()>b.getDurability();//没用过的排在前面
	  return a.getWeaponType()<b.getWeaponType();
	});
}
void warrior::ttk(warrior& enemy) {
	if(weaponList.empty()){
		return;
	}
	weaponList[ttkRound % weaponList.size()].reset(atk);
	if(weaponList[ttkRound % weaponList.size()].use(enemy,*this)){//判断是否用坏
		removeWeapon(ttkRound % weaponList.size());
	}
	ttkRound++;
}

void warrior::win(warrior& enemy) {//胜利后的操作
	enemy.sortWeapon2();
	while(weaponList.size()<10&&!enemy.weaponList.empty()){
		weaponList.push_back(enemy.getWeapon(0));
		enemy.removeWeapon(0);
	}

}

void warrior::backup() {
	prehp = hp;
	preWeaponList = weaponList;
}

bool warrior::isInfluenced() {
	if(prehp!=hp)
		return true;
	if(preWeaponList.size()!=weaponList.size())
		return true;
	for(int i =0;i<preWeaponList.size();i++){
		if(preWeaponList[i].getWeaponType()!=weaponList[i].getWeaponType()||preWeaponList[i].getDurability()!=weaponList[i].getDurability())
			return true;
	}
	return false;
}

dragon::dragon(int id,int color,double morale,int city) : warrior(id,color,DRAGON_ATK,dragon::preHp,city), morale(morale){
	weaponList.push_back(weapon(DRAGON_ATK,weaponType(id%3)));

}
ninja::ninja(int id,int color,int city) : warrior(id,color,NINJA_ATK,ninja::preHp,city){
	weaponList.push_back(weapon(NINJA_ATK,weaponType(id%3)));
	weaponList.push_back(weapon(NINJA_ATK,weaponType((id+1)%3)));
}
iceman::iceman(int id,int color,int city) : warrior(id,color,ICEMAN_ATK,iceman::preHp,city){
	weaponList.push_back(weapon(ICEMAN_ATK,weaponType(id%3)));
}
lion::lion(int id,int color,int loyalty,int city) : warrior(id,color,LION_ATK,lion::preHp,city) , loyalty(loyalty){
	weaponList.push_back(weapon(LION_ATK,weaponType(id%3)));
}
wolf::wolf(int id,int color,int city) : warrior(id,color,WOLF_ATK,wolf::preHp,city) {

}
std::string wolf::rob(warrior& enemy) {
	if(weaponList.size()>=10||enemy.weaponList.empty())
		return "";
	enemy.sortWeapon2();
	int num = 1;
	int max = 10 - weaponList.size();
	std::string ansstr;
	int i = 0;
	while(enemy.weaponList.size()>=i+2&&enemy.getWeapon(i).getWeaponType()==enemy.getWeapon(i+1).getWeaponType()){
		num++;
		i++;
	}
	num = std::min(num,max);
	ansstr.push_back(num+'0');
	ansstr.push_back(' ');
	ansstr += enemy.getWeapon(0).getType();
	while(num--){
		weaponList.push_back(enemy.getWeapon(0));
		enemy.removeWeapon(0);
	}
	return ansstr;
}

void warrior::removeWeapon(int i) {

	weaponList.erase(weaponList.begin()+i);
}
weapon& warrior::getWeapon(int i) {
	if(i>weaponList.size()-1)
		throw std::out_of_range("out of range");
	return weaponList[i];
}

//
// Created by Elaina on 2024/5/23.
//

#ifndef WARCRAFT__WEAPON_H_
#define WARCRAFT__WEAPON_H_
#include "string"
#include "warrior.h"
enum weaponType{SWORD=0, BOMB, ARROW};//武器编号类型
class weapon {
 private:
	int atk;
	int durability;
	weaponType type;
 public:
	weapon(int atk, weaponType type);
	int getAtk() const{return atk;}
	bool use(warrior &enemy,warrior& self);//武器用坏了返回true
	int getDurability() const{return durability;}
	bool reduceDurability();//减少耐久，如果耐久为0返回true
	std::string getType() const;
	weaponType getWeaponType() const{return type;}
};

#endif //WARCRAFT__WEAPON_H_

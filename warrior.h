//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__warrior_H_
#define WARCRAFT__warrior_H_

#define DRAGON_ATK 20
#define NINJA_ATK 30
#define ICEMAN_ATK 35
#define LION_ATK 40
#define WOLF_ATK 50

#include "string"
#include "iostream"
#include "weapon.h"
enum warriorType{DRAGON, NINJA, ICEMAN, LION, WOLF};

class warrior {//各种武士的基类
 private:
	int id;//编号
	int atk;//攻击力
	int hp;//生命值
	warriorType type;
 protected:
 public://该类武士初始生命值,应该在gameManager初始化
	warrior(int id,int atk,int hp);
	virtual ~warrior();
	int getId() const;
	int getAtk() const;
	int getHp() const;
	virtual warriorType getType() const = 0;
	virtual std::string getName() const = 0;
};
class dragon : public warrior {
 private:
	double morale;
	weapon weapon1;
 public:
	dragon(int id,double morale);
	~dragon(){}
	weapon getWeapon() const{return weapon1;}
	double getMorale() const{return morale;}
	static int preHp;
	std::string getName() const override{return "dragon";}
	warriorType getType() const override{return DRAGON;}
};
class ninja : public warrior {
 private:
	weapon weapon1;
	weapon weapon2;
 public:
	ninja(int id);
	~ninja(){}
	static int preHp;
	weapon getWeapon() const{return weapon1;}
	weapon getWeapon2() const{return weapon2;}
	std::string getName() const override{return "ninja";}
	warriorType getType() const override{return NINJA;}
};
class iceman : public warrior {
 private:
	weapon weapon1;
 public:
	iceman(int id);
	~iceman(){}
	static int preHp;
	weapon getWeapon() const{return weapon1;}
	std::string getName() const override{return "iceman";}
	warriorType getType() const override{return ICEMAN;}
};
class lion : public warrior {
 private:
	int loyalty;
 public:
	lion(int id,int loyalty);
	~lion(){}
	static int preHp;
	int getLoyalty() const{return loyalty;}
	std::string getName() const override{return "lion";}
	warriorType getType() const override{return LION;}
};
class wolf : public warrior {
 public:
	wolf(int id);
	~wolf(){}
	static int preHp;
	std::string getName() const override{return "wolf";}
	warriorType getType() const override{return WOLF;}
};

#endif //WARCRAFT__warrior_H_

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
#include "vector"
enum warriorType{DRAGON, NINJA, ICEMAN, LION, WOLF};

class warrior {//各种武士的基类
 private:
	int id;//编号
	int atk;//攻击力
	int city;//所在城市
	bool color;//0代表红方,1代表蓝方
	int ttkRound = 0;//武器使用顺序下标
	warriorType type;
 protected:
	std::vector<weapon> preWeaponList;//上一次的武器列表
	int hp;
	int prehp;
	std::vector<weapon> weaponList;
 public://该类武士初始生命值,应该在gameManager初始化
	warrior(int id,bool color,int atk,int hp,int city);
	virtual ~warrior();
	int getId() const;
	int getAtk() const;
	int getHp() const;
	int getCity() const{return city;}
	bool getColor() const{return color;}
	void changeCity(int City){this->city = City;}
	weapon& getWeapon(int i) {return weaponList[i];}
	void removeWeapon(int i) {weaponList.erase(weaponList.begin()+i);}
	void sortWeapon();//排序武器，按编号排序
	void sortWeapon2();//缴获时的排序
	void ttk(warrior& enemy);//武士打架
	void backup();//复制武器列表和hp到pre中
	bool isInfluenced();//检查是否有变化
	bool checkInfluence();//检查是否有变化
	void win(warrior& enemy);//胜利
	bool suffer(int damage);
	bool isDead() const{return hp<=0;}
	void die();
	std::string reportWeapon() const;
	virtual warriorType getType() const = 0;
	virtual std::string getName() const = 0;
//武器列表
//生命值

};
class dragon : public warrior {
 private:
	double morale;
 public:
	dragon(int id,int color,double morale,int city);
	~dragon(){}
	double getMorale() const{return morale;}
	static int preHp;
	std::string getName() const override{return "dragon";}
	warriorType getType() const override{return DRAGON;}
};
class ninja : public warrior {
 private:
 public:
	ninja(int id,int color,int city);
	~ninja(){}
	static int preHp;
	std::string getName() const override{return "ninja";}
	warriorType getType() const override{return NINJA;}
};
class iceman : public warrior {
 private:
 public:
	iceman(int id,int color,int city);
 	void moveSuffer(){hp-=hp/10;}
	~iceman(){}
	static int preHp;
	std::string getName() const override{return "iceman";}
	warriorType getType() const override{return ICEMAN;}
};
class lion : public warrior {
 private:
	int loyalty;
	static int loyaltyDecrease;
 public:
	lion(int id,int color,int loyalty,int city);
	~lion(){}
	static int preHp;
	int getLoyalty() const{return loyalty;}
	static void setLoyaltyDecrease(int decrease){loyaltyDecrease = decrease;}
	void reduceLoyalty(){loyalty-=loyaltyDecrease;}
	std::string getName() const override{return "lion";}
	warriorType getType() const override{return LION;}
};
class wolf : public warrior {
 public:
	wolf(int id,int color,int city);
	~wolf(){}
	static int preHp;
	std::string rob(warrior& enemy);
	std::string getName() const override{return "wolf";}
	warriorType getType() const override{return WOLF;}
};

#endif //WARCRAFT__warrior_H_

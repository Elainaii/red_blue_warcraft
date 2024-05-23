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
 public:
	dragon(int id);
	~dragon(){}
	static int preHp;
	std::string getName() const override{return "dragon";}
	warriorType getType() const override{return DRAGON;}
};
class ninja : public warrior {
 public:
	ninja(int id);
	~ninja(){}
	static int preHp;
	std::string getName() const override{return "ninja";}
	warriorType getType() const override{return NINJA;}
};
class iceman : public warrior {
 public:
	iceman(int id);
	~iceman(){}
	static int preHp;
	std::string getName() const override{return "iceman";}
	warriorType getType() const override{return ICEMAN;}
};
class lion : public warrior {
 private:
 public:
	lion(int id);
	~lion(){}
	static int preHp;
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

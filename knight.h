//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__KNIGHT_H_
#define WARCRAFT__KNIGHT_H_

#define DRAGON_ATK 20
#define NINJA_ATK 30
#define ICEMAN_ATK 35
#define LION_ATK 40
#define WOLF_ATK 50

#include "string"
#include "iostream"
enum knightType{DRAGON, NINJA, ICEMAN, LION, WOLF};
class knight {//各种武士的基类
 private:
	int id;//编号
	int atk;//攻击力
	int hp;//生命值
	knightType type;
 protected:
 public://该类武士初始生命值,应该在gameManager初始化
	knight(int id,int atk,int hp);
	virtual ~knight();
	int getId() const;
	int getAtk() const;
	int getHp() const;
	virtual knightType getType() const = 0;
	virtual std::string getName() const = 0;
};
class dragon : public knight {
 private:
 public:
	dragon(int id);
	~dragon(){}
	static int preHp;
	std::string getName() const override{return "dragon";}
	knightType getType() const override{return DRAGON;}
};
class ninja : public knight {
 public:
	ninja(int id);
	~ninja(){}
	static int preHp;
	std::string getName() const override{return "ninja";}
	knightType getType() const override{return NINJA;}
};
class iceman : public knight {
 public:
	iceman(int id);
	~iceman(){}
	static int preHp;
	std::string getName() const override{return "iceman";}
	knightType getType() const override{return ICEMAN;}
};
class lion : public knight {
 private:
 public:
	lion(int id);
	~lion(){}
	static int preHp;
	std::string getName() const override{return "lion";}
	knightType getType() const override{return LION;}
};
class wolf : public knight {
 public:
	wolf(int id);
	~wolf(){}
	static int preHp;
	std::string getName() const override{return "wolf";}
	knightType getType() const override{return WOLF;}
};

#endif //WARCRAFT__KNIGHT_H_

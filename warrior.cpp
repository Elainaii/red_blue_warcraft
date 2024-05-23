//
// Created by Elaina on 2024/5/16.
//

#include "warrior.h"

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
dragon::dragon(int id) : warrior(id,DRAGON_ATK,dragon::preHp) {

}
ninja::ninja(int id) : warrior(id,NINJA_ATK,ninja::preHp) {

}
iceman::iceman(int id) : warrior(id,ICEMAN_ATK,iceman::preHp) {

}
lion::lion(int id) : warrior(id,LION_ATK,lion::preHp) {

}
wolf::wolf(int id) : warrior(id,WOLF_ATK,wolf::preHp) {

}

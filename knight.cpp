//
// Created by Elaina on 2024/5/16.
//

#include "knight.h"

int dragon::preHp = 0;
int ninja::preHp = 0;
int iceman::preHp = 0;
int lion::preHp = 0;
int wolf::preHp = 0;
knight::knight(int id, int atk, int hp):id(id), atk(atk), hp(hp) {

}
knight::~knight() {

}
int knight::getId() const {
	return id;
}
int knight::getAtk() const {
	return atk;
}
int knight::getHp() const {
	return hp;
}
dragon::dragon(int id) : knight(id,DRAGON_ATK,dragon::preHp) {

}
ninja::ninja(int id) : knight(id,NINJA_ATK,ninja::preHp) {

}
iceman::iceman(int id) : knight(id,ICEMAN_ATK,iceman::preHp) {

}
lion::lion(int id) : knight(id,LION_ATK,lion::preHp) {

}
wolf::wolf(int id) : knight(id,WOLF_ATK,wolf::preHp) {

}

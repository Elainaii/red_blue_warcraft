//
// Created by Elaina on 2024/5/16.
//

#ifndef WARCRAFT__GAMEMANAGER_H_
#define WARCRAFT__GAMEMANAGER_H_
#include "iostream"
#include "knight.h"
#include "headquarter.h"
class warCraft {
 private:
	int event = 1;
	const std::vector<knightType> redOrder = {ICEMAN, LION, WOLF, NINJA, DRAGON};
	const std::vector<knightType> blueOrder = {LION, DRAGON, NINJA, ICEMAN, WOLF};
	headquarter red;
	headquarter blue;
 public:
	warCraft(int sp);
	void hpSet(int dragon, int ninja, int iceman, int lion, int wolf);
	void gameStart();
};

#endif //WARCRAFT__GAMEMANAGER_H_

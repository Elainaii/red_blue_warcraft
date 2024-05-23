//
// Created by Elaina on 2024/5/23.
//

#include "weapon.h"
weapon::weapon(int atk, weaponType type) {
	this->atk = atk;
	this->type = type;

}
std::string weapon::getType() const {
	switch (type) {
		case SWORD:
			return "sword";
		case BOMB:
			return "bomb";
		case ARROW:
			return "arrow";
	}
	return "";
}

//
// Created by Elaina on 2024/5/23.
//

#include "weapon.h"
weapon::weapon(int atk, weaponType type) {
	if(type==SWORD){
		this->atk = atk*2/10;
		durability = INT_MAX;
	}
	else if(type==BOMB){
		this->atk = atk*4/10;
		durability = 1;
	}
	else if(type==ARROW){
		this->atk = atk*3/10;
		durability = 2;
	}
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
bool weapon::reduceDurability() {
	durability--;
	return durability==0;
}
bool weapon::use(warrior& enemy, warrior& self) {
	if(type==SWORD){
		enemy.suffer(atk);
		return false;
	}
	else if(type==BOMB){
		enemy.suffer(atk);
		if(self.getType()!=NINJA)
			self.suffer(atk*5/10);
		reduceDurability();
		return true;
	}
	else if(type==ARROW){
		enemy.suffer(atk);
		return reduceDurability();
	}
}
void weapon::reset(int atk) {
	if(type==SWORD){
		this->atk = atk*2/10;
	}
	else if(type==BOMB){
		this->atk = atk*4/10;
	}
	else if(type==ARROW){
		this->atk = atk*3/10;
	}
}


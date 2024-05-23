//
// Created by Elaina on 2024/5/23.
//

#ifndef WARCRAFT__WEAPON_H_
#define WARCRAFT__WEAPON_H_
#include "string"
enum weaponType{SWORD=0, BOMB, ARROW};
class weapon {
 private:
	int atk;
	weaponType type;
 public:
	weapon(int atk, weaponType type);
	std::string getType() const;
};

#endif //WARCRAFT__WEAPON_H_

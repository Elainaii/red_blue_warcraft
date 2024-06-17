#include <iostream>
#include "gameManager.h"

void run(int c){
	int m,n,k,t;
	std::cin>>m>>n>>k>>t;
	warCraft game(m,n,k,t);
	int dragonHp, ninjaHp, icemanHp, lionHp, wolfHp;
	int dragonAtk, ninjaAtk, icemanAtk, lionAtk, wolfAtk;
	std::cin>>dragonHp>>ninjaHp>>icemanHp>>lionHp>>wolfHp;
	std::cin>>dragonAtk>>ninjaAtk>>icemanAtk>>lionAtk>>wolfAtk;
	getchar();
	std::cout<<"Case "<<c+1<<":"<<std::endl;
	game.hpSet(dragonHp, ninjaHp, icemanHp, lionHp, wolfHp);
	game.atkSet(dragonAtk, ninjaAtk, icemanAtk, lionAtk, wolfAtk);
	game.eventControl();
	game.outputEvent();
}

int main() {
	setbuf(stdout,NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++){
		run(i);
	}
	return 0;
}

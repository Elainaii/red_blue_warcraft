#include <iostream>
#include "gameManager.h"

void run(int c){
	int m,n,k,t;

	warCraft game(sp);
	int dragon, ninja, iceman, lion, wolf;
	std::cin>>dragon>>ninja>>iceman>>lion>>wolf;
	std::cout<<"Case:"<<c+1<<std::endl;
	game.hpSet(dragon, ninja, iceman, lion, wolf);
	game.gameStart();
}

int main() {
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++){
		run(i);
	}
	return 0;
}

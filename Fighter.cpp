#include "Fighter.h"


void Fighter :: take_dmg(Fighter& enemy) {
	HP -= enemy.getDMG();
	if (HP < 0)
		HP = 0;
}

 void Fighter :: deal_dmg(Fighter &enemy) { 
	enemy.take_dmg(*this);
}


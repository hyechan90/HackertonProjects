#include "pokemon.h"

void squirtle(mob* p1) {
	strcpy(p1->name, "部何扁");
	strcpy(p1->skillName, "部府 如甸扁");
	p1->hp = 100;
	p1->mp = 150;
	p1->basicDmg = 10;
	p1->skillDmg = 20;
	p1->mpCost = 30;
}
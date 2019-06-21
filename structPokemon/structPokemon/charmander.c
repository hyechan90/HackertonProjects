#include "pokemon.h"

void charmander(mob* p1)
{
	strcpy(p1->name, "파이리");
	strcpy(p1->skillName, "할퀴기");
	p1->hp = 80;
	p1->mp = 100;
	p1->basicDmg = 20;
	p1->skillDmg = 25;
	p1->mpCost = 35;
}
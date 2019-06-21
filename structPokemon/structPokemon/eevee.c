#include "pokemon.h"

void eevee(mob* p2)
{
	strcpy(p2->name, "이브이");
	strcpy(p2->skillName, "모래뿌리기");
	p2->hp = 100;
	p2->mp = 100;
	p2->basicDmg = 15;
	p2->skillDmg = 25;
	p2->mpCost = 30;
}
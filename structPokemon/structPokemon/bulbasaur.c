#include "pokemon.h"

void bulbasaur(mob* p1)
{
	strcpy(p1->name, "ÀÌ»óÇØ¾¾");
	strcpy(p1->skillName, "¸öÅë ¹ÚÄ¡±â");
	p1->hp = 150;
	p1->mp = 100;
	p1->basicDmg = 7;
	p1->skillDmg = 15;
	p1->mpCost = 25;
}
#include "pokemon.h"

void growlithe(mob* p2)
{
	strcpy(p2->name, "����");
	strcpy(p2->skillName, "���¢��");
	p2->hp = 75;
	p2->mp = 100;
	p2->basicDmg = 25;
	p2->skillDmg = 30;
	p2->mpCost = 25;
}
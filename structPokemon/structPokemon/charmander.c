#include "pokemon.h"

void charmander(mob* p1)
{
	strcpy(p1->name, "���̸�");
	strcpy(p1->skillName, "������");
	p1->hp = 80;
	p1->mp = 100;
	p1->basicDmg = 20;
	p1->skillDmg = 25;
	p1->mpCost = 35;
}
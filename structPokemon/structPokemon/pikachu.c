#include "pokemon.h"

void pikachu(mob* p1)
{
	strcpy(p1->name, "��ī��");
	strcpy(p1->skillName, "�����ũ");
	p1->hp = 75;
	p1->mp = 100;
	p1->basicDmg = 15;
	p1->skillDmg = 35;
	p1->mpCost = 40;
}
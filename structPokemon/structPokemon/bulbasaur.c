#include "pokemon.h"

void bulbasaur(mob* p1)
{
	strcpy(p1->name, "�̻��ؾ�");
	strcpy(p1->skillName, "���� ��ġ��");
	p1->hp = 150;
	p1->mp = 100;
	p1->basicDmg = 7;
	p1->skillDmg = 15;
	p1->mpCost = 25;
}
#include "pokemon.h"

void machop(mob* p2)
{
	strcpy(p2->name, "�����");
	strcpy(p2->skillName, "�±Ǵ��");
	p2->hp = 200;
	p2->mp = 75;
	p2->basicDmg = 5;
	p2->skillDmg = 7;
	p2->mpCost = 20;
}
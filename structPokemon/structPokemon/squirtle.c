#include "pokemon.h"

void squirtle(mob* p1) {
	strcpy(p1->name, "���α�");
	strcpy(p1->skillName, "���� ����");
	p1->hp = 100;
	p1->mp = 150;
	p1->basicDmg = 10;
	p1->skillDmg = 20;
	p1->mpCost = 30;
}
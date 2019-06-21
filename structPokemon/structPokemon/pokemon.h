#ifndef __POKEMON_H__
#define __POKEMON_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_POKEMON 4

typedef struct Mob {
	char name[20], skillName[20];
	int hp, mp, basicDmg, skillDmg, mpCost, isDead;
}mob;

void bulbasaur(mob* p1); //�̻��ؾ� �ʱ�ȭ
void pikachu(mob* p1); //��ī�� �ʱ�ȭ
void charmander(mob* p1); //���̸� �ʱ�ȭ
void squirtle(mob* p1); //���α� �ʱ�ȭ
void eevee(mob* p2); //�̺��� �ʱ�ȭ
void cubone(mob* p2); //������ �ʱ�ȭ
void machop(mob* p2); //����� �ʱ�ȭ
void growlithe(mob* p2); //���� �ʱ�ȭ
void coinToss(int *coin); // �� ���ϱ�
void printPPokemon(mob* p);// �÷��̾� ���ϸ� ���
void printPDmg(mob* p);// �÷��̾ �� ���ϸ��� ������ ���
int pickPokemon(int iPokemon);// ���ϸ� ����
int pickSkill(mob *p,int iSkill);// �⺻ ���� �Ǵ� ��ų ����
int checkGameOver(mob* p);// ���� ���� �Ǵ�

#endif
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

void bulbasaur(mob* p1); //이상해씨 초기화
void pikachu(mob* p1); //피카츄 초기화
void charmander(mob* p1); //파이리 초기화
void squirtle(mob* p1); //꼬부기 초기화
void eevee(mob* p2); //이브이 초기화
void cubone(mob* p2); //탕구리 초기화
void machop(mob* p2); //알통몬 초기화
void growlithe(mob* p2); //가디 초기화
void coinToss(int *coin); // 선 정하기
void printPPokemon(mob* p);// 플레이어 포켓몬 출력
void printPDmg(mob* p);// 플레이어가 고른 포켓몬의 데미지 출력
int pickPokemon(int iPokemon);// 포켓몬 고르기
int pickSkill(mob *p,int iSkill);// 기본 공격 또는 스킬 고르기
int checkGameOver(mob* p);// 게임 오버 판단

#endif
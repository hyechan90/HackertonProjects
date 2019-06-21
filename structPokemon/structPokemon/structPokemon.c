#include "pokemon.h"// 헤더파일

int main() {
	mob* p1[MAX_POKEMON];
	mob* p2[MAX_POKEMON];
	static int i, coin, iPokemon, iSkill, dmg, isGameOver;

	//플레이어1 메모리 할당
	for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
		p1[i] = malloc(sizeof(mob));
	}

	bulbasaur(p1[0]);// 플레이어 1의 포켓몬들 선언
	pikachu(p1[1]);
	charmander(p1[2]);
	squirtle(p1[3]);

	//플레이어2 메모리 할당
	for (i = 0; i < sizeof(p2) / sizeof(struct mob*); i++) {
		p2[i] = malloc(sizeof(mob));
	}

	eevee(p2[0]);//  플레이어 2의 포켓몬들 선언
	cubone(p2[1]);
	machop(p2[2]);
	growlithe(p2[3]);

	coinToss(&coin);// 동전을 던져서 선을 가림

	while (1) {
		printf("사용하실 포켓몬을 고르세요.\n");
		if (coin % 2) {// 코인이 홀수면 플레이어 1의 턴이고, 짝수면 플레이어 2의 턴
			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {// 플레이어 1의 포켓몬 출력
				printf("%d : ", i + 1);
				printPPokemon(p1[i]);
			}

			while (1) {
				iPokemon = pickPokemon(iPokemon);// 플레이어 1 포켓몬 선택
				if (p1[iPokemon]->hp <= 0)// 만약 선택한 포켓몬의 체력이 0이하면 사용 불가
					printf("그 포켓몬은 쓸 수 없습니다.\n");
				else
					break;
			}
			system("cls");

			printPDmg(p1[iPokemon]);// 기본 공격 또는 스킬 선택
			iSkill = pickSkill(p1[iPokemon],iSkill);
			system("cls");

			if (iSkill) {
				dmg = p1[iPokemon]->skillDmg;
				p1[iPokemon]->mp -= p1[iPokemon]->mpCost;
				printf("\"%s\"! %s!\n\n", p1[iPokemon]->name, p1[iPokemon]->skillName);
			}
			else
				dmg = p1[iPokemon]->basicDmg;

			printf("공격할 적 포켓몬을 정해주세요.\n");

			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {// 상대방 포켓몬 출력
				printf("%d : ", i + 1);
				printPPokemon(p2[i]);
			}
			while (1) {
				iPokemon = pickPokemon(iPokemon);
				if (p2[iPokemon]->hp <= 0)
					printf("그 포켓몬은 이미 쓰러졌습니다.\n");
				else
					break;
			}
			system("cls");

			p2[iPokemon]->hp -= dmg;

			coin++;
		}
		else {
			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
				printf("%d : ", i + 1);
				printPPokemon(p2[i]);
			}

			while (1) {
				iPokemon = pickPokemon(iPokemon);
				if (p2[iPokemon]->hp <= 0)
					printf("그 포켓몬은 쓸 수 없습니다.\n");
				else
					break;
			}
			system("cls");

			printPDmg(p2[iPokemon]);
			iSkill = pickSkill(p2[iPokemon], iSkill);
			system("cls");

			if (iSkill) {
				dmg = p2[iPokemon]->skillDmg;
				p2[iPokemon]->mp -= p2[iPokemon]->mpCost;
				printf("\"%s\"! %s!\n\n", p2[iPokemon]->name, p2[iPokemon]->skillName);
			}
			else {
				dmg = p2[iPokemon]->basicDmg;
			}

			printf("공격할 적 포켓몬을 정해주세요.\n");
			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
				printf("%d : ", i + 1);
				printPPokemon(p1[i]);
			}
			while (1) {
				iPokemon = pickPokemon(iPokemon);
				if (p1[iPokemon]->hp <= 0)
					printf("그 포켓몬은 이미 쓰러졌습니다.\n");
				else
					break;
			}
			system("cls");

			p1[iPokemon]->hp -= dmg;

			coin++;
		}

		//게임 오버 판단
		for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
			isGameOver += checkGameOver(p1[i]);
		}
		if (isGameOver == 4) {
			printf("플레이어 2님이 승리하셨습니다!\n");
			exit(0);
		}
		isGameOver = 0;

		for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
			isGameOver += checkGameOver(p2[i]);
		}
		if (isGameOver == 4) {
			printf("플레이어 1님이 승리하셨습니다!\n");
			exit(0);
		}
		isGameOver = 0;
	}

	//동적 메모리 해제
	for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
		free(p1[i]);
	}
	for (i = 0; i < sizeof(p2) / sizeof(struct mob*); i++) {
		free(p2[i]);
	}
}

//선 정하기
void coinToss(int *coin)
{
	srand(time(NULL));
	*coin = rand() % 2;
	if (*coin) {
		printf("플레이어 1 선\n");
	}
	else {
		printf("플레이어 2 선\n");
	}
}

// 플레이어 포켓몬 정하기
void printPPokemon(mob * p)
{
	printf("%s\t체력 : %d\t마나 : %d\n", p->name, p->hp, p->mp);
}

//포켓몬의 기본 공격, 스킬 데미지 출력
void printPDmg(mob * p)
{
	printf("하실 행동을 정하세요.\n");
	printf("1 : 기본 공격\t데미지 : %d\n", p->basicDmg);
	printf("2 : %s\t데미지 : %d\t사용 마나 : %d\n", p->skillName, p->skillDmg, p->mpCost);
}

//포켓몬 고르기
int pickPokemon(int iPokemon)
{
		scanf_s("%d", &iPokemon);// 값을 받은 다음 switch case문으로 판별
		switch (iPokemon)
		{
		case 1: // 배열은 0부터 시작하기 때문에 return 값은 1씩 낮춤
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
		case 4:
			return 3;
		default:
			printf("숫자를 이용해서 포켓몬을 정해주세요.\n");
			pickPokemon(iPokemon);
		}
}

//기본 공격 또는 스킬 고르기
int pickSkill(mob *p,int iSkill)
{
	while (1) {
		scanf_s("%d", &iSkill);
		switch (iSkill)
		{
		case 1:// 기본 공격
			return 0;
		case 2:// 스킬 사용
			if (p->mp < p->mpCost) {// 마나가 마나 사용량보다 적으면 못함
				printf("마나가 너무 적습니다.\n");
				break;
			}
			return 1;
		default:
			printf("숫자를 이용해서 포켓몬이 할 행동을 정해주세요.\n");
			break;
		}
	}
}
//게임 오버 판단
int checkGameOver(mob* p)
{
	if (p->hp <= 0)// 만약 포켓몬의 체력이 0이하면 1을 return함
		return 1;
}

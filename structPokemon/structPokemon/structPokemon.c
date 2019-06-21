#include "pokemon.h"// �������

int main() {
	mob* p1[MAX_POKEMON];
	mob* p2[MAX_POKEMON];
	static int i, coin, iPokemon, iSkill, dmg, isGameOver;

	//�÷��̾�1 �޸� �Ҵ�
	for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
		p1[i] = malloc(sizeof(mob));
	}

	bulbasaur(p1[0]);// �÷��̾� 1�� ���ϸ�� ����
	pikachu(p1[1]);
	charmander(p1[2]);
	squirtle(p1[3]);

	//�÷��̾�2 �޸� �Ҵ�
	for (i = 0; i < sizeof(p2) / sizeof(struct mob*); i++) {
		p2[i] = malloc(sizeof(mob));
	}

	eevee(p2[0]);//  �÷��̾� 2�� ���ϸ�� ����
	cubone(p2[1]);
	machop(p2[2]);
	growlithe(p2[3]);

	coinToss(&coin);// ������ ������ ���� ����

	while (1) {
		printf("����Ͻ� ���ϸ��� ������.\n");
		if (coin % 2) {// ������ Ȧ���� �÷��̾� 1�� ���̰�, ¦���� �÷��̾� 2�� ��
			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {// �÷��̾� 1�� ���ϸ� ���
				printf("%d : ", i + 1);
				printPPokemon(p1[i]);
			}

			while (1) {
				iPokemon = pickPokemon(iPokemon);// �÷��̾� 1 ���ϸ� ����
				if (p1[iPokemon]->hp <= 0)// ���� ������ ���ϸ��� ü���� 0���ϸ� ��� �Ұ�
					printf("�� ���ϸ��� �� �� �����ϴ�.\n");
				else
					break;
			}
			system("cls");

			printPDmg(p1[iPokemon]);// �⺻ ���� �Ǵ� ��ų ����
			iSkill = pickSkill(p1[iPokemon],iSkill);
			system("cls");

			if (iSkill) {
				dmg = p1[iPokemon]->skillDmg;
				p1[iPokemon]->mp -= p1[iPokemon]->mpCost;
				printf("\"%s\"! %s!\n\n", p1[iPokemon]->name, p1[iPokemon]->skillName);
			}
			else
				dmg = p1[iPokemon]->basicDmg;

			printf("������ �� ���ϸ��� �����ּ���.\n");

			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {// ���� ���ϸ� ���
				printf("%d : ", i + 1);
				printPPokemon(p2[i]);
			}
			while (1) {
				iPokemon = pickPokemon(iPokemon);
				if (p2[iPokemon]->hp <= 0)
					printf("�� ���ϸ��� �̹� ���������ϴ�.\n");
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
					printf("�� ���ϸ��� �� �� �����ϴ�.\n");
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

			printf("������ �� ���ϸ��� �����ּ���.\n");
			for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
				printf("%d : ", i + 1);
				printPPokemon(p1[i]);
			}
			while (1) {
				iPokemon = pickPokemon(iPokemon);
				if (p1[iPokemon]->hp <= 0)
					printf("�� ���ϸ��� �̹� ���������ϴ�.\n");
				else
					break;
			}
			system("cls");

			p1[iPokemon]->hp -= dmg;

			coin++;
		}

		//���� ���� �Ǵ�
		for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
			isGameOver += checkGameOver(p1[i]);
		}
		if (isGameOver == 4) {
			printf("�÷��̾� 2���� �¸��ϼ̽��ϴ�!\n");
			exit(0);
		}
		isGameOver = 0;

		for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
			isGameOver += checkGameOver(p2[i]);
		}
		if (isGameOver == 4) {
			printf("�÷��̾� 1���� �¸��ϼ̽��ϴ�!\n");
			exit(0);
		}
		isGameOver = 0;
	}

	//���� �޸� ����
	for (i = 0; i < sizeof(p1) / sizeof(struct mob*); i++) {
		free(p1[i]);
	}
	for (i = 0; i < sizeof(p2) / sizeof(struct mob*); i++) {
		free(p2[i]);
	}
}

//�� ���ϱ�
void coinToss(int *coin)
{
	srand(time(NULL));
	*coin = rand() % 2;
	if (*coin) {
		printf("�÷��̾� 1 ��\n");
	}
	else {
		printf("�÷��̾� 2 ��\n");
	}
}

// �÷��̾� ���ϸ� ���ϱ�
void printPPokemon(mob * p)
{
	printf("%s\tü�� : %d\t���� : %d\n", p->name, p->hp, p->mp);
}

//���ϸ��� �⺻ ����, ��ų ������ ���
void printPDmg(mob * p)
{
	printf("�Ͻ� �ൿ�� ���ϼ���.\n");
	printf("1 : �⺻ ����\t������ : %d\n", p->basicDmg);
	printf("2 : %s\t������ : %d\t��� ���� : %d\n", p->skillName, p->skillDmg, p->mpCost);
}

//���ϸ� ����
int pickPokemon(int iPokemon)
{
		scanf_s("%d", &iPokemon);// ���� ���� ���� switch case������ �Ǻ�
		switch (iPokemon)
		{
		case 1: // �迭�� 0���� �����ϱ� ������ return ���� 1�� ����
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
		case 4:
			return 3;
		default:
			printf("���ڸ� �̿��ؼ� ���ϸ��� �����ּ���.\n");
			pickPokemon(iPokemon);
		}
}

//�⺻ ���� �Ǵ� ��ų ����
int pickSkill(mob *p,int iSkill)
{
	while (1) {
		scanf_s("%d", &iSkill);
		switch (iSkill)
		{
		case 1:// �⺻ ����
			return 0;
		case 2:// ��ų ���
			if (p->mp < p->mpCost) {// ������ ���� ��뷮���� ������ ����
				printf("������ �ʹ� �����ϴ�.\n");
				break;
			}
			return 1;
		default:
			printf("���ڸ� �̿��ؼ� ���ϸ��� �� �ൿ�� �����ּ���.\n");
			break;
		}
	}
}

//���� ���� �Ǵ�
int checkGameOver(mob* p)
{
	if (p->hp <= 0)// ���� ���ϸ��� ü���� 0���ϸ� 1�� return��
		return 1;
}
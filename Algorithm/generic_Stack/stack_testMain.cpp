#include "stack.h"
#include <stdio.h>

int menu(char **, int);
void myFlush();
void input(Stack *);
void myDelete(Stack *);

int main()
{
	Stack stk;   /* ���û���*/
	char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����"}; /* �޴� ����Ʈ*/
	int menuCnt;   /* �޴����� ���庯��*/
	int menuNum;   /* �޴���ȣ ���庯��*/

	initStack(&stk, 5, sizeof(Person)); /* ���� �ʱ�ȭ*/
	menuCnt = sizeof(menuList)/sizeof(menuList[0]);  /* �޴� ���� ����ϱ�*/

	while(1)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum == menuCnt)  /* ����޴� ���� �� �ݺ��� Ż���ϱ�*/
		{
			break;
		}
		switch(menuNum)
		{
		case 1 : input(&stk);  break;
		case 2 : myDelete(&stk); break;
		case 3 : printStack(&stk, sizeof(Person), personPrint); /* stack���� ��� ������ ����ϱ�*/
		}
	}
	destroyStack(&stk, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: input() - ���ÿ� �����͸� �ݺ������� �Է���
��������: sPtr - ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void input(Stack *sPtr)
{
	Person in;
	char name[20];

	in.name = (char*)calloc(20, sizeof(char));

	while (1) {
		printf("�̸��� �Է� �Ͻÿ�(�� �Է½� ����) : ");
		scanf("%s", name);
		if (strcmp(name, "��") == 0) // "��"�Է½� ����
			break;

		myFlush();

		strcpy(in.name, name);

		printf("���̸� �Է� �Ͻÿ� : ");
		scanf("%d", &in.age);
		printf("��ȭ��ȣ�� �Է� �Ͻÿ� : ");
		scanf("%s", in.phoneNumber);

		if (push(sPtr, &in, sizeof(Person), personMemCpy) != 1)
			printf("push ���� ! \n");
	}

	free(in.name);
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: myDelete() - ������ �����͸� �ݺ������� ����
��������: sPtr - ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sPtr)
{
	int popCnt, i;
	void *popP;

	popP = calloc(1, sizeof(Person));

	printf("Stack���� �����͸� pop�� ȸ���� �Է��Ͻÿ� : ");
	scanf("%d", &popCnt);

	for (i = 0; i < popCnt; i++) {
		if ((pop(sPtr, popP, sizeof(Person), personMemCpy, personClear)) == 1)
			personPrint(popP);
		else
			printf("pop ����! \n");
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
��������: menuLIst - �޴������ ���ڿ�
menuCnt  - �޴�����
���ϰ�: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum=0; /* �Էµȸ޴���ȣ���庯��*/
	int res;       /* scanf()�Լ��Ǹ��ϰ����庯��*/
	for(i=0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i+1, menuList[i]);
	}

	while(menuNum<1 || menuNum>menuCnt)  /* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%d", &menuNum);
		if(res!=1)  /* ������ �Էµ��� �ʾ�����*/
		{ 
			myFlush();  /* �Է¹��� ����*/
			continue;  
		}
	}
	return menuNum;
}   
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: myFlush() - �Է¹��� �����
��������: ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void myFlush()
{
	while(getchar()!='\n')
	{ ; }
}
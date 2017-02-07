#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

int menu(char **mList, size_t menuCnt);
void dataFileLoad(LinkedList *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
void dataFileSave(LinkedList *lp); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
void mInput(LinkedList *lp);       // �Է¸޴� ó�� �Լ�
void mSearch(LinkedList *lp);      // ���ϰ˻��޴� ó�� �Լ�
void mDupSearch(LinkedList *lp);   // ���߰˻��޴� ó�� �Լ�
void mDelete(LinkedList *lp);      // �����޴� ó�� �Լ�
/*----------------------------------------------------------------------------------
  �Լ��� : main() 
----------------------------------------------------------------------------------*/
int main()
{
	char *menuList[] = {"�Է��ϱ�","����ϱ�","���ϰ˻��ϱ�","���߰˻��ϱ�", "�����ϱ�", "����� �����ϱ�", "���̼� �����ϱ�","��  ��"};
	int menuNum;    //�޴���ȣ ���� ����
	int menuCnt;    //�޴����� ���� ����
	LinkedList list;  //����Ʈ���� ����ü ����
	Person a;

	menuCnt = sizeof(menuList)/sizeof(menuList[0]);

	create(&list);      // ����ִ� ����Ʈ ���� �� �ʱ�ȭ
	dataFileLoad(&list); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
	while(1)    
	{
		      // ����ִ� ����Ʈ ���� �� �ʱ�ȭ

		menuNum = menu(menuList, menuCnt); //�޴�ȭ���� ���� �޴���ȣ�� �Է� ����
		if(menuNum==menuCnt) { break; }
		switch(menuNum)
		{
		case 1 : mInput(&list); break;               // �Է¸޴� ����
		case 2 : display(&list, printPerson);  break; // ��¸޴� ����
		case 3 : mSearch(&list); break;              // ���ϰ˻��޴� ����
		case 4 : mDupSearch(&list); break;           // ���߰˻��޴� ����
		case 5 : mDelete(&list); break;              // �����޴� ����
		case 6: sortList(&list, sizeof(a), personNameCompare, personMemCpy, personClear); break; // ����� ���ĸ޴� ����
		case 7 : sortList(&list, sizeof(a), personAgeCompare, personMemCpy, personClear); break;  // ���̼� ���ĸ޴� ����
		}
	}
	//dataFileSave(&list); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
	destroy(&list, personClear); 
	
	return 0;
}
/*----------------------------------------------------------------------------------
  �Լ��� : menu()
----------------------------------------------------------------------------------*/
int menu(char **mList, size_t menuCnt)
{
	size_t menuNum=0;  // �������� �ʴ� �޴� ��ȣ ���� 
	size_t i;

	printf("\n\n");
	for(i=0; i<menuCnt; i++)  // �޴� ���
	{
		printf("%d. %s\n", i+1, mList[i]);
	}

	while(menuNum<1 || menuNum>menuCnt) // �޴���ȣ�� ��ȿ���� ���� ���� �ݺ�
	{
		printf("# �޴� ���� : ");
		scanf("%d", &menuNum);  // �޴� ��ȣ �Է�
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
  �Լ��� : mInput()
----------------------------------------------------------------------------------*/
void mInput(LinkedList *lp)
{
	Person inData;
	char name[20], phone[16];
	inData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ �Է��ϱ� �޴� ]\n\n");
	while(1)
	{
		printf("# �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", name);
		if(strcmp(name,"��")==0) // "��"�Է½� ����
			break;

		strcpy(inData.name, name);

		printf("# ������ �Է��ϼ��� : ");
		scanf("%d", &inData.age);

		printf("# �ڵ��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%s", inData.phoneNumber);
		
		// tail ��� �տ� ������ �߰� 
		appendFromHead(lp, &inData, sizeof(inData), personMemCpy); 
	}
	return;
}
/*----------------------------------------------------------------------------------
  �Լ��� : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp)
{
	Person sData;
	Node *resp;
	char name[20];

	sData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while(1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", name);
		if(strcmp(name,"��")==0) // "��"�Է½� ����
			break; 

		strcpy(sData.name, name);

		resp = linearSearchUnique(lp, &sData, personNameCompare);
		if(resp!=NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� �����մϴ� : ");
			printPerson(resp + 1);
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}

	free(sData.name);
	return ;
}
/*----------------------------------------------------------------------------------
  �Լ��� : mDelete()
----------------------------------------------------------------------------------*/
void mDelete(LinkedList * lp)
{
	Person dData;
	Node *resp; // ������ ����� �ּ� ���� ����
	char name[20];

	dData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ �����ϱ� �޴�] \n\n");
	while(1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", name);
		if (strcmp(name, "��") == 0) // "��"�Է½� ����
			break;

		strcpy(dData.name, name);

		resp = linearSearchUnique(lp, &dData, personNameCompare);
		if(resp!=NULL) // ã������
		{	
			deleteNode(lp, resp, personClear); //�ش� ��带 ����
			printf("@ �����Ͽ����ϴ�.\n\n");
		}
		else //�����Ͱ� ������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}

	free(dData.name);

	return ;
}
/*----------------------------------------------------------------------------------
  �Լ��� : mDupSearch()
----------------------------------------------------------------------------------*/
void mDupSearch(LinkedList * lp)
{
	Node **searchPtr; // ã�� ����� �ּҵ��� ������ �迭�� �����ּҸ� ����ų ������
	int searchCnt, i;    // ã�� ����� ��
	Person sData;
	char name[20];

	sData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ ���� �˻��ϱ� �޴� ]\n\n");
	while(1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", name);
		if (strcmp(name, "��") == 0) // "��"�Է½� ����
			break;

		strcpy(sData.name, name);
		searchPtr = linearSearchDuplicate(lp, &sData, &searchCnt, personNameCompare);

		if(searchPtr!=NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� %d�� �����մϴ�.\n", searchCnt);
			for(i=0; i<searchCnt; i++) // ã�� ���� ��ŭ ������ ����ϱ�
			{
				printf("%d. ", i + 1);  
				printPerson(searchPtr[i] + 1);
			}
			free(searchPtr);  // ã������� �ּҸ� ��� �ִ� Node *�迭 �޸� ����
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}

	free(sData.name);
	return ;
}
/*----------------------------------------------------------------------------------
  �Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	fp=fopen("c:\\data\\ListData.txt", "rt");
	assert(fp!=NULL);
	Person inData;
	char name[20];   // ���� ����
	
	while(fscanf(fp, "%s", name)!=EOF)
	{
		fscanf(fp, "%d", &inData.age);
		strcpy(inData.name, name);
		appendFromTail(lp, &inData, sizeof(inData), personMemCpy);
	}
	fclose(fp);
}
/*----------------------------------------------------------------------------------
  �Լ��� : dataFileSave()
----------------------------------------------------------------------------------*/
void dataFileSave(LinkedList *lp) // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
{
	FILE *fp;
	fp=fopen(":\\data\\ListData.txt", "wt");
	assert(fp!=NULL);
	
	lp->cur = lp->head->next;
	while(lp->cur != lp->tail)
	{
		//fprintf(fp, "%s %d\n", lp->cur->data.name, lp->cur->data.age);
		lp->cur = lp->cur->next;
	}
	fclose(fp);
}
//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------
int comparePersonName(void *p1, void *p2) // Person ����ü�� name����� ���ϴ� �Լ�
{
	return ( strcmp(((Person*)p1)->name, ((Person*)p2)->name) );  // strcmp()�Լ��� ���ϰ��� �ٷ� ����
}
int comparePersonAge(void *p1, void *p2) // Person ����ü�� age����� ���ϴ� �Լ�
{
	if(((Person*)p1)->age > ((Person*)p2)->age) return 1;
	else if(((Person*)p1)->age == ((Person*)p2)->age) return 0;
	else return -1;
}

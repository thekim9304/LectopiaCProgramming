#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <Windows.h>
#include "doublelinkedlist.h"

void dataFileLoad(LinkedList *lp, char *); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
void saveLine(LinkedList *viewer, LinkedList *output, int startLine);

int main()
{	
	LinkedList viewer, output;
	char dataFileName[100];
	char keyInput;
	int startLine = 1, endLine = 24;

	printf("����� ������ �Է� �Ͻÿ� : ");
	scanf("%s", dataFileName);

	create(&viewer);
	create(&output);
	dataFileLoad(&viewer, dataFileName);

	saveLine(&viewer, &output, startLine);
	display(&output, printWord);

	while ((keyInput = getch()) != 'e') {
		if ((keyInput == 'w') && startLine != 1) {
			startLine--;
			system("cls");
			saveLine(&viewer, &output, startLine);
			display(&output, printWord);
		}
		else if ((keyInput == 's') && ((startLine + 24) <= viewer.tail->prev->data.lineNumber)) {
			startLine++;
			system("cls");
			saveLine(&viewer, &output, startLine);
			display(&output, printWord);
		}
	}
}

void saveLine(LinkedList *viewer, LinkedList *output, int startLine)
{
	Node *check;
	int i;

	check = viewer->head->next;

	while (check != viewer->tail) {
		if (check->data.lineNumber == startLine)
			break;
		check = check->next;
	}

	for (i = 0; i < 24; i++) {
		appendFromTail(output, &(check->data));
		check = check->next;
	}
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp, char *dataFileName) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	fp = fopen(dataFileName, "rt");
	assert(fp != NULL);
	DataType inData;
	char text[81];   // ���� ����
	inData.lineNumber = 0;

	while (fgets(text, sizeof(text), fp) != NULL)
	{
		inData.lineNumber++;
		text[strlen(text) - 1] = '\0';
		strcpy(inData.word, text);
		appendFromTail(lp, &inData);
	}
	fclose(fp);
}
//-------------------------------------
//   word ����ü ���� �Լ�
//-------------------------------------
int compareWord(DataType *p1, DataType *p2) // Person ����ü�� name����� ���ϴ� �Լ�
{
	return (strcmp(p1->word, p2->word));  // strcmp()�Լ��� ���ϰ��� �ٷ� ����
}

void printWord(DataType *p)  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
{
	printf("%s \n", p->word);
}
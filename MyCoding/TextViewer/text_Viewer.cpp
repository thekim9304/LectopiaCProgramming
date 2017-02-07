#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <Windows.h>
#include "doublelinkedlist.h"

void dataFileLoad(LinkedList *lp, char *); // 데이터 파일내의 데이터를 리스트에 저장 
void saveLine(LinkedList *viewer, LinkedList *output, int startLine);

int main()
{	
	LinkedList viewer, output;
	char dataFileName[100];
	char keyInput;
	int startLine = 1, endLine = 24;

	printf("출력할 파일을 입력 하시오 : ");
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
함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp, char *dataFileName) // 데이터 파일내의 데이터를 리스트에 저장 
{
	FILE *fp;
	fp = fopen(dataFileName, "rt");
	assert(fp != NULL);
	DataType inData;
	char text[81];   // 성명 저장
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
//   word 구조체 보조 함수
//-------------------------------------
int compareWord(DataType *p1, DataType *p2) // Person 구조체의 name멤버로 비교하는 함수
{
	return (strcmp(p1->word, p2->word));  // strcmp()함수의 리턴값을 바로 리턴
}

void printWord(DataType *p)  // Person 구조체의 모든 멤버를 출력하는 함수 
{
	printf("%s \n", p->word);
}
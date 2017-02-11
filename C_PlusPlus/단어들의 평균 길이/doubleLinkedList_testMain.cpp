#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

int count, lengthAve;

void dataFileLoad(LinkedList *lp, char *); // 데이터 파일내의 데이터를 리스트에 저장 
/*----------------------------------------------------------------------------------
  함수명 : main() 
----------------------------------------------------------------------------------*/
int main()
{
	LinkedList wordSave;
	char dataFileName[100];

	create(&wordSave);

	printf("출력할 파일을 입력 하시오 : ");
	scanf("%s", dataFileName);

	dataFileLoad(&wordSave, dataFileName);

	display(&wordSave, personPrint);

	printf("\n전체 단어의 개수 : %d  \t\t\t 평균 단어 길이 : %d\n", count - 1, (lengthAve / count));
}

/*----------------------------------------------------------------------------------
  함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp, char *dataFileName) // 데이터 파일내의 데이터를 리스트에 저장 
{
	FILE *fp;
	Word word;
	Node *ret;
	char text[20];

	word.wp = (char*)calloc(1, sizeof(text));
	count = 1;
	lengthAve = 0;
		 
	fp = fopen(dataFileName, "rt");
	assert(fp != NULL);

	while (fscanf(fp, "%s", text) != EOF)
	{
		text[strlen(text)] = '\0';
		strcpy(word.wp, text);
		word.length = strlen(word.wp);

		if ((ret = linearSearchUnique(lp, &word, personNameCompare)) == NULL) {
			lengthAve += word.length;
			word.count = count++;
			appendFromTail(lp, &word, sizeof(Word), personMemCpy);
		}
	}
	fclose(fp);
}


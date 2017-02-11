#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

int count, lengthAve;

void dataFileLoad(LinkedList *lp, char *); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
/*----------------------------------------------------------------------------------
  �Լ��� : main() 
----------------------------------------------------------------------------------*/
int main()
{
	LinkedList wordSave;
	char dataFileName[100];

	create(&wordSave);

	printf("����� ������ �Է� �Ͻÿ� : ");
	scanf("%s", dataFileName);

	dataFileLoad(&wordSave, dataFileName);

	display(&wordSave, personPrint);

	printf("\n��ü �ܾ��� ���� : %d  \t\t\t ��� �ܾ� ���� : %d\n", count - 1, (lengthAve / count));
}

/*----------------------------------------------------------------------------------
  �Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp, char *dataFileName) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
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


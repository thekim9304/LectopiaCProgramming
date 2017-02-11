/*Person ����ü�� ���õ� �����Լ��� ����*/
#include "person.h"

int i = 1;

void personClear(void *p) 
{
	if (((Word*)p)->wp != NULL) {
		free(((Word*)p)->wp);
	}

	((Word*)p)->wp = NULL;
}

void personPrint(void *p) 
{
	printf("%2d ��° �ܾ� : %-30s  �ܾ���� : %4d\n", i, ((Word*)p)->wp, ((Word*)p)->length);

	i++;
}

int personNameCompare(void *p1, void *p2)
{
	return strcmp(((Word*)p1)->wp, ((Word*)p2)->wp);
}

void personMemCpy(void *p1, void *p2)
{
	personClear(p1);  // name����� �޸� ����
	if (((Word *)p2)->wp != NULL)
	{
		((Word *)p1)->wp = (char *)calloc(strlen(((Word *)p2)->wp) + 1, sizeof(char));
		strcpy(((Word *)p1)->wp, ((Word *)p2)->wp);
	}


	((Word *)p1)->length = ((Word *)p2)->length;
}

/*Person 구조체와 관련된 보조함수들 정의*/
#include "person.h"

void personClear(void *p) 
{
	if (((Person*)p)->name != NULL) {
		free(((Person*)p)->name);
	}

	((Person*)p)->name = NULL;
}

void personPrint(void *p) 
{
	printf("성명 : %s(%d세), 주소 : %s\n", ((Person*)p)->name, ((Person*)p)->age, ((Person*)p)->phoneNumber);
}

int personNameCompare(void *p1, void *p2)
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}

int personAgeCompare(void *p1, void *p2)
{
	if (((Person*)p1)->age > ((Person*)p2)->age)
		return 1;
	else if (((Person*)p1)->age < ((Person*)p2)->age)
		return -1;
	else
		return 0;
}

int personCompare(void *p1, void *p2)
{
	if ((personAgeCompare(p1, p2) == 0) && (personNameCompare(p1, p2) == 0))
		return 0;
	else
		return 1;
}

void personMemCpy(void *p1, void *p2)
{
	personClear(p1);  // name멤버의 메모리 해제
	if (((Person *)p2)->name != NULL)
	{
		((Person *)p1)->name = (char *)calloc(strlen(((Person *)p2)->name) + 1, sizeof(char));
		strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	}


	((Person *)p1)->age = ((Person *)p2)->age;

	strcpy(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);

}

void printPerson(void *p)
{
	printf(" %s : %d : %s\n", ((Person*)p)->name, ((Person*)p)->age, ((Person*)p)->phoneNumber);
}
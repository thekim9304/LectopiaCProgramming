#include "person.h"

void inputPerson(Person *per, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		printf("%d번째 사람 이름 : ", i + 1);
		scanf("%s", per[i].name);
		printf("            나이 : ");
		scanf("%d", &(per[i].age));
		printf("     휴대폰 번호 : ");
		scanf("%s", per[i].phoneNumber);
	}
}

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *))
{
	while ((compareData(begin, value) != 0) && begin != end) {
		begin = (char*)begin + size;
	}

	return begin;
}


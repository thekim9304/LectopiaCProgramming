#include "person.h"

void inputPerson(Person *per, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		printf("%d��° ��� �̸� : ", i + 1);
		scanf("%s", per[i].name);
		printf("            ���� : ");
		scanf("%d", &(per[i].age));
		printf("     �޴��� ��ȣ : ");
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


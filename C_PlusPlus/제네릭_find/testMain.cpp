#include "person.h"

int compareName(void *vp1, void *vp2);     // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
int compareAge(void *vp1, void *vp2);  // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����

int main()
{
	Person per[100] = { 0 }; // 100�� ������ ��� ���� �Է�
	int count, psSize, select, searchAge, *ip; // ���� �Է¼�, ����ü 1�� ũ��, �˻� ���� ����, ���� �˻� ��, ���� �˻� ��� �ּ�
	char searchName[20], *cp; // �̸� �˻� ��, �̸� �˻� ��� �ּ�

	printf("�Է��� ����� �� : ");
	scanf("%d", &count);

	inputPerson(per, count); // ������ ��� �� ��ŭ ���� �Է�
	
	psSize = sizeof(per[0]); // ����ü 1���� ũ��

	while (1) {
		printf("�˻��� �̿��� ���� ����(1. �̸�/ 2. ����/ 3. ����) : ");
		scanf("%d", &select);

		if (select == 3)
			break;

		switch (select) {
		case 1:
			printf("�̸��� �Է� �Ͻÿ� : ");
			scanf("%s", searchName);
			cp = (char*)find(per[0].name, per[count].name, searchName, psSize, compareName);

			if (cp == per[count].name)
				printf("not find\n\n");
			else {
				printf("find data = %s\n", cp);
				printf("���� : %d\n", *((char*)cp + 20));
				printf("��ȭ��ȣ : %s\n\n", (char*)cp + 24);
			}
			break;
		case 2:
			printf("���̸� �Է� �Ͻÿ� : ");
			scanf("%d", &searchAge);
			ip = (int*)find(&(per[0].age), &(per[count].age), &searchAge, psSize, compareAge);
			
			if (ip == &(per[count].age))
				printf("not find\n");
			else {
				printf("find data = %d\n", *ip);
				printf("�̸� : %s\n", (char*)ip - 20);
				printf("��ȭ��ȣ : %s\n\n", (char*)ip + 4);
			}
			break;
		}
	}
}

int compareName(void *vp1, void *vp2)
{
	return strcmp((char*)vp1, (char*)vp2);
}

int compareAge(void *vp1, void *vp2)
{
	if (*(int*)vp1 > *(int*)vp2)
		return 1;
	else if (*(int*)vp1 < *(int*)vp2)
		return -1;
	else
		return 0;
}
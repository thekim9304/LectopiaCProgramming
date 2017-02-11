#include "person.h"

int compareName(void *vp1, void *vp2);     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int compareAge(void *vp1, void *vp2);  // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴

int main()
{
	Person per[100] = { 0 }; // 100명 이하의 사람 정보 입력
	int count, psSize, select, searchAge, *ip; // 정보 입력수, 구조체 1개 크기, 검색 정보 선택, 나이 검색 값, 나이 검색 결과 주소
	char searchName[20], *cp; // 이름 검색 값, 이름 검색 결과 주소

	printf("입력할 사람의 수 : ");
	scanf("%d", &count);

	inputPerson(per, count); // 선택한 사람 수 만큼 정보 입력
	
	psSize = sizeof(per[0]); // 구조체 1개의 크기

	while (1) {
		printf("검색에 이용할 정보 선택(1. 이름/ 2. 나이/ 3. 종료) : ");
		scanf("%d", &select);

		if (select == 3)
			break;

		switch (select) {
		case 1:
			printf("이름을 입력 하시오 : ");
			scanf("%s", searchName);
			cp = (char*)find(per[0].name, per[count].name, searchName, psSize, compareName);

			if (cp == per[count].name)
				printf("not find\n\n");
			else {
				printf("find data = %s\n", cp);
				printf("나이 : %d\n", *((char*)cp + 20));
				printf("전화번호 : %s\n\n", (char*)cp + 24);
			}
			break;
		case 2:
			printf("나이를 입력 하시오 : ");
			scanf("%d", &searchAge);
			ip = (int*)find(&(per[0].age), &(per[count].age), &searchAge, psSize, compareAge);
			
			if (ip == &(per[count].age))
				printf("not find\n");
			else {
				printf("find data = %d\n", *ip);
				printf("이름 : %s\n", (char*)ip - 20);
				printf("전화번호 : %s\n\n", (char*)ip + 4);
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
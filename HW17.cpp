#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char name[1000], sex;
	double height;

	printf("# 성명 입력 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &height);

	getchar();

	printf("# 성별입력(M/F) : ");
	scanf("%c", &sex);

	if (sex == 'M' || sex == 'm')
		printf("%s씨의 키는 %.2lf이고 남성입니다.", name, height);
	else
		printf("%s씨의 키는 %.2lf이고 여성입니다.", name, height);
}
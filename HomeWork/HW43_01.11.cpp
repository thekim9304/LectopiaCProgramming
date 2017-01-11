/*
	!삼각 알파벳 출력하기

	영문자 대문자를 입력 받아 그 문자부터 'A' 문자까지 다음과 같이 출력하시오.
	반복 수행하고 영문자 대문자 이외에 다른 문자 입력 시 종료 하십시오.
	단, 변수는 iterator변수 i, j 와 입력된 문자 저장변수 1개만 사용하여 총 3개의 변수만 사용할 것

	@2017.01.11 pm10:58
*/
#if 01
#include <stdio.h>

int main()
{
	int i, j;
	char inputAlpa;

	while (1)
	{
		printf("* 영문자 대문자 입력( 'A' ~ 'Z' ) : ");
		scanf("%c", &inputAlpa);

		if ((inputAlpa >= 'A' && inputAlpa <= 'Z') != 1)
			break;

		for (i = 0; i <= (inputAlpa - 'A'); i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("%c", (inputAlpa - j));
			}
			printf("\n");
		}

		getchar();
	}
}
#endif
/*
	!! 문자 종류별 카운트 프로그램(getch()함수 이용)

	영문 문장을 키보드로 부터 입력 받아 각각 문자를 종류별로 카운트하여 출력하시오.
	입력 종료 조건 : 새물(new line)에서 EOF 입력 시 종료 함

	@2017.01.08 pm1:49
*/

#if 0
#include <stdio.h>
#include <conio.h>

int main()
{
	char input;
	int textEnglish = 0, textNumber = 0, textBlank = 0, textRest = 0;

	while ((input = getchar()) != EOF)
	{
		if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
			textEnglish++;
		else if ((input >= 48 && input <= 57))
			textNumber++;
		else if (input == 9 || input == 10 || input == 32)
			textBlank++;
		else
			textRest++;	
	}

	printf("* 영문자 대소문자 개수 : %d\n", textEnglish);
	printf("* 숫자문자 개수 : %d\n", textNumber);
	printf("* 여백문자(space, tab, enter) 개수 : %d\n", textBlank);
	printf("* 그 외 기타문자 개수 : %d\n", textRest);
	
}
#endif
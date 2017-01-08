/*
	!!2 진수 변환 프로그램

	10진수를 입력 받아 2진수로 출력하는 프로그램을 작성하시오.
	Bit조절 연산자 및 반복문을 사용하며 음수는 2의 보수 상태로 출력 함

	@2017.01.06 pm07:10
*/

#if 0
#include <stdio.h>

int main()
{
	unsigned int inputBinary, calculator, i, result;

	printf("* 10진수 정수를 입력하시오 : ");
	scanf("%u", &inputBinary);

	calculator = 0x80000000;

	printf("%u(10) = ", inputBinary);

	for (i = 0; i <= 31; i++)
	{ 
		result = (inputBinary & calculator) >> (31-i);

		if (result == 1)
			printf("1");
		else
			printf("0");

		calculator = calculator >> 1;
	}
	printf("(2)\n");
}
#endif
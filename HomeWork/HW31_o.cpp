/*
	!!bit 조절하기

	아래 함수 작성 후 테스트 프로그램 작성

	int getBit(int num, int i)      // num변수의 2의 i승 bit값이 0이면 0, 1이면 1을 리턴
	int setBit(int num, int i)      // num변수의 2의 i승 bit값을 1로 만든 후 num값 리턴
	int clearBit(int num, int i)    // num변수의 2의 i승 bit값을 0으로 만든 후 num값 리턴
	int clearBitsMSBthroughI(int num, int i) // MSB부터 i승 비트까지 모두 0으로 지움
	int clearBitsIthrough0(int num, int i)  // i승 비트 ~ 0승 비트까지 모두 0으로 지움
	int updateBit(int num, int i, int value) // i승 비트의 값을 value(0 or 1)값으로 변경
	
	@2017.01.07 pm01:49
*/
#if 0
#include <stdio.h>

int getBit(int num, int i);
int setBit(int num, int i);
int clearBit(int num, int i);
int clearBitsMSBthroughI(int num, int i);
int clearBitsIthrough0(int num, int i);
int updateBit(int num, int i, int value);
void outputBinary(int num);
void testProgram(int);

int main()
{
	int input;

	printf("1.getBit, 2.setBit, 3.clearBit\n");
	printf("4.clearBitsMSBthroughI, 5.clearBitsIthrough0, 6.updateBit\n");
	printf("선택 하시오 : ");
	scanf("%d", &input);

	testProgram(input);
}

void testProgram(int input)
{
	int num, i, value;

	switch (input)
	{
	case 1:
		printf("num값 승수 입력 : ");
		scanf("%d %d", &num, &i);
		printf("%d", getBit(num, i));
		break;
	case 2:
		printf("num값 승수 입력 : ");
		scanf("%d %d", &num, &i);
		outputBinary(setBit(num, i));
		break;
	case 3:
		printf("num값 승수 입력 : ");
		scanf("%d %d", &num, &i);
		outputBinary(clearBit(num, i));
		break;
	case 4:
		printf("num값 승수 입력 : ");
		scanf("%d %d", &num, &i);
		outputBinary(clearBitsMSBthroughI(num, i));
		break;
	case 5:
		printf("num값 승수 입력 : ");
		scanf("%d %d", &num, &i);
		outputBinary(clearBitsIthrough0(num, i));
		break;
	case 6:
		printf("num값 승수 Value 입력 : ");
		scanf("%d %d %d", &num, &i, &value);
		outputBinary(updateBit(num, i, value));
		break;
	}
}

int updateBit(int num, int i, int value) // i승 비트의 값을 value(0 or 1)값으로 변경
{
	if (value == 1)
	{
		unsigned int calculator = 0x80000000;

		calculator = (calculator >> (31 - i) | (calculator << i + 1));

		num = num | calculator;

		return num;
	}
	else
	{
		unsigned int calculator = 0x7fffffff;
		int calcu = 0x80000000;

		calculator = (calculator >> (31 - i) | (calculator << i + 1));

		num = num & calculator;

		return num;
	}
}

int clearBitsIthrough0(int num, int i)  // i승 비트 ~ 0승 비트까지 모두 0으로 지움
{
	unsigned int calculator = 0xfffffffe, result;
	int k;

	for (k = 0; k <= i; k++)
	{
		result = num & calculator;

		calculator = calculator << 1;
	}

	return result;
}

int clearBitsMSBthroughI(int num, int i) // MSB부터 i승 비트까지 모두 0으로 지움
{
	unsigned int calculator = 0x7fffffff, result;
	int k;

	for (k = 0; k <= (31 - i); k++)
	{
		result = num & calculator;

		calculator = calculator >> 1;
	}

	return result;
}

int clearBit(int num, int i)    // num변수의 2의 i승 bit값을 0으로 만든 후 num값 리턴
{
	unsigned int calculator = 0x7fffffff;

	calculator = (calculator >> (31 - i) | (calculator << i + 1));

	num = num & calculator;

	return num;
	/*
	unsigned int calculator = 0x7fffffff;
	int calcu = 0x80000000;

	calculator = calculator >> (31 - i);

	num = num & calculator;

	return num;
	*/
}

int setBit(int num, int i)   // num변수의 2의 i승 bit값을 1로 만든 후 num값 리턴
{
	unsigned int calculator = 0x80000000;

	calculator = (calculator >> (31 - i) | (calculator << i + 1));

	num = num | calculator;

	return num;
	/*
	unsigned int calculator = 0x80000000;

	calculator = calculator >> (31 - i);

	num = num | calculator;

	return num;
	*/
}

int getBit(int num, int i) // num변수의 2의 i승 bit값이 0이면 0, 1이면 1을 리턴
{
	unsigned int calculator = 0x80000000;

	calculator = calculator >> (31 - i);

	num = num & calculator;

	num = num >> i;

	if (num == 1)
		return 1;
	else
		return 0;
}

void outputBinary(int num)
{
	unsigned int calculator = 0x80000000, result;
	int i;

	for (i = 0; i <= 31; i++)
	{
		result = (num & calculator) >> (31 - i);

		if (result == 1)
			printf("1");
		else
			printf("0");

		calculator = calculator >> 1;
	}
	printf("(2)\n");
}
#endif
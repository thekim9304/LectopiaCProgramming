#if 0
#include <stdio.h>

void printAge(int outA);
void printHeight(double outH);

int main()
{
	char name[20] = "김태형";
	int age = 25;
	double height = 173.2;

	printf("성명 : %s \n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int outA)
{
	printf("나이 : %d \n", outA);
}

void printHeight(double outH)
{
	printf("키 : %f \n", outH);
}
#endif
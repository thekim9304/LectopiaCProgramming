/*
	!! 실행결과에 맞도록 str_prn함수를 선언하고 정의하여 다음 프로그램을 완성하자. 
	   str_prn함수는 하나만 작성하며 문자를 처리하는 두 번째 매개변수는 기본 전달인자를 사용한다.

	@ 2017.02.14 
*/

#if 0
#include <iostream>

using namespace std;

int my_strlen(char *, char = '\0');

int main()
{
	char strIn[100], check;
	int strLength;

	cout << "문자열 입력 : ";
	cin >> strIn;
	cout << "문자열의 길이 : " << my_strlen(strIn) << endl;

	cout << "문자 입력 : ";
	cin >> check;
	cout << check << "이전 까지의 길이 : " << my_strlen(strIn, check) << endl;

	cout << "문자 입력 : ";
	cin >> check;
	cout << check << "이전 까지의 길이 : " << my_strlen(strIn, check) << endl;
}

int my_strlen(char *str, char check)
{
	int count = 0;

	while (str[count++] != check) {
		if (str[count - 1] == '\0')
			break;
	}

	return count - 1;
}
#endif
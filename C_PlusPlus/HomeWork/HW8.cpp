/*
	!! 포인터변수가 연결하고 있는 두 개의 문자열을 출력하고 포인터변수의 값을 서로 바꾼 후에 다시 한번 두 문자열을 출력한다.
	포인터변수의 값을 바꾸는 함수는 참조 매개변수를 사용하며 이름은 swap_ptre으로 작성한다.

	@ 2017.02.14
*/

#if 0
#include <iostream>

using namespace std;

void swap_ptr(char* &, char* &);

int main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;
}

void swap_ptr(char *(&ap), char *(&bp))
{
	char *swap;

	swap = ap;
	ap = bp;
	bp = swap;
}
#endif
/*
	!! �����ͺ����� �����ϰ� �ִ� �� ���� ���ڿ��� ����ϰ� �����ͺ����� ���� ���� �ٲ� �Ŀ� �ٽ� �ѹ� �� ���ڿ��� ����Ѵ�.
	�����ͺ����� ���� �ٲٴ� �Լ��� ���� �Ű������� ����ϸ� �̸��� swap_ptre���� �ۼ��Ѵ�.

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

	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
}

void swap_ptr(char *(&ap), char *(&bp))
{
	char *swap;

	swap = ap;
	ap = bp;
	bp = swap;
}
#endif
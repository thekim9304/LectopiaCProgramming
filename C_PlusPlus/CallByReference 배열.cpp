#include <iostream>

using namespace std;

void prn(char(&chr)[10]);
void prn(int(&aaa)[3][4]);

int main()
{
	char str[10] = "Star";
	int ary[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	prn(str);
	prn(ary);

	cout << "Afret : " << ary[2][3] << endl;
}

void prn(char(&chr)[10])
{
	cout << chr << endl;
	cout << sizeof(chr) << endl;
	strcpy(chr, "Dream");
}

void prn(int(&aaa)[3][4])
{
	cout << aaa[2][3] << endl;
	cout << sizeof(aaa) << endl;
	aaa[2][3] = 20;
}
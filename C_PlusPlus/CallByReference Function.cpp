#include <iostream>

using namespace std;

int &counter();
int cnt = 0;

int main()
{
	int res;

	res = counter();
	cout << res << endl;
	counter() = 10;
	cout << cnt << endl;
	counter()++;
	cout << cnt << endl;
	cout << counter() + 5 << endl;
}

int &counter()
{
	cnt++;
	return cnt;
}
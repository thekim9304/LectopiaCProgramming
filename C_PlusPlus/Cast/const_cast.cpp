#if 0
#include<iostream>
using namespace std;

class A
{
  private:
	int num;
  public:
	A(int n) { num = n; }
	void show();             
 };
void A::show()
{
	cout << "num = " << num << endl;
}

void sub(const A &r);
int main()
{
	 A ob(10);
	 sub(ob);

	return 0;
}
void sub(const A &r)
{
	const_cast<A &>(r).show();
}
#endif
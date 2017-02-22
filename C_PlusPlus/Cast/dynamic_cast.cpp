#if 01
#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

class A{  // �⺻ Ŭ����
	int va;
public:
	A(int n = 0) : va(n) { }
	virtual void view() { cout << "A class view..." <<va<< endl; }
};
class B : public A{  // �Ļ� Ŭ����
	int vb;
public:
	B(int n = 0) : vb(n) {  }
	void view()  // view�Լ��� ������
	{ cout << "B class view..." << vb << endl; }
	virtual void prn()
	{ cout << "B class prn()... " << vb << endl; }
};

class C : public B{  // �Ļ� Ŭ����
	int vc;
public :
	C(int n = 0) : vc(n) {  }
	void view()  // view�Լ��� ������
	{ cout << "C class view..." << vc << endl; }
	void prn()  // prn�Լ��� ������
	{ cout << "C class prn() : vc = " << vc << endl; }
};

A *GetObject();

int main()
{
	srand(time(0));
	A *ap;
	B *bp;
	C *cp;
	int i;

	for(i=0; i<10; i++)
	{
		ap = GetObject();

		if ((cp = dynamic_cast<C*>(ap)) != NULL)
			cout << "C ��ü ����..." << endl;
		else if ((bp = dynamic_cast<B *>(ap)) != NULL)
			cout << "B ��ü ����..." << endl;
		else
			cout << "A ��ü ����..." << endl;
		//ap->view();
		/*
		if((bp = dynamic_cast<B *>(ap)) != NULL )
		{
			bp->prn();
		}*/
        delete ap;
	}
	cin.get();
	return 0;
}

A * GetObject()
{
	A *p;

	switch(rand()%3)
	{
	case 0 : p = new A(10); break;
	case 1 : p = new B(20); break;
	case 2 : p = new C(30); break;
	}
	return p;
}
#endif

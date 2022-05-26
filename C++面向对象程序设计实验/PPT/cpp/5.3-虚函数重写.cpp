#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable : 4996)
class A
{
	int a;
public:
	A(int num = 0)
	{
		a = num;
	}
	virtual void operator +(int x)  //Ðéº¯Êý
	{
		a += x;
	}
	virtual void show()             //Ðéº¯Êý
	{
		cout << "a=" << a << endl;
	}
};

class B :public A
{
	int b;
public:
	B(int x = 0, int y = 0):A(x)
	{
		b = y;
	}
	void operator +(int x)
	{
		b += x;
	}
	void show()
	{
		A::show();
		cout << "b=" << b << endl;
	}
};

void add(A& a, int x)
{
	a + x;
}

int main() 
{
	A myA, * p;
	B myB(2, 3);
	add(myA, 3); p = &myA; p->show();
	add(myB, 3); p = &myB; p->show();
	return 0;
}
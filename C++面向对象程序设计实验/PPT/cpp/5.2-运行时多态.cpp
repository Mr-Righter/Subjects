#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;
class A
{
private:
	char* name;
public:
	A() {};  //这里要构造一个默认的A的构造函数，因为后面需要构造一个A的数组
	A(const char* str)
	{
		name = new char[strlen(str) + 1]{ '\0' };
		strcpy(name, str);
	}
	void show()
	{
		cout << name << endl;
	}
	virtual void print() = 0;  //这里将print函数定义为纯虚函数，使得派生类重写的print函数能被调用
	virtual ~A()   //基类析构函数定义为虚函数，防止运行时多态发生内存泄漏
	{
		delete[]name;
		cout << "destructor A" << endl;
	}
};

class B :public A
{
private:
	int age;
public:
	B(const char* str,int a) :A(str) //参数传递
	{
		age = a;
	};
	void print()
	{
		cout << "B:";
		A::show();    //这里调用A的show函数
		cout << age << endl;
	}
};

class C:public A
{
private:
	char sex;
public:
	C(const char* str,char s) :A(str) 
	{
		sex = s;
	};
	void print()
	{
		cout << "C:";
		A::show();
		cout << sex << endl;
	}
};

class manager
{
	A** array;   //数组A用于存放A*类型的数据成员，这样才能用基类指针指向派生类对象
	int len;
public:
	manager(int n)
	{
		array = new A * [n] {NULL};  //开始时初始化为NULL
		len = 0;
	}
	void add(int i, const char* str, int age)
	{
		array[i] = new B(str, age);   //动态创建类对象并初始化的方法（有参数）；若无参数则还需要写一个B的默认构造函数
		len++;
	}
	void add(int i, const char* str, char s) //对add函数重载
	{
		array[i] = new C(str, s);
		len++;
	}
	~manager()
	{
		for (int i = 0; i <= len;)
		{
			if (array[i] != NULL)
			{
				delete array[i];  //析构A*指向的派生类B或C对象，因此A的析构函数需要定义成虚函数
				i++;
			}
			else
				i++;
		}
		delete[]array;
	}
	void display()
	{
		for (int i = 0; i <= len;)
		{
			if (array[i] != NULL)
			{
				array[i]->print();  //多态
				i++;
			}
			else
				i++;
		}
	}
};

int main() 
{
	manager m(4);
	m.add(0, "zhang", 18);
	m.add(1, "wang", 'F');
	m.add(3, "liu", 'M');
	m.display();
	return 0;
}
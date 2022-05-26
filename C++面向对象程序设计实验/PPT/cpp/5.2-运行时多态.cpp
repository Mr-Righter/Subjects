#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;
class A
{
private:
	char* name;
public:
	A() {};  //����Ҫ����һ��Ĭ�ϵ�A�Ĺ��캯������Ϊ������Ҫ����һ��A������
	A(const char* str)
	{
		name = new char[strlen(str) + 1]{ '\0' };
		strcpy(name, str);
	}
	void show()
	{
		cout << name << endl;
	}
	virtual void print() = 0;  //���ｫprint��������Ϊ���麯����ʹ����������д��print�����ܱ�����
	virtual ~A()   //����������������Ϊ�麯������ֹ����ʱ��̬�����ڴ�й©
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
	B(const char* str,int a) :A(str) //��������
	{
		age = a;
	};
	void print()
	{
		cout << "B:";
		A::show();    //�������A��show����
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
	A** array;   //����A���ڴ��A*���͵����ݳ�Ա�����������û���ָ��ָ�����������
	int len;
public:
	manager(int n)
	{
		array = new A * [n] {NULL};  //��ʼʱ��ʼ��ΪNULL
		len = 0;
	}
	void add(int i, const char* str, int age)
	{
		array[i] = new B(str, age);   //��̬��������󲢳�ʼ���ķ������в����������޲�������Ҫдһ��B��Ĭ�Ϲ��캯��
		len++;
	}
	void add(int i, const char* str, char s) //��add��������
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
				delete array[i];  //����A*ָ���������B��C�������A������������Ҫ������麯��
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
				array[i]->print();  //��̬
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
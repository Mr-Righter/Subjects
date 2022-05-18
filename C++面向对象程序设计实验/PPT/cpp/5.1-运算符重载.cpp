#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;
class String
{
	char* array;
public:
	String(const char* s)
	{
		array = new char[strlen(s) + 1]{'\0'};
		strcpy(array, s);
	}
	~String()
	{
		if (array)
		{
			delete[]array;
		}	
	}
	String(const String& a)    //����һ��Ҫ�Լ����忽�����캯��
	{
		array = new char[strlen(a.array) + 1]{ '\0' };
		strcpy(array, a.array);
	}
	char &operator[] (int i)  //[]���������
	{
		if (i >= strlen(array))
		{
			cout << "Index out of range." << endl;  
			return array[strlen(array) - 1];  //Ϊ��֤�����������'\0'ǰһ���ַ��滻
		}
		else
			return array[i];
	}
	String &operator+(String& x)   //��������
	{
		char* temp = array;
		array = new char[strlen(temp) + strlen(x.array) + 1]{ '\0' };
		strcpy(array, temp);
		strcat(array, x.array);
		delete[]temp;
		return *this;
	}

	operator int()   //����ת��
	{
		return strlen(array);
	}
	
	String operator+ (const char* p)   //���ض���
	{
		String temp(array);
		String A(p);
		return temp + A;    //������temp+Aʱ����ʱ����ÿ������캯������ǳ�����Ӷ�����һ������������Ҫ�������������ᱨ��
	}
	friend ostream& operator<<(ostream& output, const String& x);   // <<��������ֻ�ܶ������Ԫ
};

ostream& operator << (ostream& output,const String &x)  //��<<���صķ�ʽ
{
	output << x.array;
	return output;
}

int main() 
{
	String string1("mystring"), string2("yourstring"), string3("herstring");
	cout<< string1 <<endl;
	string1[7] = 'n';
	cout<<string1<<endl;
	string1[8] = 'n';
	cout<<string1 + string2 + string3<<endl;
	cout<<string1<<endl;
	cout<<string2 + "ab" << endl;
	cout<<string2<<endl;
	cout<<string3+3<<endl;
	cout << string3 << endl;
	return 0;
}

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
	String(const String& a)    //这里一定要自己定义拷贝构造函数
	{
		array = new char[strlen(a.array) + 1]{ '\0' };
		strcpy(array, a.array);
	}
	char &operator[] (int i)  //[]运算符重载
	{
		if (i >= strlen(array))
		{
			cout << "Index out of range." << endl;  
			return array[strlen(array) - 1];  //为保证正常输出，将'\0'前一个字符替换
		}
		else
			return array[i];
	}
	String &operator+(String& x)   //返回引用
	{
		char* temp = array;
		array = new char[strlen(temp) + strlen(x.array) + 1]{ '\0' };
		strcpy(array, temp);
		strcat(array, x.array);
		delete[]temp;
		return *this;
	}

	operator int()   //类型转换
	{
		return strlen(array);
	}
	
	String operator+ (const char* p)   //返回对象
	{
		String temp(array);
		String A(p);
		return temp + A;    //当返回temp+A时，此时会调用拷贝构造函数进行浅拷贝从而创建一个匿名对象，需要进行深拷贝，否则会报错
	}
	friend ostream& operator<<(ostream& output, const String& x);   // <<函数重载只能定义成友元
};

ostream& operator << (ostream& output,const String &x)  //对<<重载的方式
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

#include <iostream>
#include <cstring>
#include <iomanip>  
#pragma warning(disable : 4996)
using namespace std;
class student
{
private:
	static int age;  //假设均为同龄学生
	char* name;      //姓名
	int scores;      //分数
	double gpa;      //总绩点
public:
	static void setAge(int num);   //静态成员函数
	student(const char* str, int s, double g); //含参构造函数
	~student();      //析构函数
	void print();    //输出类内数据成员的信息以及地址
};
int student::age = 0;   //初始化age
void student::setAge(int num)    //静态成员函数
{
	age = num;
}
student::student(const char* str, int s, double g) //含参构造函数
{
	name = new char[strlen(str) + 1]{ '\0' };
	strcpy(name, str);
	scores = s;
	gpa = g;
}
student::~student()
{
	if (name)
		delete[]name;
}
void student::print() 
{
	cout << "Info:" << endl;									 //输出对象的值
	cout << "age:" << age << setw(15) << "name[]:" << name << setw(15) << "name:" << (void*)name << setw(15) <<
		setw(15) << "scores:" << scores << setw(15) << "gpa:" << gpa << endl;
	cout << "Adress:" << endl;									//输出数据成员的地址（&name指name指针的地址,并非name的地址）
	cout << "&age:" << &age << setw(15) << "&name:" << &name << setw(15) << "&scores:" << &scores <<
		setw(15) << "&gpa:" << &gpa << endl;
	cout << "&student:" << this << setw(23) << "sizeof（student）:" << sizeof(*this) << endl;										//输出占用的字节
}


void Line()
{
	for (int n = 1; n <= 100; n++)
	{
		cout << "-";
	}
}
student stu_global[2]{ student("xxx",94,4.3),student("yyyyy",90,4.0)};  //定义全局对象stu_global
void func()																
{
	student stu_local[2]{ student("xxx",94,4.3),student("yyyy",90,4.0) };   //func中定义局部对象stu_loacal
	for (int i = 0; i < 2; i++)
	{
		Line();
		cout << endl;
		cout << "stu_local[" << i << "]  ";
		stu_local[i].print();
	}
}
void text(){}

int main()
{
	student::setAge(18);                                 //调用静态函数setAge
	student* stu_main = new student[2]{ student("xxx",94,4.3),student("yyyy",90,4.0) };  //main中定义局部对象stu_main
	for (int i = 0; i < 2; i++)                          //输出stu_global成员信息
	{
		Line();
		cout << "\nstu_global[" << i << "]  ";
		stu_global[i].print();
	}
	func();                                             //输出stu_local成员信息
	for (int i = 0; i < 2; i++)                         //输出stu_local成员信息
	{
		Line();
		cout << "\nstu_main[" << i << "]  ";
		stu_main[i].print();
	}
	Line();
	cout << "\n&func: " << (void*)func << endl;            //输出外部函数func的地址
	cout << "&main: " << (void*)main << endl;              //输出main函数的地址
	cout << "&text: " << (void*)text << endl;              //输出main函数的地址
	printf("&student::setAge(): %p\n", &student::setAge);  //输出静态成员函数setAge的地址
	printf("&student::print(): %p\n", &student::print);    //输出非静态成员函数print的地址
	delete[]stu_main;
	return 0;
}

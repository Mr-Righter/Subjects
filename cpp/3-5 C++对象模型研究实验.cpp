#include <iostream>
#include <cstring>
#include <iomanip>  
#pragma warning(disable : 4996)
using namespace std;
class student
{
private:
	static int age;  //�����Ϊͬ��ѧ��
	char* name;      //����
	int scores;      //����
	double gpa;      //�ܼ���
public:
	static void setAge(int num);   //��̬��Ա����
	student(const char* str, int s, double g); //���ι��캯��
	~student();      //��������
	void print();    //����������ݳ�Ա����Ϣ�Լ���ַ
};
int student::age = 0;   //��ʼ��age
void student::setAge(int num)    //��̬��Ա����
{
	age = num;
}
student::student(const char* str, int s, double g) //���ι��캯��
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
	cout << "Info:" << endl;									 //��������ֵ
	cout << "age:" << age << setw(15) << "name[]:" << name << setw(15) << "name:" << (void*)name << setw(15) <<
		setw(15) << "scores:" << scores << setw(15) << "gpa:" << gpa << endl;
	cout << "Adress:" << endl;									//������ݳ�Ա�ĵ�ַ��&nameָnameָ��ĵ�ַ,����name�ĵ�ַ��
	cout << "&age:" << &age << setw(15) << "&name:" << &name << setw(15) << "&scores:" << &scores <<
		setw(15) << "&gpa:" << &gpa << endl;
	cout << "&student:" << this << setw(23) << "sizeof��student��:" << sizeof(*this) << endl;										//���ռ�õ��ֽ�
}


void Line()
{
	for (int n = 1; n <= 100; n++)
	{
		cout << "-";
	}
}
student stu_global[2]{ student("xxx",94,4.3),student("yyyyy",90,4.0)};  //����ȫ�ֶ���stu_global
void func()																
{
	student stu_local[2]{ student("xxx",94,4.3),student("yyyy",90,4.0) };   //func�ж���ֲ�����stu_loacal
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
	student::setAge(18);                                 //���þ�̬����setAge
	student* stu_main = new student[2]{ student("xxx",94,4.3),student("yyyy",90,4.0) };  //main�ж���ֲ�����stu_main
	for (int i = 0; i < 2; i++)                          //���stu_global��Ա��Ϣ
	{
		Line();
		cout << "\nstu_global[" << i << "]  ";
		stu_global[i].print();
	}
	func();                                             //���stu_local��Ա��Ϣ
	for (int i = 0; i < 2; i++)                         //���stu_local��Ա��Ϣ
	{
		Line();
		cout << "\nstu_main[" << i << "]  ";
		stu_main[i].print();
	}
	Line();
	cout << "\n&func: " << (void*)func << endl;            //����ⲿ����func�ĵ�ַ
	cout << "&main: " << (void*)main << endl;              //���main�����ĵ�ַ
	cout << "&text: " << (void*)text << endl;              //���main�����ĵ�ַ
	printf("&student::setAge(): %p\n", &student::setAge);  //�����̬��Ա����setAge�ĵ�ַ
	printf("&student::print(): %p\n", &student::print);    //����Ǿ�̬��Ա����print�ĵ�ַ
	delete[]stu_main;
	return 0;
}

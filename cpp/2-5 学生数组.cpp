//#include <iostream>
//#include <cstring>
//#pragma warning(disable : 4996)
//using namespace std;
//class student
//{
//private:
//	char* name;
//	float g1, g2;
//public:
//	student(const char* str, int x, int y)           
//	{
//		name = new char[strlen(str) + 1]{ '\0' };    //��ȫ������ѧ�������ֿ���һ�ݷ��ڶ������ڴ���,+1Ϊ�˴��'\0'
//		strcpy(name, str);
//		cout << "construct" << " " << name << endl;
//		g1 = x;
//		g2 = y;
//	}
//	~student()
//	{
//		cout << "destruct" << " " << name << endl;
//		delete[]name;
//	}
//	student(const student& a)    
//	{
//		name = new char[strlen(a.name) + 2]{'\0'};       //�����ڴ��ͬʱ���ַ������ʼ��Ϊ'\0',������ܻᵼ��Խ��
//		strcpy(name, a.name);
//		strcat(name, "u");
//		g1 = a.g1 - 10.0;
//		g2 = a.g2 - 10.0;
//		cout << "copy" << " " << name << endl;
//	}
//	int getG1() { return g1; }
//	int getG2() { return g2; }
//	student* getAdress() { return this; }     //���������ĵ�ַ������������ student *
//};
//
//int main()
//{
//	student a("li", 90.0, 80.0);
//	{
//		student st[2] = { student("zhang",80.0,70.0),student("wang",90.0,80.0) };   //����student�ֲ�����
//		for (int i = 0; i < 2; i++)
//		{
//			cout << (st[i].getG1() + st[i].getG2()) / 2 << " ";
//		}
//		cout << endl;
//	}
//	student b(a);
//	cout << &b - b.getAdress() << endl;
//	return 0;
//}
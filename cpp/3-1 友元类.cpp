//#include<iostream>
//#include<cstring>
//using namespace std;
//class teacher;
//class student
//{
//	friend class teacher;        //注意这里定义友元要加class
//private:
//	int usual;
//	int final;
//	static float prop;
//public:
//	static void setProp(float x) { prop = x; }
//	void compScore()
//	{
//		cout << (float(usual) * prop + float(final) * (1.0 - prop)) << " ";
//	}
//};
//float student::prop = 0;  //不用加static,且要用student::修饰
//
//class teacher
//{
//private:
//	student* stu;
//public:
//	teacher(int n)
//	{
//		if (n >= 0)
//			stu = new student[n];
//		else
//			stu = NULL;
//	}
//	~teacher()
//	{
//		if(stu)
//			delete[]stu;
//	}
//	void assign(int n)
//	{
//		if (n >= 0)
//			cin >> stu[n].usual >> stu[n].final;
//	}
//	void show(int n)
//	{
//		if (n >= 0)
//			stu[n].compScore();
//	}
//};
//
//
//
//int main()
//{
//	float p;
//	int nums;
//	cin >> p >> nums;
//	student::setProp(p);
//	teacher tech(nums);
//	for (int i = 0; i < nums; i++)
//	{
//		tech.assign(i);
//	}
//	for (int i = 0; i < nums; i++)
//	{
//		tech.show(i);
//	}
//	return 0;
//}
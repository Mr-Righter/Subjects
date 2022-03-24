//#include <iostream>
//using namespace std;
//int main()
//{
//	int x;
//	cin >> x;
//	int** num = new int*[x];           //创建一个动态指针数组
//	for (int i = 0; i < x; i++)
//	{
//		num[i] = new int;              //动态创建int类型的变量
//		cin >> *num[i];
//	}
//	int sum = 0;
//	for (int i = 0; i < x; i++)
//	{
//		sum = sum + *num[i];
//		delete num[i];                 
//	}
//	cout << sum;
//	delete[]num;
//	return 0;
//}
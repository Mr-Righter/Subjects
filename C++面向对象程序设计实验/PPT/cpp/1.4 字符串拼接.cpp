#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[20];
	int x = 1;                                             //x=1是为了让字符数组以'\0'结束
	char* new_str = NULL, * old_str = NULL;                //置为NULL，防止出现野指针
	while (cin >> str)                                     //合并字符串，需要重新开辟一块内存，将原字符串和新的字符串存入内存中，再将存储原字符串的内存释放掉
	{
		x = x + strlen(str);
		old_str = new_str;
		new_str = new char[x];
		memset(new_str, 0, sizeof(new_str));               //对new_str进行初始化
		if (old_str!=NULL)                                 //old_str判断是否为空，防止出现野指针
			strcat(new_str, old_str);
		strcat(new_str, str);
		if (old_str!=NULL)                                 //old_str判断是否为空，防止内存溢出
		{
			delete old_str;
			old_str = NULL;
		}
	}
	cout << new_str;
	delete new_str;
	return 0;
}



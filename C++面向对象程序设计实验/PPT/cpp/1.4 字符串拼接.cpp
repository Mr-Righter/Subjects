#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[20];
	int x = 1;                                             //x=1��Ϊ�����ַ�������'\0'����
	char* new_str = NULL, * old_str = NULL;                //��ΪNULL����ֹ����Ұָ��
	while (cin >> str)                                     //�ϲ��ַ�������Ҫ���¿���һ���ڴ棬��ԭ�ַ������µ��ַ��������ڴ��У��ٽ��洢ԭ�ַ������ڴ��ͷŵ�
	{
		x = x + strlen(str);
		old_str = new_str;
		new_str = new char[x];
		memset(new_str, 0, sizeof(new_str));               //��new_str���г�ʼ��
		if (old_str!=NULL)                                 //old_str�ж��Ƿ�Ϊ�գ���ֹ����Ұָ��
			strcat(new_str, old_str);
		strcat(new_str, str);
		if (old_str!=NULL)                                 //old_str�ж��Ƿ�Ϊ�գ���ֹ�ڴ����
		{
			delete old_str;
			old_str = NULL;
		}
	}
	cout << new_str;
	delete new_str;
	return 0;
}



#include <iostream>
using namespace std;
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
 	y = temp;
}
void sort(int& x, int& y, int& z)  //»ùÓÚÃ°ÅÝÅÅÐò
{
	int temp;
	if (x > y)
		swap(x, y);
	if (y > z)
		swap(y, z);
	if (x > y)
		swap(x, y);
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	sort(a, b, c);
	cout << a <<" " << b <<" " << c;
	return 0;
}

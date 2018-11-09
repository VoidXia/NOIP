#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
	double f = 3.1415926535;
	cout << "Enter the huashi temperature:" << endl;
	//-----------------方法一-------------------
	/*	cout.precision(3);		//调用cout的precision()函数设置或返回当前要被显示的浮点变量的位数（即浮点数的数字个数）
	cout << fixed;		//fixed输出小数点后面三位有效数字
	cout << "The Celsius temperature is: ";
	cout << f << endl;		//输出小数点前后共三位有效数字
	cout << f << endl;
	*/
	//----------------方法二--------------------
	//使用setprecision()操作符，包含在在iomanip头文件中
	cout << f << endl;				//默认输出六位
	cout << setprecision(3);		//单用setprecision是设置显示的有效数字位数。
	cout << setprecision(0) << f << endl;
	cout << setprecision(1) << f << endl;
	cout << setprecision(2) << f << endl;
	cout << setprecision(3) << f << endl;
	cout << setprecision(4) << f << endl;
	cout << "---------------------------------" << endl;
	cout <<setiosflags(ios::fixed);	//配合setprecision就是设置小数精度(小数点后的有效位数)
	//cout << fixed;				//作为cout的一个参数是setiosflags(ios::fixed)的简写形式，等效于上一行
	cout << setprecision(0) << f << endl;
	cout << setprecision(1) << f << endl;
	cout << setprecision(2) << f << endl;
	cout << setprecision(3) << f << endl;
	cout << setprecision(4) << f << endl;
}
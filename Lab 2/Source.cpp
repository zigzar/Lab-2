/*#include <iostream>
#include <string>
using namespace std;

double inputCheck(char inp[256])
{
	short g;
	bool isZero = true;
	for (int g = 0; inp[g] != '\0'; g++)
		if (inp[g] < 48 || inp[g]>57)
		{
			std::cout << "Ошибка ввода числа. Пожалуйста введите число, используя арабские цифры";
			return false;
		}
	return strtod(inp, endptr);
}


bool err = 0;

double input(double a)
{
	return a;
}

string input(string a)
{
	err = 1;
	return 0;
}

int main()
{
	cin >> input(&a);
		cout << err;

}*/
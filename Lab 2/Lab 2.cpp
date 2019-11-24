//Используя данную программу, вы соглашаетесь выполнять следующее правило:
//Выполнять ввод только натуральных чисел арабскими цифрами в естественном виде. Например: 1.

#include <iostream>
#include <ctime>
#include <chrono>
#include "functions.h"

using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int N = 20; // Quantity of array elements
	int a[N]; // Array of elements
	int q[100] = { 0 }; //Array of elements quantity

	fillRandom(*a, *q, N);

	coutArr(a, N);

	sort(*a, N);

	cout << "\nМинимальный элемент: " << a[0] << 
	"\nМаксимальный элемент: " << a[N - 1] <<
	"\nКоличество элементов равных среднему между минимальным и максимальным значениями: " << q[(a[0] + a[N - 1]) / 2];

	smaller(*q);

	bigger(*q);

	delElement(*a, N);

	insElement(*a, N);

	search(*a, N);

	makeSym(*a, N);

}
﻿#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

const int N = 1000; // Quantity of array elements
int a[N]; // Array of elements
int q[100] = { 0 }; // Array of elements quantity

void qsort(int b, int e) // Source https://habr.com/ru/sandbox/29775/
{
	int l = b, r = e;
	int piv = a[(l + r) / 2];
	while (l <= r)
	{
		while (a[l] < piv)
			l++;
		while (a[r] > piv)
			r--;
		if (l <= r)
			swap(a[(l++)], a[(r--)]);
	}
	if (b < r)
		qsort(b, r);
	if (e > l)
		qsort(l, e);
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		q[a[i]]++;
		cout << a[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		cout << i << " ";
	}
	cout << "\n\n";

	auto timerStart = chrono::high_resolution_clock::now();
	qsort(0, N - 1);
	auto timerEnd = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
			cout << a[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < N; i++)
	{
			cout << i << " ";
	}
	chrono::duration<double, milli>;
	double timerDur = (timerEnd - timerStart).count();
	cout.setf(ios::fixed);
	cout << "\nВремя работы быстрой сортировки: " << timerDur / 1000000 << " сек";

	cout << "\nМинимальный элемент: " << a[0] << "\nМаксимальный элемент: " << a[N - 1] << "\nКоличество элементов равных среднему между минимальным и максимальным значениями: " << q[(a[0] + a[N - 1]) / 2]
		<< "\n\nВведите число, а я скажу, сколько чисел в массиве меньше вашего: ";
	int smaller;
	cin >> smaller;
	int sumSmaller = 0;
	auto smTimerStart = chrono::high_resolution_clock::now();
	for (int i = 0; i < smaller; i++)
	{
		sumSmaller = sumSmaller + q[i];
	}
	auto smTimerEnd = chrono::high_resolution_clock::now();
	cout << sumSmaller << " чисел меньше вашего\n";
	double smTimerDur = (smTimerEnd - smTimerStart).count();
	cout << "Время подсчёта: " << smTimerDur / 1000000 << " сек\n\n";

	cout << "Введите число, а я скажу, сколько чисел в массиве больше вашего: ";
	int bigger;
	cin >> bigger;
	int sumBigger = 0;
	auto bgTimerStart = chrono::high_resolution_clock::now();
	for (int i = 99; i > bigger; i--)
	{
		sumBigger = sumBigger + q[i];
	}
	auto bgTimerEnd = chrono::high_resolution_clock::now();
	double bgTimerDur = (bgTimerEnd - bgTimerStart).count();
	cout << sumBigger << " чисел больше вашего\n";
	cout << "Время подсчёта: " << bgTimerDur / 1000000 << " сек\n\n";

	cout << "Введите номер элемента для его удаления: ";
	int elementNumToDelete;
	cin >> elementNumToDelete;
	auto delTimerStart = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (i == elementNumToDelete) i++;
		cout << a[i] << " ";
	}
	auto delTimerEnd = chrono::high_resolution_clock::now();
	double delTimerDur = (delTimerEnd - delTimerStart).count();

	cout << "\nВремя удаления элемента: " << delTimerDur / 1000000 << " сек";

	cout << "\nВозвращаю массив к исходному состоянию:\n";
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}

	cout << "\n\nВведите номер элемента для вставки: ";
	int elementNumToInsert;
	cin >> elementNumToInsert;
	cout << "Введите значение элемента для вставки: ";
	int elementToInsert;
	cin >> elementToInsert;
	auto insTimerStart = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (i == elementNumToInsert) cout << elementToInsert << " ";
		cout << a[i] << " ";
	}
	auto insTimerEnd = chrono::high_resolution_clock::now();
	double insTimerDur = (insTimerEnd - insTimerStart).count();

	cout << "\nВремя вставки элемента: " << insTimerDur / 1000000 << " сек";

	cout << "\nВозвращаю массив к исходному состоянию:\n";
	for (int i = 0; i < N; i++)
		{
			cout << a[i] << " ";
		}



	cout << "\n\n_Создание симметричного массива_";
	int ind, val;
	cout << "\nВведите номер элемента, который будем изменять: ";
	cin >> ind;
	cout << "\nВведите значение для замены: ";
	cin >> val;
	cout << "\nУкажите номер центрального элемента: ";
	int center;
	cin >> center;
	cout << "\nСоздаю симметричный массив...\n";

	/*for (int i = 0; i < N / 2; i++)
	{
		a[N - 1 - i] = a[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		cout << i << "\t";
	}*/
	auto symmTimerStart = chrono::high_resolution_clock::now();
	a[ind] = val;
	for (int j = 0 ;;)
	{
		if (j == N - 1) break;
		for (int i = 0; i <= center; i++, j++)
		{
			if (j == N - 1) break;
			cout << a[i] << " ";
		}
		if (j == N - 1) break;
		for (int i = center - 1; i >= 0; i--, j++)
		{
			if (j == N - 1) break;
			cout << a[i] << " ";
		}
	}
	auto symmTimerEnd = chrono::high_resolution_clock::now();
	double symmTimerDur = (symmTimerEnd - symmTimerStart).count();
	cout << "\nВремя создания: " << symmTimerDur / 1000000 << " сек\n\n";
	


	/*int ind, num, dif;
	cin >> ind;
	cout << "\nНа что меняем?\nНа ";
	cin >> num;
		a[ind] = num;
		if (N % 2 == 1)
		{
			dif = (N-1) / 2 - ind;
			a[(N-1)/2 + dif] = num;
		}
		else 
		{
			dif = N / 2 - ind;
			a[(N-1) / 2 + dif] = num;
		}

	cout << "\nЭлементы массива:\t";
	for (int i = 0; i < N; i++)
	{
			cout << a[i] << "\t";
	}
	cout << "\nНомера массива:  \t";
	for (int i = 0; i < N; i++)
	{
		cout << i << "\t";
	}*/
}
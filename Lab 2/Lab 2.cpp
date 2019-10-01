﻿#include <iostream>
#include <ctime>

using namespace std;

const int N = 20; // Quantity of array elements
int a[N]; // Array of elements
int q[100] = { 0 }; // Array of elements quantity

void qsort(int b, int e) // Код взял с Хабра https://habr.com/ru/sandbox/29775/
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
	qsort(0, N-1);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
}
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

const int N = 20; // Quantity of array elements
int a[N]; // Array of elements
int q[100] = { 0 }; // Array of elements quantity

void qsort(int start, int end) // Source https://habr.com/ru/sandbox/29775/
{
	int left = start, right = end;
	int piv = a[(left + right) / 2];
	while (left <= right)
	{
		while (a[left] < piv)
			left++;
		while (a[right] > piv)
			right--;
		if (left <= right)
			swap(a[(left++)], a[(right--)]);
	}
	if (start < right)
		qsort(start, right);
	if (end > left)
		qsort(left, end);
}

int binSearch(int* A, int start, int end, int number) {
	if (end >= start) {
		int mid = start + (end - start) / 2;
		if (A[mid] == number)
			return mid;
		if (A[mid] > number)
			return binSearch(A, start, mid - 1, number);
		if (A[mid] < number)
			return binSearch(A, mid + 1, end, number);
	}
	return -1;
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
	chrono::duration<double, nano>;
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

	int elementNumToDelete;
	do {
	cout << "Введите номер элемента для его удаления: ";
	cin >> elementNumToDelete;
		if (elementNumToDelete >= 0 && elementNumToDelete < N) {
			auto delTimerStart = chrono::high_resolution_clock::now();
			for (int i = 0; i < N; i++)
			{
				if (i == elementNumToDelete && elementNumToDelete == N - 1) {
					break;
				}
				else if (i == elementNumToDelete) {
					i++;
					cout << a[i] << " ";
				} else cout << a[i] << " ";
			}
			auto delTimerEnd = chrono::high_resolution_clock::now();
			double delTimerDur = (delTimerEnd - delTimerStart).count();
			cout << "\nВремя удаления элемента: " << delTimerDur / 1000000 << " сек";
			break;
		}
		else {
			cout << "Число выходит за диапазон массива. Пожалуйста, укажите число в промежутке от 0 до " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);


	cout << "\nВозвращаю массив к исходному состоянию:\n";
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}

	int elementNumToInsert;
	do {
			cout << "\n\nВведите номер элемента для вставки: ";
			cin >> elementNumToInsert;		
			if (elementNumToInsert >= 0 && elementNumToInsert < N) {
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
				break;
			}
			else {
				cout << "Число выходит за диапазон массива. Пожалуйста, укажите число в промежутке от 0 до " << N - 1 << "\n";
				cin.clear();
			}
	} while (true);

	cout << "\nВозвращаю массив к исходному состоянию:\n";
	for (int i = 0; i < N; i++)
		{
			cout << a[i] << " ";
		}


	int numToSearch;
	cout << "\n\nВведите значение для поиска: ";
	cin >> numToSearch;
	auto searchTimerStart = chrono::high_resolution_clock::now();
	int searchRes = binSearch(a, 0, N - 1, numToSearch);
	auto searchTimerEnd = chrono::high_resolution_clock::now();
	if (searchRes == -1) cout << "Такого числа не нашлось =(";
	else cout << "Такое число нашлось! Его номер в массиве: " << searchRes;
	double searchTimerDur = (searchTimerEnd - searchTimerStart).count();
	cout << "\nВремя поиска элемента: " << searchTimerDur / 1000000 << " сек";


	cout << "\n\n_Создание симметричного массива_";
	int ind, val;
	do {
		cout << "\nВведите номер элемента, который будем изменять: ";
		cin >> ind;
		if (ind >= 0 && ind < N) break;
		else {
			cout << "Число выходит за диапазон массива. Пожалуйста, укажите число в промежутке от 0 до " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);
	cout << "\nВведите значение для замены: ";
	cin >> val;
	int center;
	do {
		cout << "\nУкажите номер центрального элемента: ";
		cin >> center;
		if (center >= 0 && center < N) break;
		else {
			cout << "Число выходит за диапазон массива. Пожалуйста, укажите число в промежутке от 0 до " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);

	cout << "\nСоздаю симметричный массив...\n";

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
		for (int i = center - 1; i > 0; i--, j++)
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
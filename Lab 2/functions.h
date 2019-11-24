#include <iostream>
using namespace std;

int inputCheck() {
	while (true) {
		int input;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << endl << "������ �����. ����������, ���������� ������ ����� �� ������� �����: ";
		}
		else {
			cin.ignore(cin.rdbuf()->in_avail());
			return input;
		}
	}
}

void coutArr(int* a, int N) {
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void fillRandom(int& alink, int& qlink, int N) {
	int* a = &alink;
	int* q = &qlink;
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		q[a[i]]++;
	}
}

void qsort(int& link, int start, int end)
{
	int* a = &link;
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
		qsort(*a, start, right);
	if (end > left)
		qsort(*a, left, end);
}

void sort(int& alink, int N) {
	int* a = &alink;
	auto timerStart = chrono::high_resolution_clock::now();
	qsort(*a, 0, N - 1);
	auto timerEnd = chrono::high_resolution_clock::now();
	coutArr(a, N);
	chrono::duration<double, nano>;
	double timerDur = (timerEnd - timerStart).count();
	cout.setf(ios::fixed);
	cout << "\n����� ������ ������� ����������: " << timerDur / 1000000 << " ���";
}

void getSmaller(int& qlink) {
	cout << "\n\n������� �����, � � �����, ������� ����� � ������� ������ ������: ";
	int* q = &qlink;
	int smaller = inputCheck();
	int sumSmaller = 0;
	for (int i = 0; i < smaller; i++)
	{
		sumSmaller = sumSmaller + q[i];
	}
	cout << sumSmaller << " ����� ������ ������\n";
}

void smaller(int& qlink) {
	int* q = &qlink;
	auto smTimerStart = chrono::high_resolution_clock::now();
	getSmaller(*q);
	auto smTimerEnd = chrono::high_resolution_clock::now();
	double smTimerDur = (smTimerEnd - smTimerStart).count();
	cout << "����� ��������: " << smTimerDur / 10000000000 << " ���\n\n";
}

void getBigger(int& qlink) {
	cout << "������� �����, � � �����, ������� ����� � ������� ������ ������: ";
	int* q = &qlink;
	int bigger = inputCheck();
	int sumBigger = 0;
	for (int i = 99; i > bigger; i--)
	{
		sumBigger = sumBigger + q[i];
	}
	cout << sumBigger << " ����� ������ ������\n";
}

void bigger(int& qlink) {
	int* q = &qlink;
	auto bgTimerStart = chrono::high_resolution_clock::now();
	getBigger(*q);
	auto bgTimerEnd = chrono::high_resolution_clock::now();
	double bgTimerDur = (bgTimerEnd - bgTimerStart).count();
	cout << "����� ��������: " << bgTimerDur / 10000000000 << " ���\n\n";
}

void delElement(int& alink, int N) {
	int* a = &alink;
	int elementNumToDelete;
	do {
		cout << "������� ����� �������� ��� ��� ��������: ";
		elementNumToDelete = inputCheck();
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
				}
				else cout << a[i] << " ";
			}
			auto delTimerEnd = chrono::high_resolution_clock::now();
			double delTimerDur = (delTimerEnd - delTimerStart).count();
			cout << "\n����� �������� ��������: " << delTimerDur / 10000000000 << " ���";
			break;
		}
		else {
			cout << "����� ������� �� �������� �������. ����������, ������� ����� � ���������� �� 0 �� " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);

	cout << "\n��������� ������ � ��������� ���������:\n";
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
}

void insElement(int& alink, int N) {
	int* a = &alink;
	int elementNumToInsert, elementToInsert;
	do {
		cout << "\n\n������� ����� �������� ��� �������: ";
		elementNumToInsert = inputCheck();
		if (elementNumToInsert >= 0 && elementNumToInsert < N) {
			cout << "������� �������� �������� ��� �������: ";
			elementToInsert = inputCheck();
			auto insTimerStart = chrono::high_resolution_clock::now();
			for (int i = 0; i < N; i++)
			{
				if (i == elementNumToInsert) cout << elementToInsert << " ";
				cout << a[i] << " ";
			}
			auto insTimerEnd = chrono::high_resolution_clock::now();
			double insTimerDur = (insTimerEnd - insTimerStart).count();
			cout << "\n����� ������� ��������: " << insTimerDur / 10000000000 << " ���";
			break;
		}
		else {
			cout << "����� ������� �� �������� �������. ����������, ������� ����� � ���������� �� 0 �� " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);

	cout << "\n��������� ������ � ��������� ���������:\n";
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
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

void search(int& alink, int N) {
	int* a = &alink;
	cout << "\n\n������� �������� ��� ������: ";
	int numToSearch = inputCheck();
	auto searchTimerStart = chrono::high_resolution_clock::now();
	int searchRes = binSearch(a, 0, N - 1, numToSearch);
	auto searchTimerEnd = chrono::high_resolution_clock::now();
	if (searchRes == -1) cout << "������ ����� �� ������� =(";
	else cout << "����� ����� �������! ��� ����� � �������: " << searchRes;
	double searchTimerDur = (searchTimerEnd - searchTimerStart).count();
	cout << "\n����� ������ ��������: " << searchTimerDur / 10000000000 << " ���";
}

void makeSym(int& alink, int N) {
	int* a = &alink;
	cout << "\n\n_�������� ������������� �������_";
	int ind, val;
	do {
		cout << "\n������� ����� ��������, ������� ����� ��������: ";
		ind = inputCheck();
		if (ind >= 0 && ind < N) break;
		else {
			cout << "����� ������� �� �������� �������. ����������, ������� ����� � ���������� �� 0 �� " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);
	cout << "\n������� �������� ��� ������: ";
	val = inputCheck();
	int center;
	do {
		cout << "\n������� ����� ������������ ��������: ";
		center = inputCheck();
		if (center >= 0 && center < N) break;
		else {
			cout << "����� ������� �� �������� �������. ����������, ������� ����� � ���������� �� 0 �� " << N - 1 << "\n";
			cin.clear();
		}
	} while (true);

	cout << "\n������ ������������ ������...\n";

	auto symmTimerStart = chrono::high_resolution_clock::now();
	a[ind] = val;
	for (int j = 0;;)
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
	cout << "\n����� ��������: " << symmTimerDur / 1000000 << " ���\n\n";
}
#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void reverse(int* first, int* second)
{
	while ((first != second) && (first != --second)) {
		swap(*first++, *second);
	}
}
bool next(int* end)
{
	int* i = end;
	--i;
	while (true)
	{
		int* j = i;
		--i;
		if (*i < *j)
		{
			int* k = end;
			while (!(*i < *--k));
			swap(i, k);
			reverse(j, end);
			return true;
		}
	}
}
int factorial(int n) {
	if (n < 0)return -1;
	if (n == 0)return 1;
	else
		return n * factorial(n - 1);
}

void separetion(int n) {
	cout << endl << "(x-y)^9" << endl;
	int C;
	for (int k = 0; k <= n; k++) {
		C = factorial(n) / (factorial(n - k) * factorial(k));
		cout << C << "*";
		if (k != 0) {
			cout << "y^" << k;
		}
		if (n - k != 0) {
			if (k != 0)cout << "*";
			cout << "x^" << n - k;
		}
		if (k != n) {
			if (k % 2 == 0) {
				cout << " - ";
			}
			else {
				cout << " + ";
			}
		}
	}
}

int main() {
	int elems[] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 6; i++) {
		cout << elems[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 12; i++) {
		next(elems + 6);
		for (int i = 0; i < 6; i++) {
			cout << elems[i] << " ";
		}
		cout << endl;
	}
	int n = 9;
	separetion(n);
	return 0;
}
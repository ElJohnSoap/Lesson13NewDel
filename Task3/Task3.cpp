/*3. Даны два массива: А[M] и B[N] (M и N вводятся
с клавиатуры). Необходимо создать третий массив
минимально возможного размера, в котором нужно
собрать элементы обоих массивов.*/

#include <iostream>
using namespace std;

void initArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}
int main()
{
	int M, N, T;
	cin >> M >> N;
	T = M + N;
	int* A = new int[M];
	int* B = new int[N];
	int* C = new int[T];

	initArr(A, M);
	initArr(B, N);
	printArr(A, M);
	cout << endl;
	printArr(B, N);
	cout << endl;
	for (int i = 0; i < T; i++)
	{
		C[i] = A[i];
		if (i >= M)
			C[i] = B[i - M];
	}
	printArr(C, T);
	cout << endl;
	delete []A;
	delete []B;
	delete []C;
	return 0;
}
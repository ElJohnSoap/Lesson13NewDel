/*1. Даны два массива: А[M] и B[N] (M и N вводятся
с клавиатуры). Необходимо создать третий массив
минимально возможного размера, в котором нужно
собрать элементы массива A, которые не включаются
в массив B, без повторений.*/

#include <iostream>
using namespace std;
void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
void initArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;
    cout << endl;
}

int main()
{
    srand(time(0));
    bool retry = true;
    int  M, N, T = 0;
    cin >> M >> N;
    int* A = new int[M];
    int* B = new int[N];
    //int* C = new int[T];
    initArr(A, M);
    initArr(B, N);
    for (int i = 0; i < M; i++)
    {
        retry = true;
        for (int j = 0; j < N; j++)
        {
            if (A[i] == B[j])
            {
                retry = false;
                break;
            }            
        }
        if (retry) T++;
    }
    printArr(A, M);
    printArr(B, N);
    int* C = new int[T];
    //cout << T;

    for (int i = 0, c = 0; i < M; i++)
    {
        retry = true;
        for (int j = 0; j < N; j++)
        {
            if (A[i] == B[j])
            {
                retry = false;
                break;
            }
        }
        if (retry)
        {
            C[c] = A[i];
            c++;
        }
        cout << c;
    }
    cout << "\t" << T;
    printArr(C, T);
}


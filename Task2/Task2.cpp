/*2. Даны два массива: А[M] и B[N] (M и N вводятся
с клавиатуры). Необходимо создать третий массив
минимально возможного размера, в котором нужно
собрать элементы массивов A и B, которые не являются общими для них, без повторений.*/

#include <iostream>
using namespace std;

void initArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int main()
{
    srand(time(0));
    bool retry = true;
    int M, N, count = 0;
    cin >> M >> N;
    int* A = new int[M];
    int* B = new int[N];
    initArr(A, M);
    initArr(B, N);
    printArr(A, M);
    printArr(B, N);
    
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
        if (retry)count++;

        retry = true;
        for (int j = 0; j < M; j++)
        {
            if (A[j] == B[i])
            {
                retry = false;
                break;
            }            
        }
        if (retry)count++;
    }
    cout << count;
    return 0;
}
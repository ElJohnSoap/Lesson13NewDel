/*Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные значения. Пользователь вводит данные в массив, а также
с помощью меню решает, что нужно удалить.*/

#include <iostream>
using namespace std;

void delElem(int *&arr, int &size, const int c)
{
    int size2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (c == 2)
        {
            if (arr[i] % 2 != 0)
            {
                size2++;
            }
        }
        if (c == 1)
        {
            if (arr[i] % 2 == 0)
            {
                size2++;
            }
        }
    }

    int* arr2 = new int[size2];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (c == 2)
        {
            if (arr[i] % 2 != 0)
            {
                arr2[j] = arr[i];
                j++;
            }
        }
        if (c == 1)
        {
            if (arr[i] % 2 == 0)
            {
                arr2[j] = arr[i];
                j++;
            }
        }
    }
    delete[]arr;
    arr = arr2;
    size = size2;    
}

int choise()
{
    int c;
    do {
        cout << "Удалить нечётные значения введите: 1\n";
        cout << "        чётные  значения  введите: 2\n";
        cout << "Введите 1 или 2: ";
        cin >> c;
    } while (c != 1 && c != 2);
    return c;
}

void printArr(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] <<"\t";
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int M;
    cout << "Введите размер массива: ";
    cin >> M;
    int* A = new int[M];
    for (int i = 0; i < M; i++)
    {
        cout << "Введите " << i << " элемент: ";
        cin >> A[i];
    }
    
    printArr(A, M);
    int c = choise();//выбор чёт-нечёт

    
    delElem(A, M, c);
    cout << "Новый массив: ";
    printArr(A, M);
    cout << "Размер нового массива: " << M << "эл.\n" ;
    
    delete[]A;
    
    return 0;
}

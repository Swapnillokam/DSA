#include <iostream>

using namespace std;

void printArray(int arr[], int n);

void bubbleSort(int a[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSwap = true;
            }

            if (!isSwap)   // array is already sorted
                return;
        }
    }
    printArray(a, length);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int a[] = {4, 1, 5, 2, 3};
    bubbleSort(a, 5);

    return 0;
}
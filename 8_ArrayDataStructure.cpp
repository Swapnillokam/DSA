#include <iostream>
#include <climits>
using namespace std;

// smallest element in an array
int smallestElement()
{
    int a[] = {23, 54, 5, 62, -65, 324, 26};
    int length = sizeof(a) / sizeof(a[0]);
    int smallest = INT_MAX;

    for (int i = 0; i < length; i++)
    {
        if (a[i] < smallest)
        {
            smallest = a[i];
        }
        // or
        // smallest = min(a[i],smallest);
    }
    for (int i = 0; i < length; i++)
    {
        if (smallest == a[i])
        {
            cout << "The index of smallest numebr is " << i << endl;
        }
    }
    return smallest;
}

int largestElement()
{
    int a[] = {23, 54, 5, 62, -65, 264, 26};
    int length = sizeof(a) / sizeof(a[0]);
    int largest = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
        // or
        // smallest = min(a[i],smallest);
    }
    for (int i = 0; i < length; i++)
    {
        if (largest == a[i])
        {
            cout << "The index of largest numebr is " << i << endl;
        }
    }
    return largest;
}

int linearSearch(int a[], int size, int target)
{
    int sum = 0;
    double product = 1;
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        // if (target == a[i])
        // {
        //     return i;
        // }
        // HW
        // cal sum and product
        sum += a[i];
        product *= a[i];

        // swap max and min
        largest = max(a[i], largest);
        smallest = min(a[i], smallest);
        if (largest == a[i])
        {
            a[i] = smallest;
        }
        if (smallest == a[i])
        {
            a[i] = largest;
        }
    }
    cout << "Sum of all numbers in array " << sum << endl;
    cout << "Product of all numbers in array " << product << endl;
    cout << "Largest " << largest << endl;
    cout << "Smallest " << smallest << endl;
    cout << "Array after swapping max and min elements " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return -1;
}

// reversing an array usign two point approach
void reverseArray()
{
    int a[] = {23, 54, 23, 65, 8798, 45, 3};
    int length = sizeof(a) / sizeof(a[0]);
    cout << "Original array is ";
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
    cout << "Reversed array is ";
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
}

// hw
void printUniqueValues()
{
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3, 4};

    cout << endl
         << "Intersectiosn at ";

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (b[i] == a[j])
            {
                cout << b[i] << " ";
            }
        }
    }
}

int main()
{
    // cout << endl
    //      << "The smallest number from the array is " << smallestElement() << endl;
    // cout << "The largest number from the array is " << largestElement() << endl
    //      << endl;

    // int a[] = {12, 34, 23, 5, 235, 346, 233, 54, 76};
    // int size = 9;
    // int target = 5;
    // cout << linearSearch(a, size, target) << endl;

    // reverseArray();

    printUniqueValues();
    return 0;
}
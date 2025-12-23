#include <iostream>
#include <utility>
#include <climits>
#include <vector>
using namespace std;

void _2dArrays()
{
    // int a[4][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12}};
    int a[4][3];

    int rows = 4;
    int cols = 3;

    // input values
    std::cout << "Enter the values" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }
    // output values
    std::cout << "The values are " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << a[i][j] << " ";
        }

        std::cout << endl;
    }
}

// linear search in 2d array
pair<int, int> _2DlinearSearch(int a[][3], int rows, int cols, int key)
{
    pair<int, int> p(-1, -1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] == key)
            {
                p.first = i;
                p.second = j;
            }
        }
    }
    return p;
}

int maxRowSum2D(int a[][3], int rows, int cols)
{
    int rowSum;
    int maxRowSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += a[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
}

// 0(n2)
int _2DSumOfDiagonals(int a[][3], int rows, int cols)
{
    int diaSum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                diaSum += a[i][j];
            }
            else if (j == rows - i - 1)
            {
                diaSum += a[i][j];
            }
        }
    }
    return diaSum;
}

// 0(n)
int _2DSumOfDiagonalsOptimize(int a[][3], int rows, int cols)
{
    int diaSum = 0;
    for (int i = 0; i < rows; i++)
    {
        diaSum += a[i][i];
        if (i != rows - i - 1)
        {
            diaSum += a[i][rows - i - 1];
        }
    }
    return diaSum;
}

int main()
{
    // _2dArrays();

    int a[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    // cout << linearSearch(a, 4, 3, 12) << endl;
    // pair<int, int> p = _2DlinearSearch(a, 4, 3, 12);
    // cout << "{" << p.first << "," << p.second << "}" << endl;

    // cout << "The max sum of a row in a 2d array is " << maxRowSum2D(a, 4, 3) << endl;

    int b[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // std::cout << "The sum of diagonals of a 2d array is " << _2DSumOfDiagonals(b, 3, 3) << endl;
    // std::cout << "The sum of diagonals of a 2d array is " << _2DSumOfDiagonalsOptimize(b, 3, 3) << endl;

    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6, 8, 10},
        {7, 8, 9}};

    // rows = v.size();
    // colums = v[i].size();

    cout << "ELements of the 2d vector are" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
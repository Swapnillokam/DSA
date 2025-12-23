// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // // 0(n2)
// // // bubbleSort
// // void bubbleSort(int a[], int n)
// // {
// //     bool isSwap = false;
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j < n - i - 1; j++)
// //         {
// //             if (a[j] > a[j + 1])
// //             {
// //                 swap(a[j], a[j + 1]);
// //                 isSwap = true;
// //             }
// //         }
// //         if (!isSwap)
// //         {
// //             return;
// //         }
// //     }
// // }

// // // selectionSort-0(n2) --opposite of bubble sort
// // void selectionSort(int a[], int n)
// // {
// //     for (int i = 0; i < n - 1; i++)
// //     {
// //         int ai = a[i];
// //         int smallestIndex = i;
// //         for (int j = i + 1; j < n; j++)
// //         {
// //             int aj = a[j];
// //             int aSI = a[smallestIndex];
// //             if (a[j] < a[smallestIndex])
// //             {
// //                 smallestIndex = j;
// //                 aSI;
// //             }
// //         }
// //         swap(a[i], a[smallestIndex]);
// //     }
// // }

// // // insertionSort-0(n2)
// // void insertionSort(int a[], int n)
// // {
// //     for (int i = 1; i < n; i++)
// //     {
// //         int curr = a[i];
// //         int prev = i - 1;
// //         while (prev >= 0 && a[prev] > curr)
// //         {
// //             a[prev + 1] = a[prev];
// //             prev--;
// //         }
// //         a[prev + 1] = curr;
// //     }
// // }

// // void printArray(int a[], int n)
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         cout << a[i] << " ";
// //     }
// // }
// // int main()
// // {
// //     int a[] = {4, 1, 5, 2, 3};
// //     int n = sizeof(a) / sizeof(a[0]);
// //     // bubbleSort(a, n);
// //     // selectionSort(a, n);
// //     insertionSort(a, n);
// //     printArray(a, n);
// //     cout << endl;
// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// using namespace std;

// void sort(vector<int> &v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (v[j] < v[i])
//             {
//                 swap(v[i], v[j]);
//             }
//         }
//     }
// }

// void printArray(vector<int> &a, int n)
// {
//     for (int num : a)
//     {
//         cout << num << " ";
//     }
// }

// int main()
// {
//     vector<int> v = {2, 0, 2, 1, 1, 0};
//     int n = v.size();
//     sort(v, n);
//     printArray(v, n);
//     return 0;
// }

// 25_sort0s,1s&2s.cpp

// #include <iostream>
// #include <vector>
// using namespace std;

// //leetcode - 75

// // bruteForceAppraoch
// void sort(vector<int> &v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (v[j] < v[i])
//             {
//                 swap(v[i], v[j]);
//             }
//         }
//     }
// }

// // Optimize Appraoach
// void sortOptimize(vector<int> &v, int n)
// {
//     int count0 = 0, count1 = 0, count2 = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (v[i] == 0)
//             count0++;
//         if (v[i] == 1)
//             count1++;
//         if (v[i] == 2)
//             count2++;
//     }
//     int idx = 0;
//     for (int i = 0; i < count0; i++)
//     {
//         v[idx++] = 0;
//     }

//     for (int i = 0; i < count1; i++)
//     {
//         v[idx++] = 1;
//     }

//     for (int i = 0; i < count2; i++)
//     {
//         v[idx++] = 2;
//     }
// }

// // Optimal Appraoach
// // DNS - Dutch National Algorithm
// // 0(n)
// void sortDNS(vector<int> &v, int n)
// {
//     int low = 0, mid = 0, high = n - 1;
//     while (mid <= high)
//     {
//         if (v[mid] == 0)
//         {
//             swap(v[mid], v[low]);
//             mid++;
//             low++;
//         }
//         else if (v[mid] == 1)
//         {
//             mid++;
//         }
//         else
//         {
//             swap(v[high], v[mid]);
//             high--;
//         }
//     }
// }

// void printArray(vector<int> &a, int n)
// {
//     for (int num : a)
//     {
//         cout << num << " ";
//     }
// }

// int main()
// {
//     vector<int> v = {2, 0, 2, 1, 1, 0};
//     int n = v.size();
//     // sort(v, n);
//     // sortOptimize(v, n);
//     sortDNS(v, n);
//     printArray(v, n);
//     return 0;
// }

// 26_MergeSortedArray.cpp
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> merge2SortedArrays(vector<int> v1, vector<int> v2)
// {
//     int m = v1.size() - v2.size();
//     int n = v2.size();
//     int i = m - 1;
//     int j = n - 1;
//     int idx = m + n - 1;
//     while (i >= 0 && j >= 0)
//     {
//         if (v1[i] >= v2[j])
//         {
//             v1[idx] = v1[i];
//             idx--;
//             i--;
//         }
//         else
//         {
//             v1[idx] = v2[j];
//             idx--;
//             j--;
//         }
//     }
//     while (j >= 0)
//     {
//         v1[idx] = v2[j];
//         idx--;
//         j--;
//     }

//     return v1;
// }

// void printArray(vector<int> &a, int n)
// {
//     for (int num : a)
//     {
//         cout << num << " ";
//     }
// }
// int main()
// {
//     vector<int> v1 = {1, 2, 3, 0, 0, 0};
//     vector<int> v2 = {2, 5, 6};
//     vector<int> v = merge2SortedArrays(v1, v2);
//     printArray(v,v.size()-1);
//     return 0;
// }

// Q - leetcode 31
// Next Permutation
// return lexicographically
// #include <iostream>
// #include <vector>
// using namespace std;

// // TC : 0(n), SC : 0(1)
// void nextPermutation(vector<int> &v)
// {
//     int pivot = -1;
//     int n = v.size();

//     // 1. find the pivot
//     // TC - 0(n)
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (v[i] < v[i + 1])
//         {
//             pivot = i;
//             break;
//         }
//     }

//     if (pivot == -1)
//     {
//         // reverse(v.begin(), v.end());
//         int i = 0;
//         int j = v.size() - 1;
//         while (i <= j)
//         {
//             swap(v[i++], v[j--]);
//         }
//         return;
//     }

//     // 2. next larger element
//     for (int i = n - 1; i > pivot; i--)
//     {
//         if (v[i] > v[pivot])
//         {
//             swap(v[i], v[pivot]);
//             break;
//         }
//     }

//     // 3. reverse(pivot + 1 to n - 1)
//     // 2 pointer appraoch
//     int i = pivot + 1, j = n - 1;
//     while (i <= j)
//     {
//         swap(v[i++], v[j--]);
//     }
// }
// void printArray(vector<int> &a)
// {
//     for (int num : a)
//     {
//         cout << num << " ";
//     }
// }

// int main()
// {
//     vector<int> v = {1, 2, 3, 5, 4};
//     nextPermutation(v);
//     printArray(v);
//     return 0;
// }


// 27_CPP_STL
// 1. Containers
// 2. Iterators
// 3. Algorithms
// 4. Functors

// 1. Containers
// a.Vectors
//      Vector functions 
//         TC : 0(1)
//        - size and capapcity
//        - push_back and pop_back
//        - emplace_back
//        - at() or []
//        - front and back

//         TC : 0(n)
//        - erase
//        - insert
//        - clear
//        - empty

//      Vector iterators 
//         forward iterators
//        - vec.begin
//        - vec.end
//         reverse iterators
//        - vec.rbegin
//        - vec.rend

//2. List (Doubly linked list)
//      list functions 
//       - push_back and push_front
//       - emplace_back and emplace_front        
//       - pop_back and pop_front 
//        -sixe,erase,begin,end,ebegin,rend,insert,front,back

//3.Deque : Double Ended Queue (dynamic arrays) 
//same functions and same syntax as that of list

//all the above containers are sequence containers

//Non sequential containers
// 4. Stack(LIFO - last in first out)
// 5. Queue(FIFO - first in first out)
// 6. Priority Queue


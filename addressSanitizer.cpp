#include <iostream>

int main() {
    int* arr = new int[5];
    arr[5] = 42; // Out-of-bounds write
    // forgot delete[] arr; memory leak
    return 0;
}

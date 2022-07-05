#include <iostream>

using namespace std;

const int SIZE = 8;

int sumArr(int[], int);
int sumArr(int*, int*);

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int sum1 = sumArr(arr, SIZE);
    int sum2 = sumArr(arr, arr + 3);
    
    cout << sum1 << '\n';
    printf("%d\n", sum2);
    
    return 0;
}

// int sumArr(int* arr, int n)°ú µ¿ÀÏ
int sumArr(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int sumArr(int* begin, int* end) {
    int total = 0;
    int* pt;

    for (pt = begin; pt != end; pt++)
        total += *pt;

    return total;
}
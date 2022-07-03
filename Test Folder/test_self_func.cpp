#include <iostream>

using namespace std;

void countDown(int);
int func(int);

int main() {
    int (*pf)(int); // 함수 포인터
    pf = func;

    countDown(3);
    printf("%d\n", (*pf)(3));

    return 0;
}

void countDown(int n) {
    printf("Counting... %d\n", n);
    if (n > 1)
        countDown(n - 1);
    printf("%d번째 재귀함수\n");
}

int func(int n) {
    return n + 1;
}
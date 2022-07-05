#include <iostream>

using namespace std;

void countDown(int);
int func(int);

int main() {
    int (*pf)(int); // �Լ� ������
    pf = func;

    countDown(3);
    printf("%d\n", (*pf)(3));

    return 0;
}

void countDown(int n) {
    printf("Counting... %d\n", n);
    if (n > 1)
        countDown(n - 1);
    printf("%d��° ����Լ�\n");
}

int func(int n) {
    return n + 1;
}
#include <iostream>

using namespace std;

// �ִ�����
int gcd(int a, int b){
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int main(){
    int a, b, c, d;
    int m, n;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    m = a * d + b * c;
    n = b * d;

    // �ִ������� �и�, ���� ��� -> ���м�
    printf("%d %d", m / gcd(m, n), n / gcd(m, n));

    return 0;
}
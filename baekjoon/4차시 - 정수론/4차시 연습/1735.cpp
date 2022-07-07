#include <iostream>

using namespace std;

// 최대공약수
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

    // 최대공약수로 분모, 분자 약분 -> 기약분수
    printf("%d %d", m / gcd(m, n), n / gcd(m, n));

    return 0;
}
#include <iostream>

using namespace std;

int gcd(int a, int b){
    int r;

    while(b!=0){
        r=a%b;
        a=b, b=r;
    }

    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(){
    int a, b, c, d, m, n;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    m=lcm(b, d);
    n=a*(lcm(b, d)/b)+c*(lcm(b, d)/d);

    int g=gcd(n, m);

    if(g!=1)
        printf("%d %d", n/g, m/g);
    else
        printf("%d %d", n, m);

    return 0;
}
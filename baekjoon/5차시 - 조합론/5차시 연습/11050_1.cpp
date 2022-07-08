// ÆÑÅä¸®¾ó
#include <iostream>

using namespace std;

int fact(int a){
    if(a == 0)
        return 1;

    for(int i = a - 1; i > 0; i--)
        a *= i;
    return a;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", fact(n) / (fact(n - k) * fact(k)));

    return 0;
}
// 수학적 접근
#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    ll x, y;
    cin >> x >> y;
    int z = (y * 100) / x;

    if(z >= 99){
        printf("%d", -1);
        return 0;
    }

    else{
        ll a = x * (z + 1) - 100 * y;
        ll b = 99 - z;
        if(a % b == 0)
            printf("%d", a / b);
        else
            printf("%d", a / b + 1);
    }

    return 0;
}
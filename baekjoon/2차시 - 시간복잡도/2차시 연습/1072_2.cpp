// ÀÌºÐ Å½»ö
#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    ll x, y;
    int ans = 0, l = 0, r = 1000000000;
    cin >> x >> y;
    int z = (y * 100) / x;

    if(z >= 99){
        printf("%d", -1);
        return 0;
    }

    else{
        while(l <= r){
            int m = (l + r) / 2;
            int a = (100 * (y + m)) / (x + m);
            
            if(a > z)
                r = m - 1;
            else{
                l = m + 1;
                ans = m + 1;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
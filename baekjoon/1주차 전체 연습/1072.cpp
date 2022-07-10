#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    ll x, y;
    int z;
    scanf("%lld %lld", &x, &y);

    z=(y*100)/x;

    if(z>=99){
        printf("-1");
        return 0;
    }

    ll a=x*(z+1)-100*y;
    ll b=99-z;
    if(a%b==0) printf("%lld", a/b);
    else printf("%lld", a/b+1);

    return 0;
}
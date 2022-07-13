#include <iostream>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
   
    return gcd(b, a % b);
}

ll ex_gcd(ll a, ll b){
    ll t, t1=1, t2=0, q, r, s=a;

    while(b!=0){
        q = a / b;
        r = a % b;
        a = b;
        b = r;
        t = t2; 
        t2 = t1;
        t1 = t - t1 * q;
    }

    while(t2 < 0) t2 += s;
     
    return t2;
}

int main(){
    int n;
    scanf("%d", &n);

    // cy=kx+1
    for(int i=0; i<n; i++){
        ll k, c;
        scanf("%lld %lld", &k, &c);

        if(gcd(k, c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }

        else if(c == 1){
            if(k+1>1e9) printf("IMPOSSIBLE\n");
            else printf("%lld\n", k+1);
            continue;
        }

        else if(k==1){
            printf("1\n");
            continue;
        }

        ll ans = ex_gcd(k, c);

        if(ans>1e9) printf("IMPOSSIBLE\n");
        else printf("%lld\n", ans);
    }

    return 0;
}
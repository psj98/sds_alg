//  C*y=K*x+1 -> C*y=1(mod K)
#include <iostream>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

ll ex_gcd(ll a, ll b){
    ll tmp=a, t, t1=0, t2=1;
    ll r, q;

    while(b!=0){
        r=a%b;
        q=a/b;
        t=t1-q*t2;
        a=b;
        b=r;
        t1=t2;
        t2=t;
    }

    // 음수인 경우, 1이 부족하기 때문에 a를 더함 -> a를 더해서 곱한 값은 1이 더해져서 조건에 만족 (25, 4)
    while(t1<0) t1+=tmp;

    return t1;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        ll k, c;
        scanf("%lld %lld", &k, &c);

        if(gcd(k, c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }

        else if(c==1){
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
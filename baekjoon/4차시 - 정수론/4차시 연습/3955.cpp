// 확장 유클리드 호제법
#include <iostream>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
   
    return gcd(b, a % b);
}

ll ex_gcd(ll a, ll b){
    ll t, t1 = 0, t2 = 1, r, q, s = a;

    while(b!=0){
        q = a / b;
        r = a % b;
        a = b;
        b = r;
        t = t1; 
        t1 = t2;
        t2 = t - t2 * q;
    }

    // 음수인 경우, 1이 부족하기 때문에 a를 더함
    // -> a를 더해서 곱한 값은 1이 더해져서 조건에 만족 (25, 4)
    while(t1 < 0) t1 += s;
     
    return t1;
}

int main(){
    int n;
    scanf("%d", &n);

    // Cy=Kx+1
    for(int i = 0; i < n; i++){
        ll k, c, ans;
        scanf("%lld %lld", &k, &c);

        // 최대공약수가 있는 경우
        if(gcd(k, c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        
        // 한 봉지 사탕 개수가 1인 경우
        else if(c == 1){
            // 범위 체크 (10^9)
            if(k + 1 > 1e9)
                printf("IMPOSSIBLE\n");
            else
                printf("%lld\n", k + 1);
            continue;
        }

        // 사람이 1명인 경우
        else if(k == 1){
            printf("1\n");
            continue;
        }

        ans = ex_gcd(k, c);

        // 범위 체크 (10^9)
        if(ans > 1e9)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
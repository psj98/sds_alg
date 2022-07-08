// Integer Overflow
#include <iostream>
#include <string>
#include <limits.h>

typedef long long ll;
using namespace std;

ll k, cnt=0, s;
string str="";

ll fact(ll a){
    if(a==0)
        return 1;

    for(ll i=a-1; i>0; i--)
        a*=i;

    return a;
}

ll ans_len(ll a, ll b){
    ll max, min, d=s;
    if(a>=b)
        max=a, min=b;
    else
        max=b, min=a;
    
    for(ll i=s-1; i>max; i--)
        d*=i;

    for(ll i=min-1; i>0; i--)
        min*=i;

    if(d/min>INT_MAX)
        return -1;
    else
        return d/min;
}

ll solve(ll n, ll m){
    ll a=fact(n+m-1)/(fact(n-1)*fact(m));
    if(cnt+a>=k){
        str.append("a");
        n-=1;
    }

    else{
        cnt+=a;
        str.append("z");
        m-=1;
    }
    
    if(s==str.size())
        return 0;

    return solve(n, m);
}

int main(){
    ll n, m, len;
    scanf("%lld %lld %lld", &n, &m, &k);
    s=n+m;
    // if(fact(n+m)/(fact(n)*fact(m))>INT_MAX)
    len=ans_len(n, m); // Integer Overflow
    

    // printf("%lld", (fact(200)/fact(100)));

    if(len<k){
        printf("-1");
        return 0;
    }

    ll a=solve(n, m);

    cout << str;

    return 0;
}
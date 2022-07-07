// Ȯ�� ��Ŭ���� ȣ����
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

    // ������ ���, 1�� �����ϱ� ������ a�� ����
    // -> a�� ���ؼ� ���� ���� 1�� �������� ���ǿ� ���� (25, 4)
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

        // �ִ������� �ִ� ���
        if(gcd(k, c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        
        // �� ���� ���� ������ 1�� ���
        else if(c == 1){
            // ���� üũ (10^9)
            if(k + 1 > 1e9)
                printf("IMPOSSIBLE\n");
            else
                printf("%lld\n", k + 1);
            continue;
        }

        // ����� 1���� ���
        else if(k == 1){
            printf("1\n");
            continue;
        }

        ans = ex_gcd(k, c);

        // ���� üũ (10^9)
        if(ans > 1e9)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
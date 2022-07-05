// 이분 탐색
#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int a[1000000] = {0};

int main(){
    ll n, m, sum = 0;
    int ans = 0, l = 0, r;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    r = *max_element(a, a + n); // 배열에서의 최댓값

    while(l <= r){
        int mid = (l + r) / 2; // 중간값
        sum = 0;

        for(int i = 0; i < n; i++)
            if(a[i] > mid)
                sum += a[i] - mid;

        if(sum >= m){
            if(ans < mid)
                ans = mid;
            l = mid + 1;
        }

        else r = mid - 1;
    }

    printf("%d", ans);

    return 0;
}
// 투 포인터 (둘 다 오름차순인 경우)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000

typedef long long ll;
using namespace std;

ll arr[4][MAX];
vector<ll> vec1;
vector<ll> vec2;

int main(){
    ll ans = 0;
    int n;
    cin >> n;

    int l = 0, r = n * n - 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[j][i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            vec1.push_back(arr[0][i] + arr[1][j]);
            vec2.push_back(arr[2][i] + arr[3][j]);
        }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    while(r >= 0 && l < n * n){
        if(vec1[r] == -vec2[l]){
            ll ab = 0, cd = 0, a = vec1[r];

            while(vec1[r] == a && r >= 0)
                ab++, r--;

            while(vec2[l] == -a && l < n * n)
                cd++, l++;

            ans += ab * cd;
        }
        else if(vec1[r] > -vec2[l])
            r--;
        else l++;
    }

    cout << ans;

    return 0;
}
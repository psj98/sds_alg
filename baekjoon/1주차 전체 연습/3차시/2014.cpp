#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

typedef long long ll;
using namespace std;

vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ll ans;
    int k, n;
    scanf("%d %d", &k, &n);

    for(int i=0; i<k; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
        pq.push(a);
    }

    for(int i=0; i<n-1; i++){
        ans=pq.top();

        for(int j=0; j<v.size(); j++)
            if(v[j]*ans < pow(2, 31))
                pq.push(v[j]*ans);

        while(ans==pq.top()) pq.pop();
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int main(){
    ll ans;
    int k, n;
    scanf("%d %d", &k, &n);

    for(int i=0; i<k; i++){
        int a;
        scanf("%d", &a);
        pq.push(a);
        v.push_back(a);
    }

    for(int i=0; i<n-1; i++){
        ans=pq.top();
        
        for(int j=0; j<v.size(); j++)
            if(v[j]*ans < pow(2, 31))
                pq.push(v[j]*ans);

        while(ans==pq.top()) pq.pop();
    }

    printf("%d", pq.top());

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101

using namespace std;

vector<pair<int, int>> vec;
vector<int> ans;
int app[MAX];
int cost[MAX];

int main(){
    int n, m, l=0, r=0, sum=0, val=0;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &app[i]);

    for(int i=0; i<n; i++)
        scanf("%d", &cost[i]);

    for(int i=0; i<n; i++)
        vec.push_back(make_pair(cost[i], app[i]));

    sort(vec.begin(), vec.end());

    while(vec[r].second<=m){
        if(sum>=m){
            sum-=vec[l].second;
            val-=vec[l++].first;
        }
        else{
            sum+=vec[r].second;
            val+=vec[r++].first;
        }
        
        if(sum==m) ans.push_back(val);
    }

    sort(ans.begin(), ans.end());

    printf("%d", ans[0]);

    return 0;
}
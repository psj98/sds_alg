#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int deg[32001];
vector<int> v[32001];
queue<int> q;

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        deg[b]++;
    }

    // 차수가 0인 것부터 정렬
    for(int i=1; i<=n; i++)
        if(!deg[i]) q.push(i);

    while(!q.empty()){
        int f=q.front();
        q.pop();

        printf("%d ", f);

        for(int i=0; i<v[f].size(); i++){
            deg[v[f][i]]--;
            if(!deg[v[f][i]]) q.push(v[f][i]);
        }
    }

    return 0;
}
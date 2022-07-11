#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int degree[32001];
vector<int> v[32001];
queue<int> q;

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        degree[b]++;
    }

    for(int i=1; i<=n; i++)
        if(!degree[i]) q.push(i);

    while(!q.empty()){
        int num=q.front();
        q.pop();

        printf("%d ", num);

        for(int i=0; i<v[num].size(); i++){
            degree[v[num][i]]--;
            if(!degree[v[num][i]]) q.push(v[num][i]);
        }
    }

    return 0;
}
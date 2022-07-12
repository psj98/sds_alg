// 위상 정렬
#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int degree[MAX], cost[MAX], total[MAX];
vector<int> v[MAX];
queue<int> q;

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &cost[i]);
        while(1){
            int a;
            scanf("%d", &a);

            if(a==-1) break;

            v[a].push_back(i);
            degree[i]++;
        }
    }

    for(int i=1; i<=n; i++){
        if(!degree[i]){
            q.push(i);
            total[i]=cost[i];
        }
    }

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(int i=0; i<v[curr].size(); i++){
            int end=v[curr][i];
            total[end]=max(total[end], total[curr]+cost[end]);

            degree[end]--;
            if(!degree[end]) q.push(end);
        }
    }

    for(int i=1; i<=n; i++)
        printf("%d\n", total[i]);

    return 0;
}
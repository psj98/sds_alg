#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

vector<int> v[MAX];
int depth[MAX];
int parent[18][MAX];

int LCA(int a, int b){
    // Step 1 : Depth 맞추기
    // gkdtkd a의 Depth가 크도록 함
    if(depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int diff = depth[a] - depth[b];

    // r은 자릿수
    for(int r=0; diff>0; r++){
        // diff가 10이면, 10=2^3+2^1 -> 10을 2진수로 표현하면 1010
        if(diff & 1){
            a=parent[r][a];
        }
        diff >>= 1;
    }

    // Step 2 : LCA 찾기
    while(a!=b){
        int r;

        for(r=0; r<18; r++){
            if(parent[r][a]==parent[r][b]) break;
        }
        if(r>0) r--;
        a=parent[r][a], b=parent[r][b];
    }

    return a;
}

int main(){
    int n, m, a, b;
    scanf("%d", &n);

    for(int i=1; i<n; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++) depth[i]=-1;

    deque<int> q;

    // root node
    q.push_back(1);
    depth[1]=0;

    // bfs
    while(!q.empty()){
        int curr=q.front(); // 현재 노드
        q.pop_front();

        for(int next : v[curr]){
            if(depth[next]==-1){ // 미방문 시 탐색
                q.push_back(next);
                depth[next]=depth[curr]+1;
                parent[0][next] = curr;
            }
        }
    }

    // 점핑 테이블(희소 테이블)을 만들기
    for (int r=1; r<18; r++) {
        for (int i=1; i<=n; i++) {
            // parent[r][i]는 parent[r-1][i]의 2의 r-1제곱번째 부모
            parent[r][i] = parent[r-1][parent[r-1][i]];
        }
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

vector<int> v[MAX];
int depth[MAX];
int parent[18][MAX];

int LCA(int a, int b){
    // Step 1 : Depth ���߱�
    // gkdtkd a�� Depth�� ũ���� ��
    if(depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int diff = depth[a] - depth[b];

    // r�� �ڸ���
    for(int r=0; diff>0; r++){
        // diff�� 10�̸�, 10=2^3+2^1 -> 10�� 2������ ǥ���ϸ� 1010
        if(diff & 1){
            a=parent[r][a];
        }
        diff >>= 1;
    }

    // Step 2 : LCA ã��
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
        int curr=q.front(); // ���� ���
        q.pop_front();

        for(int next : v[curr]){
            if(depth[next]==-1){ // �̹湮 �� Ž��
                q.push_back(next);
                depth[next]=depth[curr]+1;
                parent[0][next] = curr;
            }
        }
    }

    // ���� ���̺�(��� ���̺�)�� �����
    for (int r=1; r<18; r++) {
        for (int i=1; i<=n; i++) {
            // parent[r][i]�� parent[r-1][i]�� 2�� r-1������° �θ�
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
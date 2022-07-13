// 벨만-포드 알고리즘
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

vector<pair<int, int>> vec[501]; // 노드, 노드, 비용
ll visited[501]; // 방문한 곳(최단 거리)

int main(){
    bool isNegativeCycle=true;
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back(make_pair(b, c));
    }

    for(int i=1; i<=n; i++)
        visited[i]=INT_MAX;
    
    visited[1]=0; // 처음 노드 초기화

    // n-1 만큼 돌리기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[j] < INT_MAX){
                for(auto& p : vec[j]){
                    int next=p.first;
                    int nextcost=p.second;

                    if(visited[next] > visited[j]+nextcost){
                        if(i==n){
                            isNegativeCycle=false;
                            break;
                        }
                        else
                            visited[next]=visited[j]+nextcost;
                    }
                }
            }
        }
    }

    if(!isNegativeCycle) printf("-1\n");
    else{
        for(int i=2; i<=n; i++)
            printf("%d\n", visited[i]==INT_MAX ? -1 : visited[i]);
    }

    return 0;
}
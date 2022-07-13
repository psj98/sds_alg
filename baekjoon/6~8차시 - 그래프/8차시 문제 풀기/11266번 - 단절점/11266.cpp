#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int visitOrder[MAX]; // 방문 여부 배열 / 미방문 : 0, 방문 순서 저장
int cutVertex[MAX]; // 각 정점의 단절점 여부 저장
int answer[MAX], ans; // 출력할 단절점 정보, 개수
int order; // 방문 순서
vector<int> AL[MAX];

int dfs(int curr, int parent){
    visitOrder[curr] = ++order; // 방문 order 저장

    // 내 부모에게 넘겨줄 low (현재 나의 return 값) 저장하는 변수
    // 나와 연결된 점을 방문했을 때, 방문한 연결 점이 방문했던 점들 중 order가 가장 빠른 것
    int minOrder=visitOrder[curr];

    // child의 개수 저장
    int child = 0; 

    // 다음 방문 예정인 점 탐색 - 현재 정점의 인접 리스트
    for(int next : AL[curr]){
        if(next == parent) continue; // 직접적인 부모 노드인 경우 pass

        // next가 기방문을 했을 경우
        if(visitOrder[next] > 0){
            // DST의 관점에서 보면 이러한 노드들은 curr의 조상인 경우 외엔 존재할 수 X
            // 다시 말해, next 노드는 현재 dfs 작업이 끝난 상태가 아니므로,
            // next 노드에서의 유일한 order 값은 visitOrder[next]가 유일
            minOrder = visitOrder[next] < minOrder ? visitOrder[next] : minOrder;
        }

        // next가 미방문 상태인 경우
        else{
            child++;
            int low = dfs(next, curr);

            if(parent && visitOrder[curr] <= low) cutVertex[curr] = 1;

            minOrder = low < minOrder ? low : minOrder;
        }
    }

    if(!parent && child>=2) cutVertex[curr]=1;

    return minOrder;
}

int main(){
    int v, e, a, b;
    scanf("%d %d", &v, &e);

    for(int i=0; i<e; i++){
        scanf("%d %d", &a, &b);
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    // 연결 그래프가 아니므로 모든 정점을 탐색하지 못할 수 있음
    for(int i=1; i<=v; i++){
        // 미방문인 경우
        if(visitOrder[i]==0) dfs(i, 0);
    }

    // 단절점 정보 출력
    for(int i=1; i<=v; i++)
        if(cutVertex[i]) answer[ans++]=i;

    printf("%d\n", ans);
    
    for(int i=0; i<ans; i++)
        printf("%d ", answer[i]);

    return 0;
}
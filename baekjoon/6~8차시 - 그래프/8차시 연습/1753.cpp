// 다익스트라 알고리즘 (시간 초과 조심)
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 20001

using namespace std;

vector<pair<int ,int>> vec[MAX];
int result[MAX];
priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    int v, e, start; // 정점 개수, 간선 개수, 시작 정점 번호
    int a, b, c; // 출발 노드, 도착 노드, 비용(가중치)
    scanf("%d %d %d", &v, &e, &start);

    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back(make_pair(b, c));
    }

    // 초기화
    for(int i = 1; i <= v; i++)
        result[i] = INF;

    result[start] = 0; // 시작 정점 번호 비용

    // 다익스트라
    pq.push(make_pair(0, start)); // 비용부터 정렬하도록 (비용, 노드)로 넣음

    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // node에서 출발하는 각 정점들의 비용 비교
        for(int i = 0; i < vec[node].size(); i++){
            int arriveNode = vec[node][i].first;
            int arriveCost = vec[node][i].second;

            // 거쳐가는 것과 기존 비용 비교
            if(cost + arriveCost < result[arriveNode]){
                result[arriveNode] = cost + arriveCost;
                pq.push(make_pair(cost + arriveCost, arriveNode));
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(result[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", result[i]);
    }

    return 0;
}
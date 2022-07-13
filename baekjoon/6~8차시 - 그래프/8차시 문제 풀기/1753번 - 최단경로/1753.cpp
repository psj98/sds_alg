// ���ͽ�Ʈ�� �˰���
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 20001

using namespace std;

vector<pair<int, int>> vec[MAX]; // ���� ��� ����
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
int visited[MAX]; // �ִ� ��� �湮 ����

int main(){
    int v, e, start, a, b, c;
    scanf("%d %d %d", &v, &e, &start);

    // ���� ���� (���۳��, �������, ���)
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back(make_pair(b, c));
    }

    // �ʱ�ȭ
    for(int i=1; i<=v; i++)
        visited[i]=INF;
    
    visited[start]=0;

    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(int i=0; i<vec[node].size(); i++){
            int n=vec[node][i].first;
            int w=vec[node][i].second;

            if(cost+w<visited[n]){
                visited[n]=cost+w;
                pq.push(make_pair(cost+w, n));
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(visited[i]==INF) printf("INF\n");
        else printf("%d\n", visited[i]);
    }
    
    return 0;
}
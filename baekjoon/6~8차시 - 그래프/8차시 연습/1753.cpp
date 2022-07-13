// ���ͽ�Ʈ�� �˰��� (�ð� �ʰ� ����)
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
    int v, e, start; // ���� ����, ���� ����, ���� ���� ��ȣ
    int a, b, c; // ��� ���, ���� ���, ���(����ġ)
    scanf("%d %d %d", &v, &e, &start);

    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back(make_pair(b, c));
    }

    // �ʱ�ȭ
    for(int i = 1; i <= v; i++)
        result[i] = INF;

    result[start] = 0; // ���� ���� ��ȣ ���

    // ���ͽ�Ʈ��
    pq.push(make_pair(0, start)); // ������ �����ϵ��� (���, ���)�� ����

    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // node���� ����ϴ� �� �������� ��� ��
        for(int i = 0; i < vec[node].size(); i++){
            int arriveNode = vec[node][i].first;
            int arriveCost = vec[node][i].second;

            // ���İ��� �Ͱ� ���� ��� ��
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
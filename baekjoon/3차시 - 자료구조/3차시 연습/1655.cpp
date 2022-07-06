// priority queue ��� (�ϳ��� ��������, �ϳ��� ��������)
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);

        // �� ���
        if(pq1.size() == pq2.size())
            pq1.push(a);
        else
            pq2.push(a);

        // �� ��ȯ
        if(!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top()){
            int a=pq1.top(), b=pq2.top();
            pq1.pop(), pq2.pop();
            pq1.push(b), pq2.push(a);
        }

        printf("%d\n", pq1.top());
    }

    return 0;
}
// priority queue, vector ���
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

typedef long long ll;
using namespace std;

vector<int> v; // ���� ���� �ִ� ����
priority_queue<int, vector<int>, greater<int>> pq; // �Ҽ����� ���� ������ ������������ ���ĵ� priority queue

int main(){
    int k, n;
    scanf("%d %d", &k, &n);

    for(int i = 0; i < k; i++){
        int a;
        scanf("%d", &a);
        pq.push(a);
        v.push_back(a);
    }

    ll ans;

    // �ݺ� Ƚ���� �� �� �ٿ��� �ð� �ʰ� ���� (n-1��°���� pop�ϸ� priority queue���� n��° ���ڰ� top��)
    for(int i = 0; i < n - 1; i++){
        ans = pq.top();

        for(int j = 0; j < v.size(); j++){
            if(ans * v[j] < pow(2, 31)) // ����
                pq.push(ans * v[j]); // �� �Ҽ����� ���� ���� priority queue�� ����
        }

        // �ߺ� ����
        while(pq.top() == ans)
            pq.pop();
    }

    printf("%d", pq.top());

    return 0;
}
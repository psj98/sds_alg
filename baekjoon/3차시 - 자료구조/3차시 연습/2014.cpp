// priority queue, vector 사용
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

typedef long long ll;
using namespace std;

vector<int> v; // 기존 값이 있는 벡터
priority_queue<int, vector<int>, greater<int>> pq; // 소수들을 곱한 값들이 오름차순으로 정렬된 priority queue

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

    // 반복 횟수를 한 번 줄여서 시간 초과 방지 (n-1번째까지 pop하면 priority queue에는 n번째 숫자가 top임)
    for(int i = 0; i < n - 1; i++){
        ans = pq.top();

        for(int j = 0; j < v.size(); j++){
            if(ans * v[j] < pow(2, 31)) // 조건
                pq.push(ans * v[j]); // 각 소수들을 곱한 값을 priority queue에 저장
        }

        // 중복 제거
        while(pq.top() == ans)
            pq.pop();
    }

    printf("%d", pq.top());

    return 0;
}
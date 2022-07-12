// 크루스칼 알고리즘 - 비용이 적은 순으로 오름차순 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];
vector<pair<int, pair<int ,int>>> v; // 비용, 노드, 노드

int findP(int a){
    if(a == parent[a])
        return a;
    else
        return parent[a] = findP(parent[a]);
}

void unionP(int a, int b){
    a = findP(a);
    b = findP(b);
    parent[a] = b;
}

int main(){
    int n, m, a, b, c, ans = 0;
    scanf("%d %d", &n, &m);

    // 초기화
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    // vector에 값 넣음
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(v.begin(), v.end()); // cost 기준으로 오름차순 정렬

    for(int i = 0; i < m; i++){
        int cost = v[i].first;
        int s = v[i].second.first;
        int e = v[i].second.second;

        // cycle이 없는 경우
        if(findP(s) != findP(e)){
            unionP(s, e);
            ans += cost;
        }
    }

    printf("%d", ans);

    return 0;
}
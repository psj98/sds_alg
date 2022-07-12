// ũ�罺Į �˰��� - ����� ���� ������ �������� ����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];
vector<pair<int, pair<int ,int>>> v; // ���, ���, ���

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

    // �ʱ�ȭ
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    // vector�� �� ����
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(v.begin(), v.end()); // cost �������� �������� ����

    for(int i = 0; i < m; i++){
        int cost = v[i].first;
        int s = v[i].second.first;
        int e = v[i].second.second;

        // cycle�� ���� ���
        if(findP(s) != findP(e)){
            unionP(s, e);
            ans += cost;
        }
    }

    printf("%d", ans);

    return 0;
}
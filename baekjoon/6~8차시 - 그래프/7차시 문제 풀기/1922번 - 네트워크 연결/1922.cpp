#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int com[1001];
vector<pair<int, pair<int, int>>> v;

int findP(int a){
    if(a==com[a]) return a;
    else return com[a]=findP(com[a]);
}

void unionP(int a, int b){
    a=findP(a);
    b=findP(b);
    com[a]=b;
}

int main(){
    int n, m, a, b, c, ans=0;
    scanf("%d %d", &n, &m);

    // 초기화
    for(int i=1; i<=n; i++)
        com[i]=i;

    // 값 넣기 (비용, (노드, 노드))
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_pair(c, make_pair(a, b)));
    }

    // 비용 순 정렬
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++){
        int t=v[i].first;
        int k=v[i].second.first;
        int l=v[i].second.second;

        if(!(findP(k)==findP(l))){
            ans+=t;
            unionP(k, l);
        }
    }

    printf("%d", ans);

    return 0;
}
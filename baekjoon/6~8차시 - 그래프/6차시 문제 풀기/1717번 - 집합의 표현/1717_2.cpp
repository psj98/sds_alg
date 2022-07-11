#include <iostream>

using namespace std;

int parent[1000001];

int findP(int a){
    if(parent[a]==a) return a;
    else return parent[a]=findP(parent[a]);
}

void unionP(int a, int b){
    a=findP(a);
    b=findP(b);
    parent[b]=a;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<=n; i++)
        parent[i]=i;

    for(int i=0; i<m; i++){
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if(k==0) unionP(a, b);
        else{
            if(findP(a)==findP(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
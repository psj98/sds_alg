#include <iostream>

using namespace std;

int parent[1000001];

int getP(int a){
    if(parent[a]==a) return a;
    else return parent[a]=getP(parent[a]);
}

void findP(int a, int b){
    a=getP(a);
    b=getP(b);
    if(a==b) printf("YES\n");
    else printf("NO\n");
}

void unionP(int a, int b){
    a=getP(a);
    b=getP(b);

    if(a>b) parent[a]=b;
    else parent[b]=a;
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
        else findP(a, b);
    }

    return 0;
}
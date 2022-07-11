#include <iostream>

using namespace std;

int arr[1000001];

int findP(int a){
    if(a==arr[a]) return a;
    else return arr[a]=findP(arr[a]);
}

void unionP(int a, int b){
    a=findP(a);
    b=findP(b);
    arr[a]=b;
}

int main(){
    int n, m, a, b, k;
    scanf("%d %d", &n, &m);

    for(int i=0; i<=n; i++)
        arr[i]=i;

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &k, &a, &b);
        
        if(k==0) unionP(a, b);
        else{
            if(findP(a)==findP(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
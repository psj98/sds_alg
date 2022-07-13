// ����-���� �˰��� (Ʋ��)
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct e_t{
    int a, b, c;
} E[6001];

int visited[501];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        visited[i]=INT_MAX;
    
    for(int i=1; i<=m; i++)
        scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].c);

    // ó��
    visited[1]=0;
    bool isNegativeCycle;

    // n-1 ��ŭ ������
    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            if(visited[E[j].a] < INT_MAX && visited[E[j].a]+E[j].c < visited[E[j].b]){
                visited[E[j].b]=visited[E[j].a]+E[j].c;
            }
        }
    }

    // ���� ����Ŭ Ȯ���� ���� �� �� �� ������
    for(int j=1; j<=m; j++){
        if(visited[E[j].a] < INT_MAX && visited[E[j].a]+E[j].c < visited[E[j].b]){
            isNegativeCycle=true;
            break;
        }
    }

    if(isNegativeCycle) printf("-1\n");
    else{
        for(int i=2; i<=n; i++)
            printf("%d\n", visited[i]==INT_MAX ? -1 : visited[i]);
    }

    return 0;
}
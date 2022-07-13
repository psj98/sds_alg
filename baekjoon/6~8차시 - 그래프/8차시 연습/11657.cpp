// ����-���� �˰���
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

typedef long long ll;
using namespace std;

vector<pair<int, int>> vec[501]; // ��� ���, ���� ���, ���
ll result[501]; // �ִ� �Ÿ� �迭

int main(){
    bool checkCycle=false;
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back(make_pair(b, c));
    }

    for(int i=1; i<=n; i++)
        result[i]=INF;

    result[1]=0;

    // n-1�� ���� ���� ����Ŭ Ȯ��
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(result[j]!=INF){
                for(int k=0; k<vec[j].size(); k++){
                    int node=vec[j][k].first;
                    int cost=vec[j][k].second;

                    if(result[node] > result[j]+cost){
                        if(i==n){
                            checkCycle=true;
                            break;
                        }
                        else
                            result[node]=result[j]+cost;
                    }
                }
            }
        }
    }

    if(checkCycle)
        printf("-1\n");
    else{
        for(int i=2; i<=n; i++)
            printf("%d\n", result[i]==INF ? -1 : result[i]);
    }

    return 0;
}
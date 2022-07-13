#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int visitOrder[MAX]; // �湮 ���� �迭 / �̹湮 : 0, �湮 ���� ����
int cutVertex[MAX]; // �� ������ ������ ���� ����
int answer[MAX], ans; // ����� ������ ����, ����
int order; // �湮 ����
vector<int> AL[MAX];

int dfs(int curr, int parent){
    visitOrder[curr] = ++order; // �湮 order ����

    // �� �θ𿡰� �Ѱ��� low (���� ���� return ��) �����ϴ� ����
    // ���� ����� ���� �湮���� ��, �湮�� ���� ���� �湮�ߴ� ���� �� order�� ���� ���� ��
    int minOrder=visitOrder[curr];

    // child�� ���� ����
    int child = 0; 

    // ���� �湮 ������ �� Ž�� - ���� ������ ���� ����Ʈ
    for(int next : AL[curr]){
        if(next == parent) continue; // �������� �θ� ����� ��� pass

        // next�� ��湮�� ���� ���
        if(visitOrder[next] > 0){
            // DST�� �������� ���� �̷��� ������ curr�� ������ ��� �ܿ� ������ �� X
            // �ٽ� ����, next ���� ���� dfs �۾��� ���� ���°� �ƴϹǷ�,
            // next ��忡���� ������ order ���� visitOrder[next]�� ����
            minOrder = visitOrder[next] < minOrder ? visitOrder[next] : minOrder;
        }

        // next�� �̹湮 ������ ���
        else{
            child++;
            int low = dfs(next, curr);

            if(parent && visitOrder[curr] <= low) cutVertex[curr] = 1;

            minOrder = low < minOrder ? low : minOrder;
        }
    }

    if(!parent && child>=2) cutVertex[curr]=1;

    return minOrder;
}

int main(){
    int v, e, a, b;
    scanf("%d %d", &v, &e);

    for(int i=0; i<e; i++){
        scanf("%d %d", &a, &b);
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    // ���� �׷����� �ƴϹǷ� ��� ������ Ž������ ���� �� ����
    for(int i=1; i<=v; i++){
        // �̹湮�� ���
        if(visitOrder[i]==0) dfs(i, 0);
    }

    // ������ ���� ���
    for(int i=1; i<=v; i++)
        if(cutVertex[i]) answer[ans++]=i;

    printf("%d\n", ans);
    
    for(int i=0; i<ans; i++)
        printf("%d ", answer[i]);

    return 0;
}
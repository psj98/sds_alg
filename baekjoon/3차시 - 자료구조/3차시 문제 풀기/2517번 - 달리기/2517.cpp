#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<int> v; // ����
ll person[500001]; // ���� �ɷ�ġ

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> person[i];
        v.push_back(person[i]);
    }

    sort(v.begin(), v.end()); // �������� ����

    for(int i=0; i<n; i++){
        int a=lower_bound(v.begin(), v.end(), person[i]) - v.begin();
    }

    return 0;
}
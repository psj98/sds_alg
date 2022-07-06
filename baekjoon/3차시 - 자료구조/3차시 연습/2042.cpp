// �ε��� Ʈ��
#include <iostream>
#include <queue>

typedef long long ll;
using namespace std;

ll tree[1024 * 1024 * 2 + 1];

int main(){
    int n, m, k, s = 1;
    scanf("%d %d %d", &n, &m, &k);

    // ���� �ϴ��� �ε��� ���� ���
    while(s < n)
        s *= 2;

    for(int i = 0; i < n; i++)
        scanf("%lld", &tree[s + i]);

    // bottom-up �������� �� ���ؼ� ����
    for(int i = s - 1; i > 0; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    for(int i = 0; i < m + k; i++){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        // �� ����
        if(a == 1){
            tree[s + b - 1] = c;
            ll idx = (s + b - 1) / 2;

            // bottom-up �������� ����� �κп� ���� ������ �޴� ���� ����
            while(idx > 0){
                tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
                idx /= 2;
            }
        }

        // ���� ��
        else{
            ll sum = 0;
            ll l = b + s - 1, r = c + s - 1;

            // �� ������
            while(l <= r){
                if(l % 2 == 1)
                    sum += tree[l];
                if(r % 2 == 0)
                    sum += tree[r];

                l = (l + 1) / 2;
                r = (r - 1) / 2;
            }

            printf("%lld\n", sum);
        }
    }

    return 0;
}